#include "personmenu.h"
#include "ui_personmenu.h"

PersonMenu::PersonMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonMenu)
{
    ui->setupUi(this);
    DomainLayer domain;
    vector <person> personVector = domain.sortPersonVectorByName("normal");
    displayPersonVector(personVector);

    if(ui->listWidgetPerson->count() > 0)
    {
        ui->listWidgetPerson->item(0)->setSelected(true);
        ui->listWidgetPerson->setCurrentRow(0);
        on_listWidgetPerson_clicked(ui->listWidgetPerson->currentIndex());
    }
    else
    {
        QMessageBox::warning(this,"Warning!","Database is empty");
    }
}

PersonMenu::~PersonMenu()
{
    delete ui;
}

void PersonMenu::displayPersonVector(vector<person> perVec)
{
    string name;
    for(unsigned int i = 0; i < perVec.size(); i++)
    {
        person per = perVec.at(i);
        name = per.getName();

        ui->listWidgetPerson->addItem(QString::fromStdString(name));

    }

}

void PersonMenu::on_lineEditSearch_textChanged(const QString &arg1)
{
    ui->listWidgetPerson->clear();

    DomainLayer domain;
    string Query = arg1.toStdString();

    vector<person> personVector = domain.searchPersonByName(Query);
    displayPersonVector(personVector);


    if(ui->listWidgetPerson->count() > 0)
    {
        ui->listWidgetPerson->item(0)->setSelected(true);
        ui->listWidgetPerson->setCurrentRow(0);
    }

}

void PersonMenu::on_listWidgetPerson_clicked(const QModelIndex &index)
{
    DomainLayer domain;

    string nameOfSelected = ui->listWidgetPerson->currentItem()->text().toStdString();
    transform(nameOfSelected.begin(), nameOfSelected.end(), nameOfSelected.begin(),::tolower);

    vector<person> personVector = domain.sortPersonVectorByName("Normal");
    string personName;

    int locationInVector = findPersonInVector(personVector,nameOfSelected);

    person selected = personVector.at(locationInVector);

    stringstream personAge, personYearofbirth,personYearofdeath;
    personAge << selected.getAge();
    personYearofbirth << selected.getYearOfbirth();
    personYearofdeath << selected.getYearOfdeath();
    string strAge = personAge.str();
    string strYearofbirth = personYearofbirth.str();
    string strYearofdeath = personYearofdeath.str();


    ui->labelName->setText(QString::fromStdString(selected.getName()));
    ui->labelGender->setText(QString::fromStdString(selected.getGender()));
    ui->labelAge->setText(QString::fromStdString(strAge));
    ui->labelYearofBirth->setText(QString::fromStdString(strYearofbirth));
    if(selected.getYearOfdeath() == 0)
    {
        ui->label5->setText("");
        ui->labelYearofDeath->setText("");
    }
    else
    {
        ui->label5->setText("Year Of Death:");
        ui->labelYearofDeath->setText(QString::fromStdString(strYearofdeath));
    }


}

void PersonMenu::on_listWidgetPerson_activated(const QModelIndex &index)
{
    on_listWidgetPerson_clicked(index);
}


void PersonMenu::on_commandLinkButtonRemovePerson_clicked()
{
    if(ui->listWidgetPerson->count() < 1)
    {
        QMessageBox::warning(this,"Warning!","List is Empty!");
        return;
    }

    if(ui->listWidgetPerson->currentItem()->isSelected())
    {
        DomainLayer domain;

        string nameOfSelected = ui->listWidgetPerson->currentItem()->text().toStdString();
        transform(nameOfSelected.begin(), nameOfSelected.end(), nameOfSelected.begin(),::tolower);

        vector<person> personVector = domain.sortPersonVectorByName("Normal");
        string personName;

        int locationInVector = findPersonInVector(personVector,nameOfSelected);

        domain.removePerson(personVector.at(locationInVector).getID());

        ui->listWidgetPerson->clear();

        personVector = domain.sortPersonVectorByName("normal");
        displayPersonVector(personVector);


    }

    else
    {
        QMessageBox::warning(this,"Warning!","Select a person");
    }


}

int PersonMenu::findPersonInVector(vector<person> personVector, string nameOfSelected)
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

void PersonMenu::on_commandLinkButtonAddNewPerson_clicked()
{
    addpersonform.show();
}

void PersonMenu::on_commandLinkButtonEditPerson_clicked()
{
    if(ui->listWidgetPerson->count() < 1)
    {
        QMessageBox::warning(this,"Warning!","List is Empty!");
        return;
    }

    if(ui->listWidgetPerson->currentItem()->isSelected())
    {
        DomainLayer domain;

        string nameOfSelected = ui->listWidgetPerson->currentItem()->text().toStdString();
        transform(nameOfSelected.begin(), nameOfSelected.end(), nameOfSelected.begin(),::tolower);

        vector<person> personVector = domain.sortPersonVectorByName("Normal");
        string personName;

        int locationInVector = findPersonInVector(personVector,nameOfSelected);

        person selected = personVector.at(locationInVector);

        editpersonform.fillInfo(selected.getID());
        editpersonform.show();
    }
    else
    {
        QMessageBox::warning(this,"Warning!","Select a person");
    }

}

void PersonMenu::on_commandLinkButtonShowTable_clicked()
{
    //Show table form
}