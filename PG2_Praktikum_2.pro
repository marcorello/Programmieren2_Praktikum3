QT       += core gui

QT       += webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    booking.cpp \
    bookingdetailsdialog.cpp \
    customer.cpp \
    customerdetailsdialog.cpp \
    flightbooking.cpp \
    hotelbooking.cpp \
    main.cpp \
    rentalcarreservation.cpp \
    trainticket.cpp \
    travel.cpp \
    travelagency.cpp \
    travelagencyui.cpp

HEADERS += \
    booking.h \
    bookingdetailsdialog.h \
    customer.h \
    customerdetailsdialog.h \
    flightbooking.h \
    hotelbooking.h \
    json.hpp \
    rentalcarreservation.h \
    trainticket.h \
    travel.h \
    travelagency.h \
    travelagencyui.h

FORMS += \
    bookingdetailsdialog.ui \
    customerdetailsdialog.ui \
    travelagencyui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc
