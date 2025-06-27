/********************************************************************************
** Form generated from reading UI file 'travelagencyui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELAGENCYUI_H
#define UI_TRAVELAGENCYUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TravelAgencyUI
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *bookingList;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TravelAgencyUI)
    {
        if (TravelAgencyUI->objectName().isEmpty())
            TravelAgencyUI->setObjectName("TravelAgencyUI");
        TravelAgencyUI->resize(565, 600);
        centralwidget = new QWidget(TravelAgencyUI);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        bookingList = new QListWidget(centralwidget);
        bookingList->setObjectName("bookingList");

        verticalLayout->addWidget(bookingList);

        TravelAgencyUI->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TravelAgencyUI);
        statusbar->setObjectName("statusbar");
        TravelAgencyUI->setStatusBar(statusbar);
        menuBar = new QMenuBar(TravelAgencyUI);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 565, 17));
        TravelAgencyUI->setMenuBar(menuBar);
        toolBar = new QToolBar(TravelAgencyUI);
        toolBar->setObjectName("toolBar");
        TravelAgencyUI->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        retranslateUi(TravelAgencyUI);

        QMetaObject::connectSlotsByName(TravelAgencyUI);
    } // setupUi

    void retranslateUi(QMainWindow *TravelAgencyUI)
    {
        TravelAgencyUI->setWindowTitle(QCoreApplication::translate("TravelAgencyUI", "TravelAgencyUI", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("TravelAgencyUI", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TravelAgencyUI: public Ui_TravelAgencyUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELAGENCYUI_H
