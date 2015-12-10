#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <person.h>
#include <domainlayer.h>
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
    void displayPersonVector(vector <person> perVec);


private slots:
    void on_pushButtonSortPersonByID_clicked();

    void on_pushButtonSortPersonByName_clicked();

    void on_pushButtonSortPersonByAge_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
