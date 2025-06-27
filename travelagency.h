#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <vector>
#include "booking.h"
#include "travel.h"
#include "customer.h"
#include <unordered_map>
#include <QFileDialog>
#include <QMessageBox>
#include <QObject>
#include <QFile>
#include <QJsonDocument>


class TravelAgency : public QObject
{
private:

    std::vector <Booking*> bookings;
    std::vector <Customer*> allCustomers;
    std::vector <Travel*> allTravels;
    QString filepath;
    QString statistics;
    std::unordered_map <int, Customer*> customerMap;
    std::unordered_map <int, Travel*> travelMap;

public:

    void readFile(QWidget *parent = nullptr);  // Methode zum Einlesen von Buchungen
    void clearBookings();
    void assignBooking(Booking *booking, long travelId, long customerId);

    bool writeFile(const std::string &filename);

    Booking *findBooking(std::string id);
    Travel *findTravel(long id);
    Customer *findCustomer(long id);

    QString getFilepath() const;
    void setFilepath(const QString &newFilepath);

    TravelAgency();
    TravelAgency(std::vector <Booking*> BOOKINGS);
    TravelAgency(std::vector <Booking*> BOOKINGS, std::vector <Customer*> ALLCUSTOMERS, std::vector <Travel*> ALLTRAVELS);
    ~TravelAgency();

    const std::vector<Booking *> &getBookings() const;
    void setBookings(const std::vector<Booking *> &newBookings);
    std::vector<Customer *> getCustomers() const;
    void setCustomers(const std::vector<Customer *> &newCustomers);
    std::vector<Travel *> getTravels() const;
    void setTravels(const std::vector<Travel *> &newTravels);
    QString getStatistics() const;
    void setStatistics(const QString &newStatistics);
};

#endif // TRAVELAGENCY_H
