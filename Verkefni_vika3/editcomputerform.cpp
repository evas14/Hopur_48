#include "editcomputerform.h"
#include "ui_editcomputerform.h"

EditComputerForm::EditComputerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditComputerForm)
{
    ui->setupUi(this);
    ui->lineEditYearBuilt->hide();
}

EditComputerForm::~EditComputerForm()
{
    delete ui;
}

void EditComputerForm::fillInfo(int ID)
{
    DomainLayer domain;

    setComputerID(ID);

    vector<Computer> computerVector = domain.sortComputerVectorByID("normal");
    int locationInVector = 0;

    for(int i = 0; i < computerVector.size(); i++)
    {
        if(computerVector.at(i).getID() == ID)
        {
            locationInVector = i;
            break;
        }
    }

    ui->lineEditComputerName->setText(QString::fromStdString(computerVector.at(locationInVector).getName()));



    stringstream yearBuilt;
    yearBuilt << computerVector.at(locationInVector).getYearBuilt();
    string yearBuiltString = yearBuilt.str();

    ui->lineEditComputerType->setText(QString::fromStdString(computerVector.at(locationInVector).getComputerType()));

    if(computerVector.at(locationInVector).getWasBuilt())
    {
        ui->checkBoxWasBuilt->setChecked(true);
        ui->lineEditYearBuilt->setText(QString::fromStdString(yearBuiltString));
    }
    else
    {
        ui->checkBoxWasBuilt->setChecked(false);
    }
    on_checkBoxWasBuilt_clicked();
}

void EditComputerForm::on_checkBoxWasBuilt_clicked()
{
    if(ui->checkBoxWasBuilt->isChecked())
        ui->lineEditYearBuilt->show();
    else
        ui->lineEditYearBuilt->hide();
}

void EditComputerForm::on_pushButtonUpdateComputer_clicked()
{
    string name, type;
    name = ui->lineEditComputerName->text().toStdString();
    type = ui->lineEditComputerType->text().toStdString();
    bool wasbuilt;
    int yearbuilt = 0, id;
    if(ui->checkBoxWasBuilt->isChecked())
    {
        wasbuilt = true;
        yearbuilt = ui->lineEditYearBuilt->text().toInt();
    }
    else
    {
        wasbuilt = false;
    }
    DomainLayer domain;
    id = getComputerID();
    domain.updateComputer(id, name, type, yearbuilt, wasbuilt);
    qDebug() << "yes";
}

int EditComputerForm::getComputerID() const
{
    return computerID;
}

void EditComputerForm::setComputerID(int value)
{
    computerID = value;
}
