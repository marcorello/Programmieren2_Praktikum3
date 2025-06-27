#include "travelagency.h"
#include "trainticket.h"
#include "rentalcarreservation.h"
#include "hotelbooking.h"
#include "flightbooking.h"
#include "booking.h"
#include "customer.h"
#include "travel.h"
#include <iostream>
#include <QJsonArray>
#include "json.hpp"

using json = nlohmann::json;

// Methode zum Einlesen von Buchungen
std::vector<Customer *> TravelAgency::getCustomers() const
{
    return allCustomers;
}

void TravelAgency::setCustomers(const std::vector<Customer *> &newCustomers)
{
    allCustomers = newCustomers;
}

std::vector<Travel *> TravelAgency::getTravels() const
{
    return allTravels;
}

void TravelAgency::setTravels(const std::vector<Travel *> &newTravels)
{
    allTravels = newTravels;
}

QString TravelAgency::getStatistics() const
{
    return statistics;
}

void TravelAgency::readFile(QWidget* parent)
{

    QFile file(filepath);

    // Datei im Lesemodus öffnen
    if (!file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error("Datei konnte nicht geöffnet werden!");
    }

    QByteArray fileData = file.readAll();
    file.close();

    // Json Daten parsen
    json f = json::parse(fileData.toStdString());

    // Zuerst Travel- und Customer-Objekte erstellen, bevor Buchungen verarbeitet werden
    for (const auto& item : f)
    {
        long customerId = item.at("customerId").get<long>();
        long travelId = item.at("travelId").get<long>();
        std::string firstName = item.at("customerFirstname").get<std::string>();
        std::string lastName = item.at("customerLastname").get<std::string>();

        // Customer erstellen, falls noch nicht vorhanden
        if (customerMap.find(customerId) == customerMap.end())
        {
            Customer* customer = new Customer(customerId, firstName, lastName);
            customerMap[customerId] = customer;
            allCustomers.push_back(customer);
        }

        // Travel erstellen, falls noch nicht vorhanden
        if (travelMap.find(travelId) == travelMap.end())
        {
            Travel* travel = new Travel(travelId, customerId);
            travelMap[travelId] = travel;
            allTravels.push_back(travel);
        }
    }

    int counterFlug {0}, counterZug {0}, counterCar {0}, counterHotel {0};
    double preisFlug {0.0}, preisZug {0.0}, preisCar {0.0}, preisHotel {0.0};

    std::string zeile;

    // Iteration über alle Objekte im json array
    for (size_t i = 0; i < f.size(); i++)
    {
        try {
            json item = f[i]; // Greift auf das aktuelle Projekt zu

            if(!item.contains("id") || !item.contains("price") || !item.contains("fromDate") ||
                !item.contains("toDate") || !item.contains("customerId") ||
                !item.contains("travelId") ||!item.contains("type"))
            {
                throw std::invalid_argument("Fehlende Basisfelder in der Buchung!");
            }

            // Allgemeine Attribute holen
            std::string id = item.at("id").get<std::string>();
            double price = item.at("price").get<double>();
            std::string fromDate = item.at("fromDate").get<std::string>();
            std::string toDate = item.at("toDate").get<std::string>();
            long customerId = item.at("customerId").get<long>();
            long travelId = item.at("travelId").get<long>();
            std::string type = item.at("type").get<std::string>();

            // Booking Objekt
            Booking *booking = nullptr;

            std::cout << "Type: " << type << std::endl;

            if (type == "RentalCar")
            {
                if (!item.contains("pickupLocation") || !item.contains("returnLocation") ||
                    !item.contains("vehicleClass") || !item.contains("company"))
                {
                    throw std::invalid_argument("Fehlendes Attribut in 'RentalCar'!");
                }

                booking = new RentalCarReservation(item.at("pickupLocation").get<std::string>(),
                                                   item.at("returnLocation").get<std::string>(),
                                                   item.at("company").get<std::string>(),
                                                   item.at("vehicleClass").get<std::string>(),
                                                   id, price, travelId, fromDate, toDate);

                bookings.push_back(booking);
                assignBooking(booking, travelId, customerId);
                std::cout << booking->showDetails() << std::endl;
                counterCar++;
                preisCar += price;
            }

            else if (type == "Hotel")
            {
                if (!item.contains("hotel") || !item.contains("town") || !item.contains("roomType"))
                {
                    throw std::invalid_argument("Fehlendes Attribut in 'Hotel'!");
                }

                booking = new HotelBooking(item.at("hotel").get<std::string>(),
                                           item.at("town").get<std::string>(),
                                           item.at("roomType").get<std::string>(),
                                           id, price, travelId, fromDate, toDate);

                bookings.push_back(booking);
                assignBooking(booking, travelId, customerId);
                std::cout << booking->showDetails() << std::endl;
                counterHotel++;
                preisHotel += price;
            }

            else if (type == "Flight")
            {
                if (!item.contains("fromDest") || !item.contains("toDest") || !item.contains("airline") ||
                    !item.contains("bookingClass"))
                {
                    throw std::invalid_argument("Fehlendes Attribut in 'Flight'!");
                }

                if(item.value("fromDest", "").length() > 3 )
                {
                    throw std::length_error("Der string für die Flughafenkürzel ist zu lang (>3). Zeile: ");
                }

                booking = new FlightBooking(item.at("fromDest").get<std::string>(),
                                            item.at("toDest").get<std::string>(),
                                            item.at("airline").get<std::string>(),
                                            item.at("bookingClass").get<std::string>(),
                                            id, price, travelId, fromDate, toDate);

                bookings.push_back(booking);
                assignBooking(booking, travelId, customerId);
                std::cout << booking->showDetails() << std::endl;
                counterFlug++;
                preisFlug += price;
            }

            else if (type == "Train")
            {
                if (!item.contains("fromStation") || !item.contains("toStation") || !item.contains("connectingStations") ||
                    !item.contains("departureTime") || !item.contains("arrivalTime") || !item.contains("ticketType"))
                {
                    throw std::invalid_argument("Fehlendes Attribut in Train!");
                }

                booking = new TrainTicket(item.at("fromStation").get<std::string>(),
                                          item.at("toStation").get<std::string>(),
                                          item["connectingStations"],   // Übergibt das json Array direkt
                                          item.at("departureTime").get<std::string>(),
                                          item.at("arrivalTime").get<std::string>(),
                                          item.at("ticketType").get<std::string>(),
                                          id, price, travelId, fromDate, toDate);

                bookings.push_back(booking);
                assignBooking(booking, travelId, customerId);
                std::cout << booking->showDetails() << std::endl;
                counterZug++;
                preisZug += price;
            }

            else
            {
                throw std::invalid_argument("Unbekannter Buchungstyp: " + type);
            }
        }
        catch(const std::exception &e)
        {
            QMessageBox::warning(parent, "Fehler", QString("Fehler beim parsen eines Elements: ") + e.what());
            break;
        }
    }

    int reisenVonKunde1{};
    if (customerMap.find(1) != customerMap.end())
    {
        reisenVonKunde1 = customerMap[1]->getTravelList().size();
    }

    int buchungenZuReise17{};
    if (travelMap.find(17) != travelMap.end())
    {
        buchungenZuReise17 = travelMap[17]->getTravelBookings().size();
    }

    int travelNumber = allTravels.size();
    int customerNumber = allCustomers.size();

    statistics = "Es wurden " + QString::number(counterFlug) + " Flugbuchungen im Wert von " +
                      QString::number(preisFlug) + " Euro, " + QString::number(counterCar) + " Mietwagenbuchungen im Wert von " +
                      QString::number(preisCar) + " Euro, " + QString::number(counterHotel) + " Hotelreservierungen im Wert von " +
                      QString::number(preisHotel) + " Euro und " + QString::number(counterZug) + " Zugbuchungen im Wert von " +
                      QString::number(preisZug) + " Euro, angelegt.";

    statistics += " Es wurden " + QString::number(travelNumber) + " Reisen und " +
                  QString::number(customerNumber) + " Kunden angelegt.\n";

    statistics += "Der Kunde mit der ID 1 hat " + QString::number(reisenVonKunde1) +
                  " Reisen gebucht. Zur Reise mit der ID 17 gehören " +
                  QString::number(buchungenZuReise17) + " Buchungen.";

}

