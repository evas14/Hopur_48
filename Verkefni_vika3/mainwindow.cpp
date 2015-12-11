#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
void MainWindow::on_pushButtonSortPersonByID_clicked()
{
    ui->listBoxDisplay->clear();

    DomainLayer domain;


    if(ui->radioButtonNormalSort->isChecked())
    {
        vector<person>personVector = domain.sortPersonVectorByID("normal");
        displayPersonVector(personVector);

    }

    else
    {
        vector<person>personVector = domain.sortPersonVectorByID("reverse");
        displayPersonVector(personVector);
    }
}

void MainWindow::on_pushButtonSortPersonByName_clicked()
{
    ui->listBoxDisplay->clear();

    DomainLayer domain;


    if(ui->radioButtonNormalSort->isChecked())
    {
        vector<person>personVector = domain.sortPersonVectorByName("normal");
        displayPersonVector(personVector);

    }
    else
    {
        vector<person>personVector = domain.sortPersonVectorByName("reverse");
        displayPersonVector(personVector);

    }
}

void MainWindow::on_pushButtonSortPersonByAge_clicked()
{
    ui->listBoxDisplay->clear();

    DomainLayer domain;


    if(ui->radioButtonNormalSort->isChecked())
    {
        vector<person>personVector = domain.sortPersonVectorByAge("normal");
        displayPersonVector(personVector);
    }
    else
    {
        vector<person>personVector = domain.sortPersonVectorByAge("reverse");
        displayPersonVector(personVector);
    }
}
*/

void MainWindow::on_commandLinkButtonPerson_clicked()
{
    personmenu.show();
}
