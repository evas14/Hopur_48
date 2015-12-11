#include "displayform.h"
#include "ui_displayform.h"

DisplayForm::DisplayForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayForm)
{
    ui->setupUi(this);
    ui->radioButtonAscending->setChecked(true);
    ui->tableWidgetDisplayInfo->verticalHeader()->hide();
    on_pushButtonPersonSort_clicked();



}

DisplayForm::~DisplayForm()
{
    delete ui;
}

void DisplayForm::displayPersonVectorInTable(vector<person> perVec)
{
    string name;
    string gender;
    int age = 0;
    int yearofbirth=0;
    int yearofdeath=0;

    ui->tableWidgetDisplayInfo->setColumnCount(5);
    ui->tableWidgetDisplayInfo->setRowCount(perVec.size());


    QTableWidgetItem *headerColumn_1 = new QTableWidgetItem();
    headerColumn_1->setText("Name");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(0,headerColumn_1);

    QTableWidgetItem *headerColumn_2 = new QTableWidgetItem();
    headerColumn_2->setText("Gender");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(1,headerColumn_2);

    QTableWidgetItem *headerColumn_3 = new QTableWidgetItem();
    headerColumn_3->setText("Age");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(2,headerColumn_3);

    QTableWidgetItem *headerColumn_4 = new QTableWidgetItem();
    headerColumn_4->setText("Year of Birth");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(3,headerColumn_4);

    QTableWidgetItem *headerColumn_5 = new QTableWidgetItem();
    headerColumn_5->setText("Year of Death");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(4,headerColumn_5);

    for(unsigned int i = 0; i < perVec.size(); i++)
       {
           person per = perVec.at(i);
           name = per.getName();
           gender = per.getGender();
           age = per.getAge();
           yearofbirth = per.getYearOfbirth();
           yearofdeath = per.getYearOfdeath();

           QTableWidgetItem *column_1 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(name)));
           ui->tableWidgetDisplayInfo->setItem(i, 0, column_1);

           QTableWidgetItem *column_2 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(gender)));
           ui->tableWidgetDisplayInfo->setItem(i, 1, column_2);

           QTableWidgetItem *column_3 = new QTableWidgetItem(tr("%1").arg(age));
           ui->tableWidgetDisplayInfo->setItem(i, 2, column_3);

           QTableWidgetItem *column_4 = new QTableWidgetItem(tr("%1").arg(yearofbirth));
           ui->tableWidgetDisplayInfo->setItem(i, 3, column_4);

           QTableWidgetItem *column_5 = new QTableWidgetItem(tr("%1").arg(yearofdeath));
           ui->tableWidgetDisplayInfo->setItem(i, 4, column_5);

       }


}

void DisplayForm::displayComputerVectorInTable(vector<Computer> compVec)
{
    string name;
    string type;
    int yearbuilt=0;
    bool wasbuilt;


    ui->tableWidgetDisplayInfo->setColumnCount(4);
    ui->tableWidgetDisplayInfo->setRowCount(compVec.size());


    QTableWidgetItem *headerColumn_1 = new QTableWidgetItem();
    headerColumn_1->setText("Name");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(0,headerColumn_1);

    QTableWidgetItem *headerColumn_2 = new QTableWidgetItem();
    headerColumn_2->setText("Type");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(1,headerColumn_2);

    QTableWidgetItem *headerColumn_3 = new QTableWidgetItem();
    headerColumn_3->setText("Year Built");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(2,headerColumn_3);

    QTableWidgetItem *headerColumn_4 = new QTableWidgetItem();
    headerColumn_4->setText("Was it Built");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(3,headerColumn_4);



    for(unsigned int i = 0; i < compVec.size(); i++)
       {
           Computer comp = compVec.at(i);
           name = comp.getName();
           type = comp.getComputerType();
           yearbuilt = comp.getYearBuilt();
           wasbuilt = comp.getWasBuilt();

           QTableWidgetItem *column_1 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(name)));
           ui->tableWidgetDisplayInfo->setItem(i, 0, column_1);

           QTableWidgetItem *column_2 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(type)));
           ui->tableWidgetDisplayInfo->setItem(i, 1, column_2);

           QTableWidgetItem *column_3 = new QTableWidgetItem(tr("%1").arg(yearbuilt));
           ui->tableWidgetDisplayInfo->setItem(i, 2, column_3);

           if(wasbuilt)
           {
               QTableWidgetItem *column_4 = new QTableWidgetItem(tr("%1").arg("Yes"));
               ui->tableWidgetDisplayInfo->setItem(i, 3, column_4);
           }

           else
           {
               QTableWidgetItem *column_4 = new QTableWidgetItem(tr("%1").arg("No"));
               ui->tableWidgetDisplayInfo->setItem(i, 3, column_4);
           }



       }


}