void TravelAgency::clearBookings()
{
    bookings.clear();
}

// Methode zum ertsllen der Objekte Customer und Travel
void TravelAgency::assignBooking(Booking *booking, long travelId, long customerId)
{
    // Prüfen ob Customer und Travel existieren
    if (customerMap.find(customerId) == customerMap.end() ||
        travelMap.find(travelId) == travelMap.end())
    {
        throw std::invalid_argument("Ungueltige customerId oder travelId!");
    }

    // Customer und Travel aus der Map holen
    Customer* customer = customerMap[customerId];
    Travel* travel = travelMap[travelId];

    // Kunde der Buchung zuweisen
    booking->setCustomer(customer);

    // Booking dem Travel zuweisen
    travel->addBooking(booking);

    bool alreadyAdded = false;

    // existiert die Reise?
    for (auto* t : customer->getTravelList())
    {
        if (t->getId() == travelId)
        {
            alreadyAdded = true;
            break;
        }
    }

    // Wenn nicht hinzufügen
    if (!alreadyAdded)
    {
        customer->addTravel(travel);
    }
}

Customer *TravelAgency::findCustomer(long id)
{
    for(Customer *c : allCustomers)
    {
        if(c->getId() == id)
        {
            return c;
        }
    }

    return nullptr;
}

