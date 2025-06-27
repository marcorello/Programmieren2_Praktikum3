#include "booking.h"

double Booking::getPrice() const
{
    return price;
}

void Booking::setPrice(double newPrice)
{
    price = newPrice;
}

std::string Booking::getFromDate() const
{
    return fromDate;
}

void Booking::setFromDate(const std::string &newFromDate)
{
    fromDate = newFromDate;
}

std::string Booking::getToDate() const
{
    return toDate;
}

void Booking::setToDate(const std::string &newToDate)
{
    toDate = newToDate;
}

long Booking::getTravelId() const
{
    return travelId;
}

void Booking::setTravelId(long newTravelId)
{
    travelId = newTravelId;
}

Booking::~Booking()
{

}

Booking::Booking()
{

}

Booking::Booking(std::string ID, double PRICE, std::string FROMDATE, std::string TODATE) : id(ID), price(PRICE), fromDate(FROMDATE), toDate(TODATE)
{

}

Booking::Booking(std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE): id(ID), price(PRICE), travelId(TRAVELID), fromDate(FROMDATE), toDate(TODATE)
{

}

Customer *Booking::getCustomer() const
{
    return customer;
}

void Booking::setCustomer(Customer *newCustomer)
{
    customer = newCustomer;
}

std::string Booking::getId() const
{
    return id;
}

void Booking::setId(const std::string &newId)
{
    id = newId;
}
