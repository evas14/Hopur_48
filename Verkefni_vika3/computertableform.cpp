#include "computertableform.h"
#include "ui_computertableform.h"

ComputerTableForm::ComputerTableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComputerTableForm)
{
    ui->setupUi(this);
}

ComputerTableForm::~ComputerTableForm()
{
    delete ui;
}
