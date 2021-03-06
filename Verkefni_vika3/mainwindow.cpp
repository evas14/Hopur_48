#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

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
    computermenu.refresh();
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

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->move(this->pos() + (event->pos() - mLastMousePosition));
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}

