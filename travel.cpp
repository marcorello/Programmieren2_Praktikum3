#include "travel.h"

long Travel::getId() const
{
    return id;
}

void Travel::setId(long newId)
{
    id = newId;
}

long Travel::getCustomerId() const
{
    return customerId;
}

void Travel::setCustomerId(long newCustomerId)
{
    customerId = newCustomerId;
}

std::vector<Booking *> Travel::getTravelBookings() const
{
    return travelBookings;
}

void Travel::setTravelBookings(const std::vector<Booking *> &newTravelBookings)
{
    travelBookings = newTravelBookings;
}

Travel::Travel() {}

Travel::Travel(long ID, long CUSTOMERID): id(ID), customerId(CUSTOMERID)
{

}

Travel::~Travel()
{
    for(auto i : travelBookings)
    {
        delete i;
    }
}

void Travel::addBooking(Booking *booking)
{
    travelBookings.push_back(booking);
}
