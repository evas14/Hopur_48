#include "personmenu.h"
#include "ui_personmenu.h"

PersonMenu::PersonMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonMenu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
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

    if(ui->listWidgetPerson->count() > 0)
    {
        ui->listWidgetPerson->item(0)->setSelected(true);
        ui->listWidgetPerson->setCurrentRow(0);
    }



}

void PersonMenu::on_lineEditSearch_textChanged(const QString &arg1)
{
    ui->listWidgetPerson->clear();

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

    string nameOfSelected = ui->listWidgetPerson->currentItem()->text().toStdString();
    transform(nameOfSelected.begin(), nameOfSelected.end(), nameOfSelected.begin(),::tolower);

    vector<person> personVector = domain.sortPersonVectorByName("Normal");
    string personName;

    int locationInVector = findPersonInVector(personVector,nameOfSelected);

    person selected = personVector.at(locationInVector);

    setPersonID(selected.getID());

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

    ui->lineEditPersonName->setText(QString::fromStdString(selected.getName()));
    ui->lineEditPersonYearOfBirth->setText(QString::fromStdString(strYearofbirth));
    ui->lineEditPersonYearOfDeath->setText(QString::fromStdString(strYearofdeath));
    if(selected.getYearOfdeath() == 0)
    {
        ui->label5->setText("");
        ui->labelYearofDeath->setText("");
        ui->checkBoxPersonAlive->setChecked(true);
        ui->lineEditPersonYearOfDeath->hide();
    }
    else
    {
        ui->label5->setText("Year Of Death:");
        ui->labelYearofDeath->setText(QString::fromStdString(strYearofdeath));
        ui->checkBoxPersonAlive->setChecked(false);
        ui->lineEditPersonYearOfDeath->show();
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

        string nameOfSelected = ui->listWidgetPerson->currentItem()->text().toStdString();
        transform(nameOfSelected.begin(), nameOfSelected.end(), nameOfSelected.begin(),::tolower);

        vector<person> personVector = domain.sortPersonVectorByName("Normal");
        string personName;

        int locationInVector = findPersonInVector(personVector,nameOfSelected);

        if(domain.removePerson(personVector.at(locationInVector).getID()))
            ui->labelStatus->setText("<font color = 'green'> Operation Successful! </font>");
        else
            ui->labelStatus->setText("<font color = 'red'> Error: Failed to remove person! </font>");


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

bool PersonMenu::validateInput()
{
    int validation = 0;
    if(ui->lineEditPersonName->text().isEmpty() ||
       ui->lineEditPersonName->text() == "Cannot Be Empty!")
    {
        ui->lineEditPersonName->setText("Cannot Be Empty!");
        validation = 1;
    }

    if(ui->lineEditPersonYearOfBirth->text().isEmpty())
    {
        ui->lineEditPersonYearOfBirth->setText("Cannot Be Empty!");
        validation = 1;
    }

    if(ui->lineEditPersonYearOfDeath->text().isEmpty())
    {
        if(!ui->checkBoxPersonAlive->isChecked())
        {
            ui->lineEditPersonYearOfDeath->setText("Cannot Be Empty!");
            validation = 1;
        }
    }

    if (validation == 1)
    {
        return false;
    }

    return true;

}



void PersonMenu::on_commandLinkButtonShowTable_clicked()
{
    persontable.show();
    persontable.refresh();
}

void PersonMenu::Refresh()
{
    ui->listWidgetPerson->clear();
    vector <person> personVector = domain.sortPersonVectorByName("normal");
    displayPersonVector(personVector);
    ui->lineEditSearch->clear();


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

void PersonMenu::on_pushButtonClear_clicked()
{
   ui->lineEditPersonName->clear();
   ui->lineEditPersonYearOfBirth->clear();
   ui->radioButtonPersonGenderMale->setChecked(true);
   ui->checkBoxPersonAlive->setChecked(false);
   ui->lineEditPersonYearOfDeath->clear();
   ui->lineEditPersonYearOfDeath->show();
   ui->labelStatus->clear();
}

void PersonMenu::on_pushButtonAddPerson_clicked()
{

    string name;
    string gender;
    int yearofbirth=0,yearofdeath=0, status = 0;;


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
        yearofdeath = 0;
    }

    else
    { 
        yearofdeath = ui->lineEditPersonYearOfDeath->text().toInt();
    }

    if(validateInput())
    {
        status = domain.addPerson(name,gender,yearofbirth,yearofdeath);

        switch(status)
        {
            case 0:
                ui->labelStatus->setText("<font color = 'green'> Operation Successful! </font>");
                break;
            case 1:
                ui->labelStatus->setText("<font color = 'red'>Error: Name cannot contain numbers! </font>");
                break;
            case 2:
                ui->labelStatus->setText("<font color = 'red'>Error: Invalid Birth Year! </font>");
                break;
            case 3:
                ui->labelStatus->setText("<font color = 'red'>Error: Invalid Death Year! </font>");
                break;
            case 4:
                ui->labelStatus->setText("<font color = 'red'>Error: Database Error! </font>");
                break;
        }
        Refresh();
    }


}

void PersonMenu::on_checkBoxPersonAlive_clicked()
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



void PersonMenu::on_pushButtonUpdatePerson_clicked()
{
    if(ui->listWidgetPerson->count() < 1)
    {
        QMessageBox::warning(this,"Warning!","List is Empty!");
        return;
    }

    if(ui->listWidgetPerson->currentItem()->isSelected())
    {
        string name = ui->lineEditPersonName->text().toStdString();
        string gender;
        int yearofbirth = ui->lineEditPersonYearOfBirth->text().toInt();
        int yearofdeath, status = 0;

        if(ui->radioButtonPersonGenderMale->isChecked())
        {
            gender = "Male";
        }
        else
        {
            gender = "Female";
        }

        if(ui->checkBoxPersonAlive->isChecked())
        {
            yearofdeath = 0;
        }
        else
        {
            yearofdeath = ui->lineEditPersonYearOfDeath->text().toInt();
        }

        if(validateInput())
        {
            status = domain.updatePerson(getPersonID(),name,gender,yearofbirth,yearofdeath);

            switch(status)
            {
                case 0:
                    ui->labelStatus->setText("<font color = 'green'> Operation Successful! </font>");
                    break;
                case 1:
                    ui->labelStatus->setText("<font color = 'red'>Error: Name cannot contain numbers! </font>");
                    break;
                case 2:
                    ui->labelStatus->setText("<font color = 'red'>Error: Invalid Birth Year! </font>");
                    break;
                case 3:
                    ui->labelStatus->setText("<font color = 'red'>Error: Invalid Death Year! </font>");
                    break;
                case 4:
                    ui->labelStatus->setText("<font color = 'red'>Error: Database Error! </font>");
                    break;

            }
            Refresh();
        }


    }

    else
    {
        QMessageBox::warning(this,"Warning!","Select a person");
    }




}

int PersonMenu::getPersonID() const
{
    return personID;
}

void PersonMenu::setPersonID(int value)
{
    personID = value;
}


void PersonMenu::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void PersonMenu::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->move(this->pos() + (event->pos() - mLastMousePosition));
    }
}

void PersonMenu::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}

void PersonMenu::on_pushButton_clicked()
{
     PersonMenu::close();
}
