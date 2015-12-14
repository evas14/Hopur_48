#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
   // connect(on_Button_close_clicked()), SIGNAL(clicked()), qApp, SLOT(quit());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandLinkButtonPerson_clicked()
{
    personmenu.Refresh();
    personmenu.show();
}

void MainWindow::on_commandLinkButtonComputer_clicked()
{
    computermenu.show();

}

void MainWindow::on_commandLinkButtonConnections_clicked()
{
     connectionsmenu.refresh();
     connectionsmenu.show();
}



void MainWindow::on_Button_Close_clicked()
{
   QMainWindow::close();
}
