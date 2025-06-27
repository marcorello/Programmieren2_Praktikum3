#ifndef CUSTOMERDETAILSDIALOG_H
#define CUSTOMERDETAILSDIALOG_H
#include <QDialog>
#include <QTableWidgetItem>
#include <QAction>

class Booking;
class Customer;
class Travel;
class TravelAgency;

namespace Ui
{
class CustomerDetailsDialog;
}

class CustomerDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDetailsDialog(QWidget *parent = nullptr);
    ~CustomerDetailsDialog();

    void setCustomer(Customer *customer);
    void loadBookingsForCurrentTravel();

private slots:
    void travelTableItemDoubleClicked(QTableWidgetItem *item);
    void bookingTableItemDoubleClicked(QTableWidgetItem *item);

signals:

    void bookingChanged();

private:
    Ui::CustomerDetailsDialog *ui;
    Customer *currentCustomer = nullptr;
    Travel *currentTravel = nullptr;
};

#endif // CUSTOMERDETAILSDIALOG_H
