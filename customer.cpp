#include "customer.h"

std::string Customer::getFirstName() const
{
    return firstName;
}

void Customer::setFirstName(const std::string &newFirstName)
{
    firstName = newFirstName;
}

std::string Customer::getLastName() const
{
    return lastName;
}

void Customer::setLastName(const std::string &newLastName)
{
    lastName = newLastName;
}

std::vector<Travel *> Customer::getTravelList() const
{
    return travelList;
}

void Customer::setTravelList(const std::vector<Travel *> &newTravelList)
{
    travelList = newTravelList;
}

long Customer::getId() const
{
    return id;
}

void Customer::setId(long newId)
{
    id = newId;
}

Customer::Customer() {}

Customer::Customer(long ID, std::string FIRSTNAME, std::string LASTNAME): id(ID), firstName(FIRSTNAME), lastName(LASTNAME)
{

}

Customer::~Customer()
{
    for(auto i : travelList)
    {
        delete i;
    }
}

void Customer::addTravel(Travel *travel)
{
    travelList.push_back(travel);
}
