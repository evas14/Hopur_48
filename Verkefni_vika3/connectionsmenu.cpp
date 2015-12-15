#include "connectionsmenu.h"
#include "ui_connectionsmenu.h"

ConnectionsMenu::ConnectionsMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionsMenu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

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

    displayConnectionsVectorInTable(domain.sortConnectionsVectorByID());
    fillComboBoxConnectionID();

    vector <person> personVector = domain.sortPersonVectorByName("normal");
    vector <Computer> computerVector = domain.sortComputerVectorByName("normal");
    displayPersonVector(personVector);
    displayComputerVector(computerVector);

    if(ui->listWidgetDisplayPerson->count() > 0)
    {
        ui->listWidgetDisplayPerson->item(0)->setSelected(true);
        ui->listWidgetDisplayPerson->setCurrentRow(0);
    }
    else
    {
        QMessageBox::warning(this,"Warning!","Person Table is Empty!");

    }

    if(ui->listWidgetDisplayComputer->count() > 0)
    {
        ui->listWidgetDisplayComputer->item(0)->setSelected(true);
        ui->listWidgetDisplayComputer->setCurrentRow(0);
    }
    else
    {
        QMessageBox::warning(this,"Warning!","Computer Table is Empty!");

    }

    fillComboBoxConnectionID();
}


void ConnectionsMenu::fillComboBoxConnectionID()
{

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



void ConnectionsMenu::on_commandLinkButtonAddNewConnection_clicked()
{
     addconnectionform.show();
}

void ConnectionsMenu::on_pushButtonMakeConnection_clicked()
{
    if(ui->listWidgetDisplayPerson->count() < 1 || ui->listWidgetDisplayComputer->count() < 1)
    {
        QMessageBox::warning(this,"Warning!","List is Empty!");
        return;
    }

    if(ui->listWidgetDisplayPerson->currentItem()->isSelected() &&
       ui->listWidgetDisplayComputer -> currentItem() ->isSelected())
    {

        string nameOfSelectedPerson = ui->listWidgetDisplayPerson->currentItem()->text().toStdString();
        transform(nameOfSelectedPerson.begin(), nameOfSelectedPerson.end(), nameOfSelectedPerson.begin(),::tolower);

        string nameOfSelectedComputer = ui->listWidgetDisplayComputer->currentItem()->text().toStdString();
        transform(nameOfSelectedComputer.begin(), nameOfSelectedComputer.end(), nameOfSelectedComputer.begin(),::tolower);

        vector<person> personVector = domain.sortPersonVectorByName("normal");
        vector<Computer>computerVector = domain.sortComputerVectorByName("normal");

        int personLocationInVector = findPersonInVector(personVector,nameOfSelectedPerson);
        int computerLocationInVector = findComputerInVector(computerVector,nameOfSelectedComputer);

        int personID = personVector.at(personLocationInVector).getID();
        int computerID = computerVector.at(computerLocationInVector).getID();

        domain.addConnection(personID,computerID);

        ui->listWidgetDisplayPerson->clear();
        ui->listWidgetDisplayComputer->clear();
        refresh();


    }

    else
    {
        QMessageBox::warning(this,"Warning!","Select a person and computer");
    }


}

void ConnectionsMenu::displayPersonVector(vector<person> perVec)
{
    string name;
    ui->listWidgetDisplayPerson->clear();
    for(unsigned int i = 0; i < perVec.size(); i++)
    {
        person per = perVec.at(i);
        name = per.getName();

        ui->listWidgetDisplayPerson->addItem(QString::fromStdString(name));

    }

}

void ConnectionsMenu::displayComputerVector(vector<Computer> compVec)
{

    string name;
    ui->listWidgetDisplayComputer->clear();
    for(unsigned int i = 0; i < compVec.size(); i++)
    {
        Computer com = compVec.at(i);
        name = com.getName();

        ui->listWidgetDisplayComputer->addItem(QString::fromStdString(name));
    }
}


int ConnectionsMenu::findPersonInVector(vector<person> personVector, string nameOfSelected)
{
    string personName;
    for(unsigned int i = 0; i < personVector.size(); i++)
    {
        personName = personVector.at(i).getName();
        transform(personName.begin(), personName.end(), personName.begin(),::tolower);

        if(personName == nameOfSelected)
        {
            return i;
        }
    }

}

int ConnectionsMenu::findComputerInVector(vector<Computer> computerVector, string nameOfSelected)
{
    string computerName;
    for(unsigned int i = 0; i < computerVector.size(); i++)
    {
        computerName = computerVector.at(i).getName();
        transform(computerName.begin(), computerName.end(), computerName.begin(),::tolower);

        if(computerName == nameOfSelected)
        {
            return i;
        }
    }
    return -1;
}


void ConnectionsMenu::on_commandLinkButtonRemoveConnection_clicked()
{
    vector<Connections> connectionsVector = domain.sortConnectionsVectorByID();

    if(connectionsVector.size() > 0)
    {
        int ID = ui->comboBoxConnectionID->currentText().toInt();
        if(domain.removeConnection(ID))
        {
            connectionsVector = domain.sortConnectionsVectorByID();
            displayConnectionsVectorInTable(connectionsVector);
            refresh();
        }
        else
        {

        }

    }
}

void ConnectionsMenu::on_pushButtonRefresh_clicked()
{
    refresh();
}

void ConnectionsMenu::on_ButtonClose_clicked()
{
    ConnectionsMenu::close();
}

void ConnectionsMenu::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void ConnectionsMenu::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->move(this->pos() + (event->pos() - mLastMousePosition));
    }
}

void ConnectionsMenu::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}
