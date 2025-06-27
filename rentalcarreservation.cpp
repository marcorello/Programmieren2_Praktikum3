#include "rentalcarreservation.h"
#include <sstream>

std::string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

void RentalCarReservation::setReturnLocation(const std::string &newReturnLocation)
{
    returnLocation = newReturnLocation;
}

std::string RentalCarReservation::getCompany() const
{
    return company;
}

void RentalCarReservation::setCompany(const std::string &newCompany)
{
    company = newCompany;
}

std::string RentalCarReservation::getVehicleClass() const
{
    return vehicleClass;
}

void RentalCarReservation::setVehicleClass(const std::string &newVehicleClass)
{
    vehicleClass = newVehicleClass;
}

std::string RentalCarReservation::showDetails()
{
    std::stringstream ausgabe;

    ausgabe << "Mietwagenreservirung mit " << company << ". Abholung am: "  << Booking::getFromDate()
            << " in"  << pickupLocation << ". Rueckgabe am " << Booking::getToDate() << " in " << returnLocation
            << ". Preis: " << Booking::getPrice() << "€" << std::endl;

    return ausgabe.str();
}

RentalCarReservation::RentalCarReservation()
{

}

RentalCarReservation::RentalCarReservation(std::string PICKUPLOCATION, std::string RETURNLOCATION, std::string COMPANY, std::string ID, double PRICE, std::string FROMDATE, std::string TODATE) : Booking(ID,PRICE,FROMDATE,TODATE), pickupLocation(PICKUPLOCATION), returnLocation(RETURNLOCATION), company(COMPANY)
{

}

RentalCarReservation::RentalCarReservation(std::string PICKUPLOCATION, std::string RETURNLOCATION, std::string COMPANY, std::string VEHICLECLASS, std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE): Booking(ID,PRICE,TRAVELID,FROMDATE,TODATE), pickupLocation(PICKUPLOCATION), returnLocation(RETURNLOCATION), company(COMPANY), vehicleClass(VEHICLECLASS)
{

}

RentalCarReservation::~RentalCarReservation()
{

}

std::string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

void RentalCarReservation::setPickupLocation(const std::string &newPickupLocation)
{
    pickupLocation = newPickupLocation;
}
