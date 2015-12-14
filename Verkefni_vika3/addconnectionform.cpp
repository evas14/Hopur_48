#include "addconnectionform.h"
#include "ui_addconnectionform.h"

AddConnectionForm::AddConnectionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddConnectionForm)
{
    ui->setupUi(this);
    DomainLayer domain;
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

}

AddConnectionForm::~AddConnectionForm()
{
    delete ui;
}

void AddConnectionForm::displayPersonVector(vector<person> perVec)
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

void AddConnectionForm::displayComputerVector(vector<Computer> compVec)
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

int AddConnectionForm::findPersonInVector(vector<person> personVector, string nameOfSelected)
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

int AddConnectionForm::findComputerInVector(vector<Computer> computerVector, string nameOfSelected)
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

}


void AddConnectionForm::on_pushButtonMakeConnection_clicked()
{
    if(ui->listWidgetDisplayPerson->count() < 1 || ui->listWidgetDisplayComputer->count() < 1)
    {
        QMessageBox::warning(this,"Warning!","List is Empty!");
        return;
    }

    if(ui->listWidgetDisplayPerson->currentItem()->isSelected() &&
       ui->listWidgetDisplayComputer -> currentItem() ->isSelected())
    {
        DomainLayer domain;

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

        personVector = domain.sortPersonVectorByName("normal");
        displayPersonVector(personVector);

        computerVector = domain.sortComputerVectorByName("normal");
        displayComputerVector(computerVector);


    }

    else
    {
        QMessageBox::warning(this,"Warning!","Select a person and computer");
    }

}
