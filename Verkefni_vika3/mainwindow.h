#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <person.h>
#include <domainlayer.h>
#include <displayform.h>
#include <connectionsmenu.h>
#include <personmenu.h>
#include <string>
#include <vector>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    /*void on_pushButtonSortPersonByID_clicked();

    void on_pushButtonSortPersonByName_clicked();

    void on_pushButtonSortPersonByAge_clicked();*/

    void on_commandLinkButtonPerson_clicked();

    void on_commandLinkButtonComputer_clicked();

    void on_commandLinkButtonConnections_clicked();

    void on_Button_Close_clicked();



private:
    Ui::MainWindow *ui;
    PersonMenu personmenu;
    ConnectionsMenu connectionmenu;

};

#endif // MAINWINDOW_H
