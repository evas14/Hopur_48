#include "persontable.h"
#include "ui_persontable.h"

PersonTable::PersonTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonTable)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

PersonTable::~PersonTable()
{
    delete ui;
}

void PersonTable::refresh()
{
    ui->tableWidgetPersons->clear();
    vector <person> personVector = domain.sortPersonVectorByName("normal");
    displayPersonVectorInTable(personVector);
}

void PersonTable::displayPersonVectorInTable(vector<person> personVector)
{
    string personName, gender;
    int ID = 0, yearOfBirth = 0, yearOfDeath = 0, age = 0;

    ui->tableWidgetPersons->clear();
    ui->tableWidgetPersons->setRowCount(personVector.size());

    QTableWidgetItem *headerColumn_1 = new QTableWidgetItem();
    headerColumn_1->setText("ID");
    ui->tableWidgetPersons->setHorizontalHeaderItem(0,headerColumn_1);

    QTableWidgetItem *headerColumn_2 = new QTableWidgetItem();
    headerColumn_2->setText("Name");
    ui->tableWidgetPersons->setHorizontalHeaderItem(1,headerColumn_2);

    QTableWidgetItem *headerColumn_3 = new QTableWidgetItem();
    headerColumn_3->setText("Gender");
    ui->tableWidgetPersons->setHorizontalHeaderItem(2,headerColumn_3);

    QTableWidgetItem *headerColumn_4 = new QTableWidgetItem();
    headerColumn_4->setText("Year of Birth");
    ui->tableWidgetPersons->setHorizontalHeaderItem(3,headerColumn_4);

    QTableWidgetItem *headerColumn_5 = new QTableWidgetItem();
    headerColumn_5->setText("Year of Death");
    ui->tableWidgetPersons->setHorizontalHeaderItem(4,headerColumn_5);

    QTableWidgetItem *headerColumn_6 = new QTableWidgetItem();
    headerColumn_6->setText("Age");
    ui->tableWidgetPersons->setHorizontalHeaderItem(5,headerColumn_6);


    for(unsigned int i = 0; i < personVector.size(); i++)
    {
        personName = personVector.at(i).getName();
        gender = personVector.at(i).getGender();
        ID = personVector.at(i).getID();
        yearOfBirth = personVector.at(i).getYearOfbirth();
        yearOfDeath = personVector.at(i).getYearOfdeath();
        age = personVector.at(i).getAge();

        stringstream id, yearofbirth, yearofdeath, personage;
        id << ID;
        yearofbirth << yearOfBirth;
        yearofdeath << yearOfDeath;
        personage << age;

        string strID = id.str();
        string stryearOfBirth = yearofbirth.str();
        string stryearOfDeath = yearofdeath.str();
        string strage = personage.str();

        QTableWidgetItem *column_1 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(strID)));
        ui->tableWidgetPersons->setItem(i, 0, column_1);

        QTableWidgetItem *column_2 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(personName)));
        ui->tableWidgetPersons->setItem(i, 1, column_2);

        QTableWidgetItem *column_3 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(gender)));
        ui->tableWidgetPersons->setItem(i, 2, column_3);

        QTableWidgetItem *column_4 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(stryearOfBirth)));
        ui->tableWidgetPersons->setItem(i, 3, column_4);

        QTableWidgetItem *column_5 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(stryearOfDeath)));
        ui->tableWidgetPersons->setItem(i, 4, column_5);

        QTableWidgetItem *column_6 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(strage)));
        ui->tableWidgetPersons->setItem(i, 5, column_6);

    }
}

void PersonTable::on_commandLinkButtonRefresh_clicked()
{
    refresh();
}

void PersonTable::on_ButtonClose_clicked()
{
    PersonTable::close();
}

void PersonTable::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void PersonTable::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->move(this->pos() + (event->pos() - mLastMousePosition));
    }
}

void PersonTable::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}
