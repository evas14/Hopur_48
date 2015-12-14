#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <person.h>
#include <domainlayer.h>
#include <displayform.h>
#include <connectionsmenu.h>
#include <computermenu.h>
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
    int counter = 0;


private slots:

    void on_commandLinkButtonPerson_clicked();

    void on_commandLinkButtonComputer_clicked();

    void on_commandLinkButtonConnections_clicked();

    void on_Button_Close_clicked();



private:
    Ui::MainWindow *ui;
    PersonMenu personmenu;
    ComputerMenu computermenu;
    ConnectionsMenu connectionsmenu;


};

#endif // MAINWINDOW_H
