#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "travel.h"

class Customer
{
private:
    long id;
    std::string firstName;
    std::string lastName;
    std::vector <Travel*> travelList;

public:
    Customer();
    Customer(long ID, std::string FIRSTNAME, std::string LASTNAME);
    ~Customer();
    void addTravel(Travel* travel);
    std::string getFirstName() const;
    void setFirstName(const std::string &newFirstName);
    std::string getLastName() const;
    void setLastName(const std::string &newLastName);
    std::vector<Travel *> getTravelList() const;
    void setTravelList(const std::vector<Travel *> &newTravelList);
    long getId() const;
    void setId(long newId);
};

#endif // CUSTOMER_H
