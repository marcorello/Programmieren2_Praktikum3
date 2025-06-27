#ifndef TRAVEL_H
#define TRAVEL_H
#include <vector>
#include "booking.h"

class Travel
{
private:
    long id;
    long customerId;
    std::vector <Booking*> travelBookings;

public:
    Travel();
    Travel(long ID, long CUSTOMERID);
    ~Travel();
    void addBooking(Booking* booking);
    long getId() const;
    void setId(long newId);
    long getCustomerId() const;
    void setCustomerId(long newCustomerId);
    std::vector<Booking *> getTravelBookings() const;
    void setTravelBookings(const std::vector<Booking *> &newTravelBookings);
};

#endif // TRAVEL_H
