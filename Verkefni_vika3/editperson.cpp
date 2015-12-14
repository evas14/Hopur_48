#include "editperson.h"
#include "ui_editperson.h"


EditPerson::EditPerson(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPerson)
{
    ui->setupUi(this);

}

EditPerson::~EditPerson()
{
    delete ui;
}


void EditPerson::fillInfo(int ID)
{
    DomainLayer domain;

    vector<person> personVector = domain.sortPersonVectorByID("normal");
    int locationInVector = 0;

    for(int i = 0; i < personVector.size(); i++)
    {
        if(personVector.at(i).getID() == ID)
        {
            locationInVector = i;
            break;
        }
    }

    setPersonID(personVector.at(locationInVector).getID());

    ui->lineEditPersonName->setText(QString::fromStdString(personVector.at(locationInVector).getName()));

    if(personVector.at(locationInVector).getGender() == "Male")
    {
        ui->radioButtonPersonGenderMale->setChecked(true);
    }
    else
    {
        ui->radioButtonPersonGenderFemale->setChecked(true);
    }


    stringstream yearofbirth, yearofdeath;
    yearofbirth << personVector.at(locationInVector).getYearOfbirth();
    yearofdeath << personVector.at(locationInVector).getYearOfdeath();
    string yearofbirthstring = yearofbirth.str();
    string yearofdeathstring = yearofdeath.str();

    ui->lineEditPersonYearOfBirth->setText(QString::fromStdString(yearofbirthstring));
    ui->lineEditPersonYearOfDeath->setText(QString::fromStdString(yearofdeathstring));

    if(personVector.at(locationInVector).getYearOfdeath() == 0)
    {
        ui->checkBoxPersonAlive->setChecked(true);

    }
    else
    {
        ui->checkBoxPersonAlive->setChecked(false);
    }
    on_checkBoxPersonAlive_clicked();


}

void EditPerson::on_checkBoxPersonAlive_clicked()
{
    if(!ui->checkBoxPersonAlive->isChecked())
    {
        ui->lineEditPersonYearOfDeath->show();
    }
    else
    {
        ui->lineEditPersonYearOfDeath->hide();
    }
}

void EditPerson::on_pushButton_clicked()
{
    ui->lineEditPersonName->clear();
    ui->lineEditPersonYearOfBirth->clear();
    ui->lineEditPersonYearOfDeath->clear();
}

void EditPerson::on_pushButtonPersonUpdate_clicked()
{
    int ID = getPersonID();
}

int EditPerson::getPersonID() const
{
    return PersonID;
}

void EditPerson::setPersonID(int value)
{
    PersonID = value;
}
