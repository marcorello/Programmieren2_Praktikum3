#ifndef BOOKING_H
#define BOOKING_H
#include <string>
#include <QJsonObject>

class Customer;

class Booking
{
private:

    std::string id;
    double price;
    long travelId;
    std::string fromDate;
    std::string toDate;

public:

    virtual std::string showDetails()=0;
    virtual ~Booking();

    Booking();
    Booking(std::string ID, double PRICE, std::string FROMDATE, std::string TODATE);
    Booking(std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE);

    Customer *customer;

    std::string getId() const;
    void setId(const std::string &newId);
    double getPrice() const;
    void setPrice(double newPrice);
    std::string getFromDate() const;
    void setFromDate(const std::string &newFromDate);
    std::string getToDate() const;
    void setToDate(const std::string &newToDate);
    long getTravelId() const;
    void setTravelId(long newTravelId);
    Customer *getCustomer() const;
    void setCustomer(Customer *newCustomer);
};

#endif // BOOKING_H
