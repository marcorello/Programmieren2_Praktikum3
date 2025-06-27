/********************************************************************************
** Form generated from reading UI file 'bookingdetailsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINGDETAILSDIALOG_H
#define UI_BOOKINGDETAILSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookingDetailsDialog
{
public:
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *Zug;
    QGroupBox *ZugGroupBox;
    QLineEdit *TrainFromStation;
    QLabel *label_5;
    QDateTimeEdit *TrainDepTime;
    QLabel *label_6;
    QLineEdit *TrainToStation;
    QLabel *label_7;
    QDateTimeEdit *TrainArrTime;
    QLabel *label_8;
    QLineEdit *TrainTicketType;
    QLabel *label_9;
    QLineEdit *TrainConnectingStations;
    QLabel *label_10;
    QWidget *Flug;
    QGroupBox *FlugGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_23;
    QLineEdit *FlightFromDest;
    QLabel *label_25;
    QLineEdit *FlightToDest;
    QLabel *label_26;
    QLineEdit *FlightAirline;
    QLabel *label_27;
    QLineEdit *FlightBookingClass;
    QWidget *Hotel;
    QGroupBox *HotelGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_29;
    QLineEdit *HotelName;
    QLabel *label_31;
    QLineEdit *HotelTown;
    QLabel *label_33;
    QLineEdit *HotelRoomType;
    QWidget *Auto;
    QGroupBox *AutoGroupBox;
    QGridLayout *gridLayout_4;
    QLabel *label_35;
    QLineEdit *CarCompany;
    QLabel *label_36;
    QLineEdit *CarPickuplocation;
    QLabel *label_37;
    QLineEdit *CarReturnlocation;
    QLabel *label_39;
    QLineEdit *CarVehicleClass;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QDoubleSpinBox *price;
    QDateEdit *fromDate;
    QLineEdit *bookingId;
    QDateEdit *toDate;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BookingDetailsDialog)
    {
        if (BookingDetailsDialog->objectName().isEmpty())
            BookingDetailsDialog->setObjectName("BookingDetailsDialog");
        BookingDetailsDialog->setEnabled(true);
        BookingDetailsDialog->resize(352, 480);
        gridLayout_5 = new QGridLayout(BookingDetailsDialog);
        gridLayout_5->setObjectName("gridLayout_5");
        tabWidget = new QTabWidget(BookingDetailsDialog);
        tabWidget->setObjectName("tabWidget");
        Zug = new QWidget();
        Zug->setObjectName("Zug");
        ZugGroupBox = new QGroupBox(Zug);
        ZugGroupBox->setObjectName("ZugGroupBox");
        ZugGroupBox->setGeometry(QRect(30, 0, 291, 271));
        ZugGroupBox->setCheckable(false);
        TrainFromStation = new QLineEdit(ZugGroupBox);
        TrainFromStation->setObjectName("TrainFromStation");
        TrainFromStation->setGeometry(QRect(49, 24, 111, 22));
        label_5 = new QLabel(ZugGroupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(9, 24, 31, 16));
        TrainDepTime = new QDateTimeEdit(ZugGroupBox);
        TrainDepTime->setObjectName("TrainDepTime");
        TrainDepTime->setGeometry(QRect(49, 50, 121, 21));
        label_6 = new QLabel(ZugGroupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(9, 50, 41, 16));
        TrainToStation = new QLineEdit(ZugGroupBox);
        TrainToStation->setObjectName("TrainToStation");
        TrainToStation->setGeometry(QRect(49, 75, 111, 22));
        label_7 = new QLabel(ZugGroupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(9, 75, 31, 16));
        TrainArrTime = new QDateTimeEdit(ZugGroupBox);
        TrainArrTime->setObjectName("TrainArrTime");
        TrainArrTime->setGeometry(QRect(49, 101, 121, 21));
        label_8 = new QLabel(ZugGroupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(9, 101, 41, 16));
        TrainTicketType = new QLineEdit(ZugGroupBox);
        TrainTicketType->setObjectName("TrainTicketType");
        TrainTicketType->setGeometry(QRect(49, 126, 111, 22));
        label_9 = new QLabel(ZugGroupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(9, 126, 41, 16));
        TrainConnectingStations = new QLineEdit(ZugGroupBox);
        TrainConnectingStations->setObjectName("TrainConnectingStations");
        TrainConnectingStations->setGeometry(QRect(50, 150, 141, 61));
        label_10 = new QLabel(ZugGroupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(9, 152, 41, 16));
        tabWidget->addTab(Zug, QString());
        Flug = new QWidget();
        Flug->setObjectName("Flug");
        FlugGroupBox = new QGroupBox(Flug);
        FlugGroupBox->setObjectName("FlugGroupBox");
        FlugGroupBox->setGeometry(QRect(20, 10, 221, 201));
        FlugGroupBox->setCheckable(false);
        gridLayout_2 = new QGridLayout(FlugGroupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        label_23 = new QLabel(FlugGroupBox);
        label_23->setObjectName("label_23");

        gridLayout_2->addWidget(label_23, 0, 0, 1, 1);

        FlightFromDest = new QLineEdit(FlugGroupBox);
        FlightFromDest->setObjectName("FlightFromDest");

        gridLayout_2->addWidget(FlightFromDest, 0, 1, 1, 1);

        label_25 = new QLabel(FlugGroupBox);
        label_25->setObjectName("label_25");

        gridLayout_2->addWidget(label_25, 1, 0, 1, 1);

        FlightToDest = new QLineEdit(FlugGroupBox);
        FlightToDest->setObjectName("FlightToDest");

        gridLayout_2->addWidget(FlightToDest, 1, 1, 1, 1);

        label_26 = new QLabel(FlugGroupBox);
        label_26->setObjectName("label_26");

        gridLayout_2->addWidget(label_26, 2, 0, 1, 1);

        FlightAirline = new QLineEdit(FlugGroupBox);
        FlightAirline->setObjectName("FlightAirline");

        gridLayout_2->addWidget(FlightAirline, 2, 1, 1, 1);

        label_27 = new QLabel(FlugGroupBox);
        label_27->setObjectName("label_27");

        gridLayout_2->addWidget(label_27, 3, 0, 1, 1);

        FlightBookingClass = new QLineEdit(FlugGroupBox);
        FlightBookingClass->setObjectName("FlightBookingClass");

        gridLayout_2->addWidget(FlightBookingClass, 3, 1, 1, 1);

        tabWidget->addTab(Flug, QString());
        Hotel = new QWidget();
        Hotel->setObjectName("Hotel");
        HotelGroupBox = new QGroupBox(Hotel);
        HotelGroupBox->setObjectName("HotelGroupBox");
        HotelGroupBox->setGeometry(QRect(40, 20, 231, 181));
        HotelGroupBox->setCheckable(false);
        gridLayout_3 = new QGridLayout(HotelGroupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        label_29 = new QLabel(HotelGroupBox);
        label_29->setObjectName("label_29");

        gridLayout_3->addWidget(label_29, 0, 0, 1, 1);

        HotelName = new QLineEdit(HotelGroupBox);
        HotelName->setObjectName("HotelName");

        gridLayout_3->addWidget(HotelName, 0, 1, 1, 1);

        label_31 = new QLabel(HotelGroupBox);
        label_31->setObjectName("label_31");

        gridLayout_3->addWidget(label_31, 1, 0, 1, 1);

        HotelTown = new QLineEdit(HotelGroupBox);
        HotelTown->setObjectName("HotelTown");

        gridLayout_3->addWidget(HotelTown, 1, 1, 1, 1);

        label_33 = new QLabel(HotelGroupBox);
        label_33->setObjectName("label_33");

        gridLayout_3->addWidget(label_33, 2, 0, 1, 1);

        HotelRoomType = new QLineEdit(HotelGroupBox);
        HotelRoomType->setObjectName("HotelRoomType");

        gridLayout_3->addWidget(HotelRoomType, 2, 1, 1, 1);

        tabWidget->addTab(Hotel, QString());
        Auto = new QWidget();
        Auto->setObjectName("Auto");
        AutoGroupBox = new QGroupBox(Auto);
        AutoGroupBox->setObjectName("AutoGroupBox");
        AutoGroupBox->setGeometry(QRect(10, 10, 301, 201));
        AutoGroupBox->setCheckable(false);
        gridLayout_4 = new QGridLayout(AutoGroupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        label_35 = new QLabel(AutoGroupBox);
        label_35->setObjectName("label_35");

        gridLayout_4->addWidget(label_35, 0, 0, 1, 1);

        CarCompany = new QLineEdit(AutoGroupBox);
        CarCompany->setObjectName("CarCompany");

        gridLayout_4->addWidget(CarCompany, 0, 1, 1, 1);

        label_36 = new QLabel(AutoGroupBox);
        label_36->setObjectName("label_36");

        gridLayout_4->addWidget(label_36, 1, 0, 1, 1);

        CarPickuplocation = new QLineEdit(AutoGroupBox);
        CarPickuplocation->setObjectName("CarPickuplocation");

        gridLayout_4->addWidget(CarPickuplocation, 1, 1, 1, 1);

        label_37 = new QLabel(AutoGroupBox);
        label_37->setObjectName("label_37");

        gridLayout_4->addWidget(label_37, 2, 0, 1, 1);

        CarReturnlocation = new QLineEdit(AutoGroupBox);
        CarReturnlocation->setObjectName("CarReturnlocation");

        gridLayout_4->addWidget(CarReturnlocation, 2, 1, 1, 1);

        label_39 = new QLabel(AutoGroupBox);
        label_39->setObjectName("label_39");

        gridLayout_4->addWidget(label_39, 3, 0, 1, 1);

        CarVehicleClass = new QLineEdit(AutoGroupBox);
        CarVehicleClass->setObjectName("CarVehicleClass");

        gridLayout_4->addWidget(CarVehicleClass, 3, 1, 1, 1);

        tabWidget->addTab(Auto, QString());

        gridLayout_5->addWidget(tabWidget, 1, 0, 1, 1);

        groupBox = new QGroupBox(BookingDetailsDialog);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        price = new QDoubleSpinBox(groupBox);
        price->setObjectName("price");

        gridLayout->addWidget(price, 3, 1, 1, 1);

        fromDate = new QDateEdit(groupBox);
        fromDate->setObjectName("fromDate");

        gridLayout->addWidget(fromDate, 1, 1, 1, 1);

        bookingId = new QLineEdit(groupBox);
        bookingId->setObjectName("bookingId");
        bookingId->setReadOnly(true);

        gridLayout->addWidget(bookingId, 0, 1, 1, 1);

        toDate = new QDateEdit(groupBox);
        toDate->setObjectName("toDate");

        gridLayout->addWidget(toDate, 2, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(BookingDetailsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        gridLayout_5->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(BookingDetailsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, BookingDetailsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, BookingDetailsDialog, qOverload<>(&QDialog::reject));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(BookingDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *BookingDetailsDialog)
    {
        BookingDetailsDialog->setWindowTitle(QCoreApplication::translate("BookingDetailsDialog", "Dialog", nullptr));
        ZugGroupBox->setTitle(QCoreApplication::translate("BookingDetailsDialog", "Buchungsdetails", nullptr));
        label_5->setText(QCoreApplication::translate("BookingDetailsDialog", "von", nullptr));
        label_6->setText(QCoreApplication::translate("BookingDetailsDialog", "Abfahrt", nullptr));
        label_7->setText(QCoreApplication::translate("BookingDetailsDialog", "nach", nullptr));
        label_8->setText(QCoreApplication::translate("BookingDetailsDialog", "Ankunft", nullptr));
        label_9->setText(QCoreApplication::translate("BookingDetailsDialog", "Tickettyp", nullptr));
        label_10->setText(QCoreApplication::translate("BookingDetailsDialog", "\303\234ber", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Zug), QCoreApplication::translate("BookingDetailsDialog", "Zug", nullptr));
        FlugGroupBox->setTitle(QCoreApplication::translate("BookingDetailsDialog", "Buchungsdetails", nullptr));
        label_23->setText(QCoreApplication::translate("BookingDetailsDialog", "von", nullptr));
        label_25->setText(QCoreApplication::translate("BookingDetailsDialog", "nach", nullptr));
        label_26->setText(QCoreApplication::translate("BookingDetailsDialog", "Airline", nullptr));
        label_27->setText(QCoreApplication::translate("BookingDetailsDialog", "Tickettyp", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Flug), QCoreApplication::translate("BookingDetailsDialog", "Flug", nullptr));
        HotelGroupBox->setTitle(QCoreApplication::translate("BookingDetailsDialog", "Buchungsdetails", nullptr));
        label_29->setText(QCoreApplication::translate("BookingDetailsDialog", "Hotel", nullptr));
        label_31->setText(QCoreApplication::translate("BookingDetailsDialog", "Stadt", nullptr));
        label_33->setText(QCoreApplication::translate("BookingDetailsDialog", "Zimmer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Hotel), QCoreApplication::translate("BookingDetailsDialog", "Hotel", nullptr));
        AutoGroupBox->setTitle(QCoreApplication::translate("BookingDetailsDialog", "Buchungsdetails", nullptr));
        label_35->setText(QCoreApplication::translate("BookingDetailsDialog", "Firma", nullptr));
        label_36->setText(QCoreApplication::translate("BookingDetailsDialog", "Abholort", nullptr));
        label_37->setText(QCoreApplication::translate("BookingDetailsDialog", "R\303\274ckgabeort", nullptr));
        label_39->setText(QCoreApplication::translate("BookingDetailsDialog", "Wagentyp", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Auto), QCoreApplication::translate("BookingDetailsDialog", "Mietwagen", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BookingDetailsDialog", "Reise Details", nullptr));
        label_4->setText(QCoreApplication::translate("BookingDetailsDialog", "Preis:", nullptr));
        label->setText(QCoreApplication::translate("BookingDetailsDialog", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("BookingDetailsDialog", "Von", nullptr));
        label_3->setText(QCoreApplication::translate("BookingDetailsDialog", "Bis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookingDetailsDialog: public Ui_BookingDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINGDETAILSDIALOG_H
