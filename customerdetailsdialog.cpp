#include "customerdetailsdialog.h"
#include "ui_customerdetailsdialog.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include "trainticket.h"
#include "customer.h"
#include "travel.h"
#include "booking.h"
#include <QDate>
#include <QTableWidgetItem>
#include "bookingdetailsdialog.h"

CustomerDetailsDialog::CustomerDetailsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomerDetailsDialog)
{
    ui->setupUi(this);
    ui->bookingGroupBox->setVisible(false);   // Table mit den Reisedaten unsichtbar machen

    connect(ui->travelTable, &QTableWidget::itemDoubleClicked,
            this, &CustomerDetailsDialog::travelTableItemDoubleClicked);
    connect(ui->bookingTable, &QTableWidget::itemDoubleClicked,
            this, &CustomerDetailsDialog::bookingTableItemDoubleClicked);

}

CustomerDetailsDialog::~CustomerDetailsDialog()
{
    delete ui;
}

void CustomerDetailsDialog::setCustomer(Customer *customer)
{
    if(!customer) return;

    this->currentCustomer = customer;

    if (!customer) {
        qDebug() << "setCustomer: NULL-Kunde übergeben!";
        return;
    }

    ui->customerId->setText(QString::number(customer->getId()));
    ui->customerName->setText(QString::fromStdString(customer->getFirstName()) + " " +
                              QString::fromStdString(customer->getLastName()));

    ui->customerId->setReadOnly(true);
    ui->customerName->setReadOnly(true);

    QTableWidget *table = ui->travelTable;
    table->clear();
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Reise-ID", "Startdatum", "Enddatum"});
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QList<Booking*> bookings;

    for (Travel* travel : customer->getTravelList())
    {
        for (Booking* booking : travel->getTravelBookings())
        {
            bookings.append(booking);
        }
    }

    table->setRowCount(bookings.size());

    for (int i = 0; i < bookings.size(); ++i)
    {
        Booking* b = bookings.at(i);
        table->setItem(i, 0, new QTableWidgetItem(QString::number(b->getTravelId())));

        QDate fromDate = QDate::fromString(QString::fromStdString(b->getFromDate()), "yyyyMMdd");
        QDate toDate = QDate::fromString(QString::fromStdString(b->getToDate()), "yyyyMMdd");

        table->setItem(i, 1, new QTableWidgetItem(fromDate.toString("dd.MM.yyyy")));
        table->setItem(i, 2, new QTableWidgetItem(toDate.toString("dd.MM.yyyy")));
    }

    table->resizeColumnsToContents();
}

void CustomerDetailsDialog::loadBookingsForCurrentTravel()
{
    if (!currentTravel) return;

    ui->bookingTable->clear();
    ui->bookingTable->setColumnCount(4);
    ui->bookingTable->setHorizontalHeaderLabels({"", "Startdatum", "Enddatum", "Preis"});
    ui->bookingTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    const auto& bookings = currentTravel->getTravelBookings();
    ui->bookingTable->setRowCount(static_cast<int>(bookings.size()));

    int i = 0;
    for (Booking* booking : bookings)
    {
        if(!booking) continue;

        QTableWidgetItem* iconItem = new QTableWidgetItem;
        QString bookingType;

        if (dynamic_cast<FlightBooking*>(booking)) bookingType = "Flight";
        else if (dynamic_cast<HotelBooking*>(booking)) bookingType = "Hotel";
        else if (dynamic_cast<TrainTicket*>(booking)) bookingType = "Train";
        else if (dynamic_cast<RentalCarReservation*>(booking)) bookingType = "RentalCar";
        else bookingType = "Unknown";

        if (bookingType == "Flight") iconItem->setIcon(QIcon(":/icons/Icons/Flight.png"));
        else if (bookingType == "Hotel") iconItem->setIcon(QIcon(":/icons/Icons/Hotel.png"));
        else if (bookingType == "Train") iconItem->setIcon(QIcon(":/icons/Icons/Train.png"));
        else if (bookingType == "RentalCar") iconItem->setIcon(QIcon(":/icons/Icons/Car.png"));
        else iconItem->setText("?");

        iconItem->setData(Qt::UserRole, QVariant::fromValue<void*>(booking));
        ui->bookingTable->setItem(i, 0, iconItem);

        QString from = QDate::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd").toString("dd.MM.yyyy");
        QString to   = QDate::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd").toString("dd.MM.yyyy");
        QString price = QString::number(booking->getPrice(), 'f', 2);

        ui->bookingTable->setItem(i, 1, new QTableWidgetItem(from));
        ui->bookingTable->setItem(i, 2, new QTableWidgetItem(to));
        ui->bookingTable->setItem(i, 3, new QTableWidgetItem(price));
        ++i;
    }

    ui->bookingTable->resizeColumnsToContents();
}

