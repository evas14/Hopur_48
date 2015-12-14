#include "addpersonform.h"
#include "ui_addpersonform.h"

AddPersonForm::AddPersonForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPersonForm)
{
    ui->setupUi(this);
    on_checkBoxPersonAlive_clicked();
    ui->radioButtonPersonGenderMale->clicked();


}

AddPersonForm::~AddPersonForm()
{
    delete ui;
}

void AddPersonForm::on_checkBoxPersonAlive_clicked()
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

void AddPersonForm::on_pushButtonClear_clicked()
{
    ui->lineEditPersonName->clear();
    ui->lineEditPersonYearOfBirth->clear();
    ui->lineEditPersonYearOfDeath->clear();
}

void AddPersonForm::on_pushButtonAddPerson_clicked()
{
    string name;
    string gender;
    int yearofbirth=0,yearofdeath=0;


    name = ui->lineEditPersonName->text().toStdString();

    if(ui->radioButtonPersonGenderMale->isChecked())
    {
        gender = "Male";
    }
    else
    {
        gender = "Female";
    }

    yearofbirth = ui->lineEditPersonYearOfBirth->text().toInt();

    if(ui->checkBoxPersonAlive->isChecked())
    {
        yearofdeath = ui->lineEditPersonYearOfDeath->text().toInt();
    }

    else
    {
        yearofdeath = 0;
    }

    DomainLayer domain;
    domain.addPerson(name,gender,yearofbirth,yearofdeath);

    this->close();

}