void DisplayForm::displayConnectionsVectorInTable(vector<Connections> conVec)
{
    string personName;
    string computerName;


    ui->tableWidgetDisplayInfo->setColumnCount(2);
    ui->tableWidgetDisplayInfo->setRowCount(conVec.size());

    QTableWidgetItem *headerColumn_1 = new QTableWidgetItem();
    headerColumn_1->setText("Person Name");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(0,headerColumn_1);

    QTableWidgetItem *headerColumn_2 = new QTableWidgetItem();
    headerColumn_2->setText("Computer Name");
    ui->tableWidgetDisplayInfo->setHorizontalHeaderItem(1,headerColumn_2);

    for(unsigned int i = 0; i < conVec.size(); i++)
    {
        Connections con = conVec.at(i);
        personName = con.getPersonName();
        computerName = con.getComputerName();

        QTableWidgetItem *column_1 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(personName)));
        ui->tableWidgetDisplayInfo->setItem(i, 0, column_1);

        QTableWidgetItem *column_2 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(computerName)));
        ui->tableWidgetDisplayInfo->setItem(i, 1, column_2);

    }


}

void DisplayForm::on_pushButtonPersonSort_clicked()
{

    DomainLayer domain;
    ui->tableWidgetDisplayInfo->clear();

    if(ui->comboBoxSortPerson->currentText()=="Name")
    {
        if(ui->radioButtonAscending->isChecked())
        {
           vector<person>personVector = domain.sortPersonVectorByName("normal");
           displayPersonVectorInTable(personVector);
        }

        else
        {
            vector<person>personVector = domain.sortPersonVectorByName("reverse");
            displayPersonVectorInTable(personVector);
        }

    }


    if(ui->comboBoxSortPerson->currentText()=="Age")
    {
        if(ui->radioButtonAscending->isChecked())
        {
            vector<person>personVector = domain.sortPersonVectorByAge("normal");
            displayPersonVectorInTable(personVector);
        }

        else
        {
            vector<person>personVector = domain.sortPersonVectorByAge("reverse");
            displayPersonVectorInTable(personVector);
        }

    }

}

void DisplayForm::on_pushButtonComputerSort_clicked()
{
    ui->tableWidgetDisplayInfo->clear();
    DomainLayer domain;




    if(ui->comboBoxSortComputer->currentText()=="Name")
    {
        if(ui->radioButtonAscending->isChecked())
        {
            vector<Computer>computerVector = domain.sortComputerVectorByName("normal");
            displayComputerVectorInTable(computerVector);
        }

        else
        {
            vector<Computer>computerVector = domain.sortComputerVectorByName("reverse");
            displayComputerVectorInTable(computerVector);

        }

    }



}

void DisplayForm::on_pushButtonConnectionsSort_clicked()
{
    ui->tableWidgetDisplayInfo->clear();
    DomainLayer domain;

    vector<Connections> connectionsVector = domain.sortConnectionsVectorByID();
    displayConnectionsVectorInTable(connectionsVector);


}

void DisplayForm::on_radioButtonAlphabeticalSort_clicked()
{
    on_pushButtonPersonSort_clicked();
}