void CustomerDetailsDialog::travelTableItemDoubleClicked(QTableWidgetItem *item)
{
    if (!currentCustomer || !item) return;

    int row = item->row();
    QString travelIdStr = ui->travelTable->item(row, 0)->text();

    Travel* selectedTravel = nullptr;

    for (Travel* travel : currentCustomer->getTravelList())
    {
        if (QString::number(travel->getId()) == travelIdStr)
        {
            selectedTravel = travel;
            break;
        }
    }

    if (!selectedTravel) return;

    currentTravel = selectedTravel;

    // Reise-ID anzeigen
    ui->bookingId->setText(travelIdStr);
    ui->bookingId->setReadOnly(true);

    // Tabelle vorbereiten
    ui->bookingGroupBox->setVisible(true);
    ui->bookingTable->clear();
    ui->bookingTable->setColumnCount(4);
    ui->bookingTable->setHorizontalHeaderLabels({"", "Startdatum", "Enddatum", "Preis"});
    ui->bookingTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    const auto& bookings = selectedTravel->getTravelBookings();
    ui->bookingTable->setRowCount(static_cast<int>(bookings.size()));

    int i = 0;

    for (Booking* booking : bookings)
    {
        if(!booking) continue;

        // Icon je nach Typ
        QTableWidgetItem* iconItem = new QTableWidgetItem;
        QString bookingType;

        if (dynamic_cast<FlightBooking*>(booking))
        {
            bookingType = "Flight";
        }
        else if (dynamic_cast<HotelBooking*>(booking))
        {
            bookingType = "Hotel";
        }
        else if (dynamic_cast<TrainTicket*>(booking))
        {
            bookingType = "Train";
        }
        else if (dynamic_cast<RentalCarReservation*>(booking))
        {
            bookingType = "RentalCar";
        }
        else
        {
            bookingType = "Unknown";
        }

        if (bookingType == "Flight")
        {
            iconItem->setIcon(QIcon(":/icons/Icons/Flight.png"));
        }
        else if (bookingType == "Hotel")
        {
            iconItem->setIcon(QIcon(":/icons/Icons/Hotel.png"));
        }
        else if (bookingType == "Train")
        {
            iconItem->setIcon(QIcon(":/icons/Icons/Train.png"));
        }
        else if (bookingType == "RentalCar")
        {
            iconItem->setIcon(QIcon(":/icons/Icons/Car.png"));
        }
        else
        {
            iconItem->setText("?");
        }

        QString from = QDate::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd").toString("dd.MM.yyyy");
        QString to   = QDate::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd").toString("dd.MM.yyyy");
        QString price = QString::number(booking->getPrice(), 'f', 2);

        iconItem->setData(Qt::UserRole, QVariant::fromValue<void*>(booking));  // Booking-Zeiger speichern
        ui->bookingTable->setItem(i, 0, iconItem);

        ui->bookingTable->setItem(i, 1, new QTableWidgetItem(from));
        ui->bookingTable->setItem(i, 2, new QTableWidgetItem(to));
        ui->bookingTable->setItem(i, 3, new QTableWidgetItem(price));
        ++i;
    }

    ui->bookingTable->resizeColumnsToContents();
}

void CustomerDetailsDialog::bookingTableItemDoubleClicked(QTableWidgetItem *item)
{
    if (!item) return;



    int row = item->row();
    QTableWidgetItem* iconItem = ui->bookingTable->item(row, 0);
    if (!iconItem) return;

    QVariant data = iconItem->data(Qt::UserRole);
    Booking* selected = static_cast<Booking*>(data.value<void*>());
    if (!selected) return;

    BookingDetailsDialog* details = new BookingDetailsDialog(selected, this);

    connect(details, &BookingDetailsDialog::bookingChanged, this, [this]()
            {
                loadBookingsForCurrentTravel();  // <-- Neue Buchungsdaten laden
                emit bookingChanged();           // Optional, wenn z. B. TravelAgency reagieren soll
            });

    details->loadBooking(selected);
    details->exec();
    delete details;
}
