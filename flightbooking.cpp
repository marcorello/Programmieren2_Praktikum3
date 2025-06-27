#include "flightBooking.h"
#include <iostream>
#include <sstream>

std::string FlightBooking::getToDestination() const
{
    return toDestination;
}

void FlightBooking::setToDestination(const std::string &newToDestination)
{
    toDestination = newToDestination;
}

std::string FlightBooking::getAirline() const
{
    return airline;
}

void FlightBooking::setAirline(const std::string &newAirline)
{
    airline = newAirline;
}

std::string FlightBooking::getBookingClass() const
{
    return bookingClass;
}

void FlightBooking::setBookingClass(const std::string &newBookingClass)
{
    bookingClass = newBookingClass;
}

std::string FlightBooking::showDetails()
{
    std::stringstream ausgabe;

    ausgabe << "Flugbuchung von " << fromDestination << " nach " << toDestination << " mit " << airline
            << " am " << Booking::getFromDate() <<". Preis: " << Booking::getPrice() << "€" << std::endl;

    return ausgabe.str();
}

FlightBooking::FlightBooking()
{

}

FlightBooking::FlightBooking(std::string FROMDESTINATION, std::string TODESTINATION, std::string AIRLINE, std::string ID, double PRICE, std::string FROMDATE, std::string TODATE) : Booking(ID,PRICE,FROMDATE,TODATE), fromDestination(FROMDESTINATION), toDestination(TODESTINATION), airline(AIRLINE)
{

}

FlightBooking::FlightBooking(std::string FROMDESTINATION, std::string TODESTINATION, std::string AIRLINE, std::string BOOKINGCLASS, std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE): Booking(ID,PRICE,TRAVELID,FROMDATE,TODATE), fromDestination(FROMDESTINATION), toDestination(TODESTINATION), airline(AIRLINE), bookingClass(BOOKINGCLASS)
{

}

FlightBooking::~FlightBooking()
{

}

std::string FlightBooking::getFromDestination() const
{
    return fromDestination;
}

void FlightBooking::setFromDestination(const std::string &newFromDestination)
{
    fromDestination = newFromDestination;
}
