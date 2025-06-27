#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <string>
#include "booking.h"

class FlightBooking : public Booking
{
private:

    std::string fromDestination;
    std::string toDestination;
    std::string airline;
    std::string bookingClass;

public:

    std::string showDetails() override;

    FlightBooking();
    FlightBooking(std::string FROMDESTINATION, std::string TODESTINATION, std::string AIRLINE, std::string ID, double PRICE, std::string FROMDATE, std::string TODATE);
    FlightBooking(std::string FROMDESTINATION, std::string TODESTINATION, std::string AIRLINE, std::string BOOKINGCLASS, std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE);
    ~FlightBooking();

    std::string getFromDestination() const;
    void setFromDestination(const std::string &newFromDestination);
    std::string getToDestination() const;
    void setToDestination(const std::string &newToDestination);
    std::string getAirline() const;
    void setAirline(const std::string &newAirline);
    std::string getBookingClass() const;
    void setBookingClass(const std::string &newBookingClass);
};

#endif // FLIGHTBOOKING_H