TravelAgency::TravelAgency()
{

}

TravelAgency::TravelAgency(std::vector<Booking *> BOOKINGS) : bookings(BOOKINGS)
{

}

TravelAgency::TravelAgency(std::vector<Booking *> BOOKINGS, std::vector<Customer *> ALLCUSTOMERS, std::vector<Travel *> ALLTRAVELS): bookings(BOOKINGS), allCustomers(ALLCUSTOMERS), allTravels(ALLTRAVELS)
{

}

TravelAgency::~TravelAgency()
{
    for(auto i : bookings)
    {
        delete i;
    }

    for(auto i : allCustomers)
    {
        delete i;
    }

    for(auto i : allTravels)
    {
        delete i;
    }
}

const std::vector<Booking *> &TravelAgency::getBookings() const
{
    return bookings;
}

void TravelAgency::setBookings(const std::vector<Booking *> &newBookings)
{
    bookings = newBookings;
}

QString TravelAgency::getFilepath() const
{
    return filepath;
}

void TravelAgency::setFilepath(const QString &newfilepath)
{
    filepath = newfilepath;
}

// Methode zum schreiben der json Datei
bool TravelAgency::writeFile(const std::string &filename)
{
    QJsonArray bookingArray;

    for (Booking* b : getBookings())
    {
        QJsonObject bookingObject;

        bookingObject["id"] = QString::fromStdString(b->getId());
        bookingObject["price"] = b->getPrice();
        bookingObject["fromDate"] = QString::fromStdString(b->getFromDate());
        bookingObject["toDate"] = QString::fromStdString(b->getToDate());

        // Customer-Daten über Customer-Objekt holen
        Customer* customer = b->getCustomer();

        if (customer)
        {
            bookingObject["customerId"] = static_cast<int>(customer->getId());  // cast to int
            bookingObject["customerFirstname"] = QString::fromStdString(customer->getFirstName());
            bookingObject["customerLastname"] = QString::fromStdString(customer->getLastName());
        }
        else
        {
            bookingObject["customerId"] = -1;
            bookingObject["customerFirstname"] = "Unknown";
            bookingObject["customerLastname"] = "Unknown";
        }

        // TravelId als int speichern, falls es ein long ist
        bookingObject["travelId"] = static_cast<int>(b->getTravelId());

        // Typ-spezifische Felder
        if (auto flight = dynamic_cast<FlightBooking*>(b))
        {
            bookingObject["type"] = "Flight";
            bookingObject["airline"] = QString::fromStdString(flight->getAirline());
            bookingObject["bookingClass"] = QString::fromStdString(flight->getBookingClass());
            bookingObject["fromDest"] = QString::fromStdString(flight->getFromDestination());
            bookingObject["toDest"] = QString::fromStdString(flight->getToDestination());
        }
        else if (auto hotel = dynamic_cast<HotelBooking*>(b))
        {
            bookingObject["type"] = "Hotel";
            bookingObject["hotel"] = QString::fromStdString(hotel->getHotel());
            bookingObject["roomType"] = QString::fromStdString(hotel->getRoomType());
            bookingObject["town"] = QString::fromStdString(hotel->getTown());
        }
        else if (auto car = dynamic_cast<RentalCarReservation*>(b))
        {
            bookingObject["type"] = "RentalCar";
            bookingObject["company"] = QString::fromStdString(car->getCompany());
            bookingObject["pickupLocation"] = QString::fromStdString(car->getPickupLocation());
            bookingObject["returnLocation"] = QString::fromStdString(car->getReturnLocation());
            bookingObject["vehicleClass"] = QString::fromStdString(car->getVehicleClass());
        }
        else if (auto train = dynamic_cast<TrainTicket*>(b))
        {
            bookingObject["type"] = "Train";
            bookingObject["arrivalTime"] = QString::fromStdString(train->getArrivalTime());
            bookingObject["departureTime"] = QString::fromStdString(train->getDepatureTime());
            bookingObject["fromStation"] = QString::fromStdString(train->getFromDestination());
            bookingObject["toStation"] = QString::fromStdString(train->getToDestination());

            QJsonArray connectingStationsArray;
            for (const auto& station : train->getConnectingStations()) {
                connectingStationsArray.append(QString::fromStdString(station));
            }
            bookingObject["connectingStations"] = connectingStationsArray;
            bookingObject["ticketType"] = QString::fromStdString(train->getBookingClass());
        }
        else
        {
            bookingObject["type"] = "Unknown";
        }

        bookingArray.append(bookingObject);
    }

    QJsonDocument doc(bookingArray);

    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::WriteOnly))
    {
        return false;
    }

    file.write(doc.toJson());
    file.close();

    return true;
}
