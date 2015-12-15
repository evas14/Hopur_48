#include "computertable.h"
#include "ui_computertable.h"

ComputerTable::ComputerTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComputerTable)
{
    ui->setupUi(this);
}

ComputerTable::~ComputerTable()
{
    delete ui;
}

void ComputerTable::refresh()
{
    ui->tableWidgetComputers->clear();
    vector <Computer> computerVector = domain.sortComputerVectorByName("normal");
    displayComputerVectorInTable(computerVector);

}

void ComputerTable::displayComputerVectorInTable(vector<Computer> computerVector)
{
    string computerName,computerType;
    int ID = 0,yearBuilt;

    ui->tableWidgetComputers->clear();
    ui->tableWidgetComputers->setRowCount(computerVector.size());

    QTableWidgetItem *headerColumn_1 = new QTableWidgetItem();
    headerColumn_1->setText("ID");
    ui->tableWidgetComputers->setHorizontalHeaderItem(0,headerColumn_1);

    QTableWidgetItem *headerColumn_2 = new QTableWidgetItem();
    headerColumn_2->setText("Name");
    ui->tableWidgetComputers->setHorizontalHeaderItem(1,headerColumn_2);

    QTableWidgetItem *headerColumn_3 = new QTableWidgetItem();
    headerColumn_3->setText("Type");
    ui->tableWidgetComputers->setHorizontalHeaderItem(2,headerColumn_3);

    QTableWidgetItem *headerColumn_4 = new QTableWidgetItem();
    headerColumn_4->setText("Was Built");
    ui->tableWidgetComputers->setHorizontalHeaderItem(3,headerColumn_4);

    QTableWidgetItem *headerColumn_5 = new QTableWidgetItem();
    headerColumn_5->setText("Year Built");
    ui->tableWidgetComputers->setHorizontalHeaderItem(4,headerColumn_5);


    for(unsigned int i = 0; i < computerVector.size(); i++)
    {
        computerName = computerVector.at(i).getName();
        computerType = computerVector.at(i).getComputerType();
        ID = computerVector.at(i).getID();
        yearBuilt = computerVector.at(i).getYearBuilt();

        stringstream id,yearbuilt;
        id << ID;
        yearbuilt << yearBuilt;
        string strID = id.str();
        string stryearBuilt = yearbuilt.str();

        QTableWidgetItem *column_1 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(strID)));
        ui->tableWidgetComputers->setItem(i, 0, column_1);

        QTableWidgetItem *column_2 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(computerName)));
        ui->tableWidgetComputers->setItem(i, 1, column_2);

        QTableWidgetItem *column_3 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(computerType)));
        ui->tableWidgetComputers->setItem(i, 2, column_3);

        if(computerVector.at(i).getWasBuilt() == true)
        {
            QTableWidgetItem *column_4 = new QTableWidgetItem(tr("%1").arg("Yes"));
            ui->tableWidgetComputers->setItem(i, 3, column_4);
        }

        else
        {
            QTableWidgetItem *column_4 = new QTableWidgetItem(tr("%1").arg("No"));
            ui->tableWidgetComputers->setItem(i, 3, column_4);
        }

        QTableWidgetItem *column_5 = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(stryearBuilt)));
        ui->tableWidgetComputers->setItem(i, 4, column_5);

    }


}

void ComputerTable::on_commandLinkButtonRefresh_clicked()
{
    refresh();
}
