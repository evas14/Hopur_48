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

}

void PersonMenu::on_listWidgetPerson_clicked(const QModelIndex &index)
{
    DomainLayer domain;
    int locationInVector = 0;

    string nameOfSelected = ui->listWidgetPerson->currentItem()->text().toStdString();
    transform(nameOfSelected.begin(), nameOfSelected.end(), nameOfSelected.begin(),::tolower);

    vector<person> personVector = domain.sortPersonVectorByName("Normal");
    string personName;



    for(unsigned int i = 0; i < personVector.size(); i++)
    {
        personName = personVector.at(i).getName();
        transform(personName.begin(), personName.end(), personName.begin(),::tolower);

        if(personName == nameOfSelected)
        {
            locationInVector = i;
            break;
        }
    }

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

