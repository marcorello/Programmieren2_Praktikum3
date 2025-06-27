/********************************************************************************
** Form generated from reading UI file 'customerdetailsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERDETAILSDIALOG_H
#define UI_CUSTOMERDETAILSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CustomerDetailsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *travelGroupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *customerId;
    QLineEdit *customerName;
    QTableWidget *travelTable;
    QGroupBox *bookingGroupBox;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *bookingId;
    QTableWidget *bookingTable;

    void setupUi(QDialog *CustomerDetailsDialog)
    {
        if (CustomerDetailsDialog->objectName().isEmpty())
            CustomerDetailsDialog->setObjectName("CustomerDetailsDialog");
        CustomerDetailsDialog->resize(343, 546);
        verticalLayout = new QVBoxLayout(CustomerDetailsDialog);
        verticalLayout->setObjectName("verticalLayout");
        travelGroupBox = new QGroupBox(CustomerDetailsDialog);
        travelGroupBox->setObjectName("travelGroupBox");
        label = new QLabel(travelGroupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(9, 24, 71, 16));
        label_2 = new QLabel(travelGroupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(9, 66, 121, 16));
        customerId = new QLineEdit(travelGroupBox);
        customerId->setObjectName("customerId");
        customerId->setGeometry(QRect(9, 40, 74, 22));
        customerName = new QLineEdit(travelGroupBox);
        customerName->setObjectName("customerName");
        customerName->setGeometry(QRect(9, 82, 121, 22));
        travelTable = new QTableWidget(travelGroupBox);
        travelTable->setObjectName("travelTable");
        travelTable->setGeometry(QRect(9, 108, 281, 121));
        bookingGroupBox = new QGroupBox(travelGroupBox);
        bookingGroupBox->setObjectName("bookingGroupBox");
        bookingGroupBox->setGeometry(QRect(0, 240, 331, 283));
        label_3 = new QLabel(bookingGroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(9, 24, 71, 16));
        label_4 = new QLabel(bookingGroupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(9, 66, 75, 16));
        bookingId = new QLineEdit(bookingGroupBox);
        bookingId->setObjectName("bookingId");
        bookingId->setGeometry(QRect(9, 40, 61, 22));
        bookingTable = new QTableWidget(bookingGroupBox);
        bookingTable->setObjectName("bookingTable");
        bookingTable->setGeometry(QRect(9, 82, 281, 192));

        verticalLayout->addWidget(travelGroupBox);


        retranslateUi(CustomerDetailsDialog);

        QMetaObject::connectSlotsByName(CustomerDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomerDetailsDialog)
    {
        CustomerDetailsDialog->setWindowTitle(QCoreApplication::translate("CustomerDetailsDialog", "Dialog", nullptr));
        travelGroupBox->setTitle(QCoreApplication::translate("CustomerDetailsDialog", "Kunde", nullptr));
        label->setText(QCoreApplication::translate("CustomerDetailsDialog", "Kunden-ID:", nullptr));
        label_2->setText(QCoreApplication::translate("CustomerDetailsDialog", "Name des Kunden:", nullptr));
        bookingGroupBox->setTitle(QCoreApplication::translate("CustomerDetailsDialog", "Reise", nullptr));
        label_3->setText(QCoreApplication::translate("CustomerDetailsDialog", "Reise-ID:", nullptr));
        label_4->setText(QCoreApplication::translate("CustomerDetailsDialog", "Buchungen:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerDetailsDialog: public Ui_CustomerDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERDETAILSDIALOG_H
