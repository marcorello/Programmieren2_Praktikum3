#include "travelagencyui.h"
#include "travelagency.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TravelAgency agency;
    TravelAgencyUI w(&agency,nullptr);
    w.show();
    return a.exec();
}

