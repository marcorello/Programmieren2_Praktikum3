#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include <string>
#include "booking.h"

class HotelBooking : public Booking
{
private:

    std::string hotel;
    std::string town;
    std::string roomType;

public:

    std::string showDetails() override;

    HotelBooking();
    HotelBooking(std::string HOTEL, std::string TOWN, std::string ID, double PRICE, std::string FROMDATE, std::string TODATE);
    HotelBooking(std::string HOTEL, std::string TOWN, std::string ROOMTYPE, std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE);
    ~HotelBooking();

    std::string getHotel() const;
    void setHotel(const std::string &newHotel);
    std::string getTown() const;
    void setTown(const std::string &newTown);
    std::string getRoomType() const;
    void setRoomType(const std::string &newRoomType);
};


#endif // HOTELBOOKING_H
