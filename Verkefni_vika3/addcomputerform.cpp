#include "addcomputerform.h"
#include "ui_addcomputerform.h"

AddComputerForm::AddComputerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddComputerForm)
{
    ui->setupUi(this);
}

AddComputerForm::~AddComputerForm()
{
    delete ui;
}

void AddComputerForm::on_pushButtonAddComputer_clicked()
{
    string name, type;
    name = ui->lineEditComputerName->text().toStdString();
    type = ui->lineEditComputerType->text().toStdString();
    bool wasbuilt;
    int yearbuilt = 0;
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
    domain.addComputer(name, type, yearbuilt, wasbuilt);

}
