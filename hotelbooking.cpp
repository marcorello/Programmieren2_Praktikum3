#include "hotelBooking.h"
#include <sstream>

std::string HotelBooking::getTown() const
{
    return town;
}

void HotelBooking::setTown(const std::string &newTown)
{
    town = newTown;
}

std::string HotelBooking::getRoomType() const
{
    return roomType;
}

void HotelBooking::setRoomType(const std::string &newRoomType)
{
    roomType = newRoomType;
}

std::string HotelBooking::showDetails()
{
    std::stringstream ausgabe;

    ausgabe << "Hotelreservierung im " << hotel << " in " << town  << " vom "  << Booking::getFromDate()
            << " bis zum "  << Booking::getToDate() << ". Preis: " << Booking::getPrice() << "€" << std::endl;

    return ausgabe.str();
}

HotelBooking::HotelBooking()
{

}

HotelBooking::HotelBooking(std::string HOTEL, std::string TOWN, std::string ID, double PRICE, std::string FROMDATE, std::string TODATE) : Booking(ID,PRICE,FROMDATE,TODATE), hotel(HOTEL), town(TOWN)
{

}

HotelBooking::HotelBooking(std::string HOTEL, std::string TOWN, std::string ROOMTYPE, std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE): Booking(ID,PRICE,TRAVELID,FROMDATE,TODATE), hotel(HOTEL), town(TOWN), roomType(ROOMTYPE)
{

}

HotelBooking::~HotelBooking()
{

}

std::string HotelBooking::getHotel() const
{
    return hotel;
}

void HotelBooking::setHotel(const std::string &newHotel)
{
    hotel = newHotel;
}
