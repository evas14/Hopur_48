#include "connectionsmenu.h"
#include "ui_connectionsmenu.h"

ConnectionsMenu::ConnectionsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionsMenu)
{
    ui->setupUi(this);
    ui->tableWidgetDisplayConnections->verticalHeader()->hide();
    DomainLayer domain;
    displayConnectionsVectorInTable(domain.sortConnectionsVectorByID());

}

ConnectionsMenu::~ConnectionsMenu()
{
    delete ui;
}

void ConnectionsMenu::displayConnectionsVectorInTable(vector<Connections> connectionsVector)
{
    string personName;
    string computerName;

    ui->tableWidgetDisplayConnections ->setRowCount(connectionsVector.size());
    ui->tableWidgetDisplayConnections->clear();
    //ui->tableWidgetDisplayConnections->resizeColumnsToContents();

    QTableWidgetItem *headerColumn_1 = new QTableWidgetItem();
    headerColumn_1->setText("Person");
    ui->tableWidgetDisplayConnections->setHorizontalHeaderItem(0,headerColumn_1);

    QTableWidgetItem *headerColumn_2 = new QTableWidgetItem();
    headerColumn_2->setText("Computer");
    ui->tableWidgetDisplayConnections->setHorizontalHeaderItem(1,headerColumn_2);

    for(unsigned int i = 0; i < connectionsVector.size(); i++)
    {
        personName = connectionsVector.at(i).getPersonName();
        computerName = connectionsVector.at(i).getComputerName();

        //ui->tableWidgetDisplayConnections->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);

        QTableWidgetItem *column_1 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(personName)));
        ui->tableWidgetDisplayConnections->setItem(i, 0, column_1);

        QTableWidgetItem *column_2 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(computerName)));
        ui->tableWidgetDisplayConnections->setItem(i, 1, column_2);

    }

    ui->tableWidgetDisplayConnections->resizeColumnsToContents();

}
