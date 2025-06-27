#ifndef TRAINTICKET_H
#define TRAINTICKET_H
#include <string>
#include <vector>
#include "booking.h"

class TrainTicket : public Booking
{
private:

    std::string fromDestination;
    std::string toDestination;
    std::vector <std::string> connectingStations;
    std::string depatureTime;
    std::string arrivalTime;
    std::string bookingClass;

public:

    std::string showDetails() override;

    TrainTicket();
    TrainTicket(std::string FROMDESTINATION, std::string TODESTINATION, std::vector <std::string> CONNECTINGSTATIONS, std::string DEPATURETIME, std::string ARRIVALTIME, std::string ID, double PRICE, std::string FROMDATE, std::string TODATE);
    TrainTicket(std::string FROMDESTINATION, std::string TODESTINATION, std::vector <std::string> CONNECTINGSTATIONS, std::string DEPATURETIME, std::string ARRIVALTIME, std::string BOOKINGCLASS, std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE);
    ~TrainTicket();

    std::string getFromDestination() const;
    void setFromDestination(const std::string &newFromDestination);
    std::string getToDestination() const;
    void setToDestination(const std::string &newToDestination);
    std::vector<std::string> getConnectingStations() const;
    void setConnectingStations(const std::vector<std::string> &newConnectingStations);
    std::string getBookingClass() const;
    void setBookingClass(const std::string &newBookingClass);
    std::string getDepatureTime() const;
    void setDepatureTime(const std::string &newDepatureTime);
    std::string getArrivalTime() const;
    void setArrivalTime(const std::string &newArrivalTime);
};

#endif // TRAINTICKET_H
