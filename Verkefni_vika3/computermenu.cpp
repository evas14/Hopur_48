#include "computermenu.h"
#include "ui_computermenu.h"

ComputerMenu::ComputerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComputerMenu)
{
    ui->setupUi(this);
}

ComputerMenu::~ComputerMenu()
{
    delete ui;
}
