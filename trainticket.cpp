#include "trainTicket.h"
#include <sstream>

std::string TrainTicket::getToDestination() const
{
    return toDestination;
}

void TrainTicket::setToDestination(const std::string &newToDestination)
{
    toDestination = newToDestination;
}

std::vector<std::string> TrainTicket::getConnectingStations() const
{
    return connectingStations;
}

void TrainTicket::setConnectingStations(const std::vector<std::string> &newConnectingStations)
{
    connectingStations = newConnectingStations;
}

std::string TrainTicket::getBookingClass() const
{
    return bookingClass;
}

void TrainTicket::setBookingClass(const std::string &newBookingClass)
{
    bookingClass = newBookingClass;
}

std::string TrainTicket::getDepatureTime() const
{
    return depatureTime;
}

void TrainTicket::setDepatureTime(const std::string &newDepatureTime)
{
    depatureTime = newDepatureTime;
}

std::string TrainTicket::getArrivalTime() const
{
    return arrivalTime;
}

void TrainTicket::setArrivalTime(const std::string &newArrivalTime)
{
    arrivalTime = newArrivalTime;
}

std::string TrainTicket::showDetails()
{
    std::stringstream ausgabe;

    ausgabe << "Zugticket von " << fromDestination << " nach " << toDestination << " am "
            << Booking::getFromDate() << " von " << depatureTime << " bis " << arrivalTime
            << " ueber: " << std::endl;

    if(!connectingStations.empty())
    {
        for(auto i : connectingStations)
        {
            ausgabe << i << "-";
        }
    }else if(connectingStations.empty())
    {
        ausgabe << "Keine weiteren Stationen" << std::endl;
    }

    return ausgabe.str();
}

TrainTicket::TrainTicket()
{

}

TrainTicket::TrainTicket(std::string FROMDESTINATION, std::string TODESTINATION, std::vector<std::string> CONNECTINGSTATIONS, std::string DEPATURETIME, std::string ARRIVALTIME, std::string ID, double PRICE, std::string FROMDATE, std::string TODATE) : Booking(ID,PRICE,FROMDATE,TODATE), fromDestination(FROMDESTINATION), toDestination(TODESTINATION), connectingStations(CONNECTINGSTATIONS), depatureTime(DEPATURETIME), arrivalTime(ARRIVALTIME)
{

}

TrainTicket::TrainTicket(std::string FROMDESTINATION, std::string TODESTINATION, std::vector<std::string> CONNECTINGSTATIONS, std::string DEPATURETIME, std::string ARRIVALTIME, std::string BOOKINGCLASS, std::string ID, double PRICE, long TRAVELID, std::string FROMDATE, std::string TODATE): Booking(ID,PRICE,TRAVELID,FROMDATE,TODATE), fromDestination(FROMDESTINATION), toDestination(TODESTINATION), connectingStations(CONNECTINGSTATIONS), depatureTime(DEPATURETIME), arrivalTime(ARRIVALTIME), bookingClass(BOOKINGCLASS)
{

}

TrainTicket::~TrainTicket()
{

}

std::string TrainTicket::getFromDestination() const
{
    return fromDestination;
}

void TrainTicket::setFromDestination(const std::string &newFromDestination)
{
    fromDestination = newFromDestination;
}
