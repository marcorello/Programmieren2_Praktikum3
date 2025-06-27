#include "bookingdetailsdialog.h"
#include "ui_bookingdetailsdialog.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include "trainticket.h"
#include <QPushButton>

BookingDetailsDialog::BookingDetailsDialog(Booking *booking, QWidget *parent)
    : QDialog(parent), ui(new Ui::BookingDetailsDialog), currentBooking(booking), changed(false)
{
    ui->setupUi(this);


    // Tabs zunächst deaktivieren
    ui->tabWidget->setTabEnabled(0, false); // Zug
    ui->tabWidget->setTabEnabled(1, false); // Flug
    ui->tabWidget->setTabEnabled(2, false); // Hotel
    ui->tabWidget->setTabEnabled(3, false); // Auto

    // Button Box zunächst deaktivieren
    ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);



    // Allgemeine Felder
    connect(ui->fromDate, &QDateEdit::dateChanged, this, &BookingDetailsDialog::fileChanged);
    connect(ui->toDate, &QDateEdit::dateChanged, this, &BookingDetailsDialog::fileChanged);
    connect(ui->price, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &BookingDetailsDialog::fileChanged);

    // Zug
    connect(ui->TrainFromStation, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged);
    connect(ui->TrainToStation, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged);
    connect(ui->TrainDepTime, &QDateTimeEdit::dateTimeChanged, this, &BookingDetailsDialog::fileChanged);
    connect(ui->TrainArrTime, &QDateTimeEdit::dateTimeChanged, this, &BookingDetailsDialog::fileChanged);
    connect(ui->TrainTicketType, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged);
    connect(ui->TrainConnectingStations, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged);

    // Flug
    connect(ui->FlightFromDest, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged);
    connect(ui->FlightToDest, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // ToDestination
    connect(ui->FlightAirline, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // Airline
    connect(ui->FlightBookingClass, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // Buchungsklasse

    // Hotel
    connect(ui->HotelName, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // Hotelname
    connect(ui->HotelTown, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // Stadt
    connect(ui->HotelRoomType, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // Zimmertyp

    // Auto
    connect(ui->CarCompany, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // Firma
    connect(ui->CarPickuplocation, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // Abholort
    connect(ui->CarReturnlocation, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // Rückgabeort
    connect(ui->CarVehicleClass, &QLineEdit::textChanged, this, &BookingDetailsDialog::fileChanged); // Fahrzeugklasse

    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &BookingDetailsDialog::reject);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &BookingDetailsDialog::accept);

}

BookingDetailsDialog::~BookingDetailsDialog()
{
    delete ui;
}

void BookingDetailsDialog::loadBooking(Booking *booking)
{
    ui->bookingId->setText(QString::fromStdString(booking->getId()));

    QString fromStr = QString::fromStdString(booking->getFromDate());
    QString toStr = QString::fromStdString(booking->getToDate());

    QDate fromDate = QDate::fromString(fromStr, "yyyyMMdd");
    QDate toDate = QDate::fromString(toStr, "yyyyMMdd");

    if (!fromDate.isValid()) fromDate = QDate::currentDate();
    if (!toDate.isValid()) toDate = QDate::currentDate();

    ui->fromDate->setDate(fromDate);
    ui->toDate->setDate(toDate);

    ui->price->setMaximum(10000.0);
    ui->price->setValue(static_cast<double>(booking->getPrice()));

    // Prüfe den Typ dynamisch
    if (auto *train = dynamic_cast<TrainTicket *>(booking))
    {
        ui->tabWidget->setCurrentIndex(0);
        ui->tabWidget->setTabEnabled(0, true);

        ui->TrainFromStation->setText(QString::fromStdString(train->getFromDestination()));
        ui->TrainToStation->setText(QString::fromStdString(train->getToDestination()));
        ui->TrainDepTime->setDateTime(QDateTime::fromString(QString::fromStdString(train->getDepatureTime()), Qt::ISODate));
        ui->TrainArrTime->setDateTime(QDateTime::fromString(QString::fromStdString(train->getArrivalTime()), Qt::ISODate));

        // Kürzel für Züge mappen
        static const QMap<QString, QString> trainTypes
        {
            {"SSP1", "Supersparpreis 1. Klasse"},
            {"SSP2", "Supersparpreis 2. Klasse"},
            {"SP1",  "Sparpreis 1. Klasse"},
            {"SP2",  "Sparpreis 2. Klasse"},
            {"FP1",  "Flexpreis 1. Klasse"},
            {"FP2",  "Flexpreis 2. Klasse"}
        };

        QString bookingClass = QString::fromStdString(train->getBookingClass());
        ui->TrainTicketType->setText(trainTypes.value(bookingClass, bookingClass)); // Fallback: Kürzel, wenn nicht gefunden

        QStringList stations;

        for (const std::string &s : train->getConnectingStations())
        {
            stations << QString::fromStdString(s);
        }

        ui->TrainConnectingStations->setText(stations.join(", "));
    }
    else if (auto *flight = dynamic_cast<FlightBooking *>(booking))
    {
        ui->tabWidget->setCurrentIndex(1);
        ui->tabWidget->setTabEnabled(1, true);

        ui->FlightFromDest->setText(QString::fromStdString(flight->getFromDestination()));
        ui->FlightToDest->setText(QString::fromStdString(flight->getToDestination()));
        ui->FlightAirline->setText(QString::fromStdString(flight->getAirline()));

        static const QMap<QString, QString> flightClasses
        {
            {"Y", "Economy"},
            {"W", "Premium Economy"},
            {"J", "Business"},
            {"F", "First"}
        };

        QString bookingClass = QString::fromStdString(flight->getBookingClass());

        ui->FlightBookingClass->setText(flightClasses.value(bookingClass, bookingClass));
    }
    else if (auto *hotel = dynamic_cast<HotelBooking *>(booking))
    {
        ui->tabWidget->setCurrentIndex(2);
        ui->tabWidget->setTabEnabled(2, true);

        ui->HotelName->setText(QString::fromStdString(hotel->getHotel()));
        ui->HotelTown->setText(QString::fromStdString(hotel->getTown()));

        static const QMap<QString, QString> hotelRooms
        {
            {"EZ", "Einzelzimmer"},
            {"DZ", "Doppelzimmer"},
            {"SU", "Suite"},
            {"AP", "Appartment"}
        };

        QString roomType = QString::fromStdString(hotel->getRoomType());

        ui->HotelRoomType->setText(hotelRooms.value(roomType, roomType));
    }
    else if (auto *car = dynamic_cast<RentalCarReservation *>(booking))
    {
        ui->tabWidget->setCurrentIndex(3);
        ui->tabWidget->setTabEnabled(3, true);

        ui->CarCompany->setText(QString::fromStdString(car->getCompany()));
        ui->CarPickuplocation->setText(QString::fromStdString(car->getPickupLocation()));
        ui->CarReturnlocation->setText(QString::fromStdString(car->getReturnLocation()));
        ui->CarVehicleClass->setText(QString::fromStdString(car->getVehicleClass()));
    }
}

void BookingDetailsDialog::fileChanged()
{
    if (!changed)
    {
        changed = true;
        ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(true);
        ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(true);
    }
}

void BookingDetailsDialog::reject()
{
    changed = false;
    ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);
    QDialog::reject();
}

void BookingDetailsDialog::accept()
{
    if (!currentBooking || !changed) return;

    // Allgemeine Felder
    currentBooking->setFromDate(ui->fromDate->date().toString("yyyyMMdd").toStdString());
    currentBooking->setToDate(ui->toDate->date().toString("yyyyMMdd").toStdString());
    currentBooking->setPrice(ui->price->value());

    // Signal dass eine Änderung stattgefunden hat
    emit bookingChanged();

    // Typ-spezifische Felder
    if (auto *train = dynamic_cast<TrainTicket *>(currentBooking))
    {
        train->setFromDestination(ui->TrainFromStation->text().toStdString());
        train->setToDestination(ui->TrainToStation->text().toStdString());
        train->setDepatureTime(ui->TrainDepTime->dateTime().toString(Qt::ISODate).toStdString());
        train->setArrivalTime(ui->TrainArrTime->dateTime().toString(Qt::ISODate).toStdString());
        train->setBookingClass(ui->TrainTicketType->text().toStdString());

        QStringList stationList = ui->TrainConnectingStations->text().split(",", Qt::SkipEmptyParts);
        std::vector<std::string> stations;

        for (const QString &station : stationList)
        {
            stations.push_back(station.trimmed().toStdString());
        }

        train->setConnectingStations(stations);

    }
    else if (auto *flight = dynamic_cast<FlightBooking *>(currentBooking))
    {
        flight->setFromDestination(ui->FlightFromDest->text().toStdString());
        flight->setToDestination(ui->FlightToDest->text().toStdString());
        flight->setAirline(ui->FlightAirline->text().toStdString());
        flight->setBookingClass(ui->FlightBookingClass->text().toStdString());

    }
    else if (auto *hotel = dynamic_cast<HotelBooking *>(currentBooking))
    {
        hotel->setHotel(ui->HotelName->text().toStdString());
        hotel->setTown(ui->HotelTown->text().toStdString());
        hotel->setRoomType(ui->HotelRoomType->text().toStdString());

    }
    else if (auto *car = dynamic_cast<RentalCarReservation *>(currentBooking))
    {
        car->setCompany(ui->CarCompany->text().toStdString());
        car->setPickupLocation(ui->CarPickuplocation->text().toStdString());
        car->setReturnLocation(ui->CarReturnlocation->text().toStdString());
        car->setVehicleClass(ui->CarVehicleClass->text().toStdString());
    }

    changed = false;
    ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setEnabled(false);

    QDialog::accept(); // Fenster schließen
}

