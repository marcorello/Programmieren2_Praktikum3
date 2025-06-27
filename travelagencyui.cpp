#include "travelagencyui.h"
#include "ui_travelagencyui.h"
#include "bookingdetailsdialog.h"
#include "travelagency.h"
#include "customer.h"
#include "customerdetailsdialog.h"
#include "booking.h"
#include <QFileDialog>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QTableWidget>
#include <QMessageBox>
#include <QToolBar>

TravelAgencyUI::TravelAgencyUI(TravelAgency *travelAgency, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TravelAgencyUI)
    , travelAgency(travelAgency)  // Speichert den Zeiger auf die TravelAgency Instanz
{
    ui->setupUi(this);   // Setzt UI auf das aktuelle Objekt

    createMenu();
    createToolBar();
    // Verbindung des Doppelklicksignals mit dem entsprechenden Slot
    connect(ui->bookingList, &QListWidget::itemDoubleClicked, this, &TravelAgencyUI::listItemDoubleClicked);

}

TravelAgencyUI::~TravelAgencyUI()
{
    delete ui;
}

void TravelAgencyUI::loadBookings()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Datei öffnen"), "", tr("JSON-Dateien (*.json);;Binärdateien(*.bin);;Alle Dateien (*)"));

    if(file.isEmpty()) {
        QMessageBox::warning(this, tr("Fehler"), tr("Keine Datei ausgewählt!"));
        return;
    }

    travelAgency->setFilepath(file);

    while (true)
    {
        try
        {
            if (file.endsWith(".json"))
            {
                qDebug() << "JSON-Datei erkannt. Lese JSON-Datei...";
                travelAgency->readFile(this);
                showBookings();
            }
            else
            {
                throw std::invalid_argument("Unbekannter Dateityp: Nur .json zulässig!");
            }

            QMessageBox::information(this, tr("Erfolg"), travelAgency->getStatistics());
            break; // alles erfolgreich, Schleife verlassen
        }
        catch (const std::invalid_argument &ex)
        {
            QMessageBox::warning(this, tr("Warnung"), QString::fromStdString(ex.what()));

            auto reply = QMessageBox::question(this, tr("Rückfrage"), tr("Haben Sie die Datei korrigiert?"), QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes)
            {
                travelAgency->clearBookings(); // optional, falls deine Klasse das bietet
                continue; // erneut versuchen
            }
            else
            {
                QMessageBox::critical(this, tr("Fehler"), tr("Datei wurde nicht korrigiert!"));
                break;
            }
        }
        catch (const std::length_error &ex)
        {
            QMessageBox::warning(this, tr("Warnung"), QString::fromStdString(ex.what()));

            auto reply = QMessageBox::question(this, tr("Rückfrage"), tr("Haben Sie die Datei korrigiert?"), QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes)
            {
                travelAgency->clearBookings(); // ebenfalls optional
                continue;
            }
            else
            {
                QMessageBox::critical(this, tr("Fehler"), tr("Datei wurde nicht korrigiert!"));
                break;
            }
        }
        catch (const std::exception &ex)
        {
            QMessageBox::critical(this, tr("Fehler"), QString::fromStdString(ex.what()));
            break;
        }
    }
}

void TravelAgencyUI::createMenu()
{
    QMenu* fileMenu = menuBar()->addMenu(tr("&Datei"));

    loadAction = new QAction(tr("&Datei einlesen"), this);
    loadAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_0));  // Shortcut hinzufügen (Ctrl + 0)

    saveAction = new QAction(tr("&Speichern"), this);
    saveAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    saveAction->setEnabled(false);


    searchCustomerAction = new QAction(tr("Kunden suchen"), this);

    fileMenu->addAction(loadAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(searchCustomerAction);

    // Verbindet Klick auf "Datei einlesen" mit loadBookings()
    connect(loadAction, &QAction::triggered, this, &TravelAgencyUI::loadBookings);
    connect(saveAction, &QAction::triggered, this, &TravelAgencyUI::saveBookings);
    connect(searchCustomerAction, &QAction::triggered, this, &TravelAgencyUI::searchCustomerById);
}

void TravelAgencyUI::createToolBar()
{
    QToolBar* toolbar = addToolBar(tr("Hauptleiste"));
    toolbar->addAction(loadAction);
    toolbar->addAction(searchCustomerAction);
}

void TravelAgencyUI::showBookings()
{
    ui->bookingList->clear(); // Liste leeren bevor sie neu gefüllt wird

    for (Booking* b : travelAgency->getBookings())
    {
        // Neues Listenelement mit Booking Details als Text
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(b->showDetails()));

        // Speichert den Booking Zeiger in der UserRole-Datenstruktur des Items
        item->setData(Qt::UserRole, QVariant::fromValue<void*>(b));

        ui->bookingList->addItem(item);  // Item der Liste hinzufügen
    }
}

// Doppelklick auf ein Listenelement
void TravelAgencyUI::listItemDoubleClicked(QListWidgetItem *item)
{
    // Holt die im Item gespeicherten Daten
    QVariant data = item->data(Qt::UserRole);
    Booking* selected = static_cast<Booking*>(data.value<void*>());  // Typumwandlung

    // Nur wenn gültiges Booking
    if (selected)
    {
        BookingDetailsDialog* details = new BookingDetailsDialog(selected, this); // Neues Details Fenster

        // Wenn Änderung stattfindet
        connect(details, &BookingDetailsDialog::bookingChanged, this, [this]()
        {
            this->isChanged = true;
            saveAction->setEnabled(true);
        });

        details->loadBooking(selected);  // Booking Details ins Fenster laden
        details->exec();  // Zeigt Fenster modal an

        delete details;  // Speicher freigeben wenn Fenster geschlossen wird
    }
}

void TravelAgencyUI::searchCustomerById()
{
    bool ok;
    QString input = QInputDialog::getText(this, tr("Kundensuche"), tr("Kunden-ID eingeben:"), QLineEdit::Normal, "", &ok);

    if (!ok || input.isEmpty()) return;

    long customerId = input.toLong(&ok);

    if (!ok)
    {
        QMessageBox::warning(this, tr("Fehler"), tr("Ungültige ID!"));
        return;
    }

    if (!travelAgency) {
        QMessageBox::critical(this, tr("Fehler"), tr("TravelAgency-Instanz fehlt!"));
        return;
    }

    // Customer finden
    Customer *customer = travelAgency->findCustomer(customerId);

    if (!customer)
    {
        QMessageBox::warning(this, tr("Fehler"), tr("Customer-ID existiert nicht!"));
        return;
    }

    CustomerDetailsDialog* dialog = new CustomerDetailsDialog(this);
    connect(dialog, &CustomerDetailsDialog::bookingChanged, this, [this]() {
        this->isChanged = true;
        saveAction->setEnabled(true);
    });

    dialog->setCustomer(customer);
    dialog->exec();
    delete dialog;
}

void TravelAgencyUI::saveBookings()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Speichern unter"), "", tr("JSON-Dateien (*.json)"));

    if (fileName.isEmpty()) return;

    // Alle Buchungen in einer Json speichern
    bool ok = travelAgency->writeFile(fileName.toStdString());

    if (ok)
    {
        QMessageBox::information(this, tr("Erfolg"), tr("Datei erfolgreich gespeichert."));
        isChanged = false;
        saveAction->setEnabled(false);
    }
    else
    {
        QMessageBox::critical(this, tr("Fehler"), tr("Datei konnte nicht gespeichert werden."));
    }
}



