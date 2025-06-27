#ifndef BOOKINGDETAILSDIALOG_H
#define BOOKINGDETAILSDIALOG_H
#include "booking.h"
#include <QDialog>

class Booking;

namespace Ui {
class BookingDetailsDialog;
}

class BookingDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookingDetailsDialog(Booking *booking, QWidget *parent = nullptr);
    ~BookingDetailsDialog();

    // Lädt die Buchungsdetails in die Dialogfelder
    void loadBooking(Booking *booking);

signals:
    void bookingChanged();

public slots:
    void fileChanged();
    void reject();
    void accept();

private:
    Ui::BookingDetailsDialog *ui;
    Booking *currentBooking;
    bool changed;
};

#endif // BOOKINGDETAILSDIALOG_H
