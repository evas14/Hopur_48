#include "connectionsmenu.h"
#include "ui_connectionsmenu.h"

ConnectionsMenu::ConnectionsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionsMenu)
{
    ui->setupUi(this);


}

ConnectionsMenu::~ConnectionsMenu()
{
    delete ui;
}

void ConnectionsMenu::displayConnectionsVectorInTable(vector<Connections> connectionsVector)
{
    string personName;
    string computerName;
    int Id = 0;

    ui->tableWidgetDisplayConnections->setRowCount(connectionsVector.size());
    ui->tableWidgetDisplayConnections->clear();


    QTableWidgetItem *headerColumn_1 = new QTableWidgetItem();
    headerColumn_1->setText("ID");
    ui->tableWidgetDisplayConnections->setHorizontalHeaderItem(0,headerColumn_1);

    QTableWidgetItem *headerColumn_2 = new QTableWidgetItem();
    headerColumn_2->setText("Person");
    ui->tableWidgetDisplayConnections->setHorizontalHeaderItem(1,headerColumn_2);

    QTableWidgetItem *headerColumn_3 = new QTableWidgetItem();
    headerColumn_3->setText("Computer");
    ui->tableWidgetDisplayConnections->setHorizontalHeaderItem(2,headerColumn_3);


    for(unsigned int i = 0; i < connectionsVector.size(); i++)
    {
        personName = connectionsVector.at(i).getPersonName();
        computerName = connectionsVector.at(i).getComputerName();
        Id = connectionsVector.at(i).getID();

        stringstream id;
        id << Id;
        string strID = id.str();

        QTableWidgetItem *column_1 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(strID)));
        ui->tableWidgetDisplayConnections->setItem(i, 0, column_1);

        QTableWidgetItem *column_2 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(personName)));
        ui->tableWidgetDisplayConnections->setItem(i, 1, column_2);

        QTableWidgetItem *column_3 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(computerName)));
        ui->tableWidgetDisplayConnections->setItem(i, 2, column_3);



    }

    ui->tableWidgetDisplayConnections->resizeColumnsToContents();

}

void ConnectionsMenu::refresh()
{
    ui->tableWidgetDisplayConnections->verticalHeader()->hide();
    DomainLayer domain;
    displayConnectionsVectorInTable(domain.sortConnectionsVectorByID());
    fillComboBoxConnectionID();
}


void ConnectionsMenu::fillComboBoxConnectionID()
{
    DomainLayer domain;
    vector <Connections> connectionVector = domain.sortConnectionsVectorByID();
    int ID = 0;

    ui->comboBoxConnectionID->clear();

    if(connectionVector.size() > 0)
    {
        for(int i = 0; i < connectionVector.size(); i++)
        {
            ID = connectionVector.at(i).getID();

            stringstream id;
            id << ID;
            string strID = id.str();

            ui->comboBoxConnectionID->addItem(QString::fromStdString(strID));
        }

    }


}

void ConnectionsMenu::on_pushButtonRemoveConnection_clicked()
{
    DomainLayer domain;
    vector<Connections> connectionsVector = domain.sortConnectionsVectorByID();

    if(connectionsVector.size() > 0)
    {
        int ID = ui->comboBoxConnectionID->currentText().toInt();
        if(domain.removeConnection(ID))
        {
            connectionsVector = domain.sortConnectionsVectorByID();
            displayConnectionsVectorInTable(connectionsVector);
            fillComboBoxConnectionID();
        }
        else
        {

        }

    }

}

void ConnectionsMenu::on_commandLinkButtonAddNewConnection_clicked()
{
     addconnectionform.show();
}
