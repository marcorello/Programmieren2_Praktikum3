#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include <string>
#include "booking.h"

class RentalCarReservation : public Booking
{
private:

    std::string pickupLocation;
    std::string returnLocation;
    std::string company;
    std::string vehicleClass;

public:

    std::string showDetails() override;

    RentalCarReservation();
    RentalCarReservation(std::string PICKUPLOCATION, std::string RETURNLOCATION, std::string COMPANY, std::string ID, double PRICE, std::string FROMDATE, std::string TODATE);
    RentalCarReservation(std::string PICKUPLOCATION, std::string RETURNLOCATION, std::string COMPANY, std::string VEHICLECLASS, std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE);
    ~RentalCarReservation();

    std::string getPickupLocation() const;
    void setPickupLocation(const std::string &newPickupLocation);
    std::string getReturnLocation() const;
    void setReturnLocation(const std::string &newReturnLocation);
    std::string getCompany() const;
    void setCompany(const std::string &newCompany);
    std::string getVehicleClass() const;
    void setVehicleClass(const std::string &newVehicleClass);
};

#endif // RENTALCARRESERVATION_H
