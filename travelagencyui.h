#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H
#include "qlistwidget.h"
#include <QMainWindow>
#include "travelagency.h"
#include <QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui
{
class TravelAgencyUI;
}
QT_END_NAMESPACE

class TravelAgencyUI : public QMainWindow
{
    Q_OBJECT

public:
    // Konstruktor initialisiert Fenster mit TravelAgency Instanz
    TravelAgencyUI(TravelAgency *travelAgency, QWidget *parent = nullptr);
    ~TravelAgencyUI();

private slots:
    void loadBookings();  // Buchungen aus json laden

private:
    void createMenu();  // Menüleiste erzeugen
    void createToolBar();  // Toolbar erzeugen
    void showBookings();

    // Detailansicht einer Buchung bei Doppelklick auf ListWidget
    void listItemDoubleClicked(QListWidgetItem *item);
    void searchCustomerById();
    void saveBookings();

    bool isChanged = false;

    Ui::TravelAgencyUI *ui;
    TravelAgency *travelAgency;  // Zeiger auf TravelAgency Instanz für die Buchungen
    QAction *loadAction;   // Aktion zum laden von Buchungen (für Menü und Toolbar)
    QAction *searchCustomerAction;
    QAction *saveAction;
};
#endif // TRAVELAGENCYUI_H
