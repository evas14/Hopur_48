#include "computermenu.h"
#include "ui_computermenu.h"

ComputerMenu::ComputerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComputerMenu)
{
    ui->setupUi(this);
    ui->labelYearBuilt->hide();
    ui->label4->hide();
    ui->lineEditComputerYearBuilt->hide();
    ui->label_3->hide();

    setWindowFlags(Qt::FramelessWindowHint);
}

ComputerMenu::~ComputerMenu()
{
    delete ui;
}

void ComputerMenu::displayComputerVector(vector<Computer> compVec)
{
    string name;
    ui->listWidgetComputer->clear();
    for(unsigned int i = 0; i < compVec.size(); i++)
    {
        Computer comp = compVec.at(i);
        name = comp.getName();

        ui->listWidgetComputer->addItem(QString::fromStdString(name));

    }

    if(ui->listWidgetComputer->count() > 0)
    {
        ui->listWidgetComputer->item(0)->setSelected(true);
        ui->listWidgetComputer->setCurrentRow(0);
    }

}

void ComputerMenu::refresh()
{

    vector <Computer> computerVector = domain.sortComputerVectorByName("normal");
    displayComputerVector( computerVector);
    ui->lineEditSearchComputer->clear();

    if(ui->listWidgetComputer->count() > 0)
    {
        ui->listWidgetComputer->item(0)->setSelected(true);
        ui->listWidgetComputer->setCurrentRow(0);
        on_listWidgetComputer_clicked(ui->listWidgetComputer->currentIndex());
    }
    else
    {
        QMessageBox::warning(this,"Warning!","Database is empty");
    }

}

int ComputerMenu::findComputerInVector(vector<Computer> computerVector, string nameofSelected)
{
    string computerName;
    for(unsigned int i = 0; i < computerVector.size(); i++)
    {
        computerName = computerVector.at(i).getName();
        transform(computerName.begin(), computerName.end(), computerName.begin(),::tolower);

        if(computerName == nameofSelected)
        {
            return i;
        }
    }

}

void ComputerMenu::on_commandLinkButtonAddNewComputer_clicked()
{
    string name,computerType;
    int yearBuilt = 0;
    bool wasBuilt;

    name = ui->lineEditComputerName->text().toStdString();
    computerType = ui->lineEditComputerType->text().toStdString();
    yearBuilt = ui->lineEditComputerYearBuilt->text().toInt();

    if(ui->checkBoxWasBuilt->isChecked())
    {
        wasBuilt = true;
    }
    else
    {
        wasBuilt = false;
        yearBuilt = 0;
    }

    domain.addComputer(name,computerType,yearBuilt,wasBuilt);
    refresh();
}

void ComputerMenu::on_commandLinkButtonRemoveComputer_clicked()
{
    if(ui->listWidgetComputer->count() < 1)
    {
        QMessageBox::warning(this,"Warning!","List is Empty!");
        return;
    }

    if(ui->listWidgetComputer->currentItem()->isSelected())
    {

        string nameOfSelected = ui->listWidgetComputer->currentItem()->text().toStdString();
        transform(nameOfSelected.begin(), nameOfSelected.end(), nameOfSelected.begin(),::tolower);

        vector<Computer> computerVector = domain.sortComputerVectorByName("Normal");
        string computerName;

        int locationInVector = findComputerInVector(computerVector,nameOfSelected);

        domain.removeComputer(computerVector.at(locationInVector).getID());

        refresh();


    }

    else
    {
        QMessageBox::warning(this,"Warning!","Select a computer");
    }


}

void ComputerMenu::on_commandLinkButtonEditComputer_clicked()
{
    int compID = getComputerID();
    int yearBuild = 0;
    bool wasBuilt;

    string name = ui->lineEditComputerName->text().toStdString();
    string type = ui->lineEditComputerType->text().toStdString();

    if(ui->checkBoxWasBuilt->isChecked())
    {
        wasBuilt = true;
        yearBuild = ui->lineEditComputerYearBuilt->text().toInt();
    }
    else
    {
        wasBuilt = false;
    }


    domain.updateComputer(compID,name,type,yearBuild,wasBuilt);
    refresh();



}

void ComputerMenu::on_commandLinkButtonShowTable_clicked()
{
    comptable.refresh();
    comptable.show();
}

void ComputerMenu::on_lineEditSearchComputer_textChanged(const QString &arg1)
{

    string Query = arg1.toStdString();

    vector<Computer> computerVector = domain.searchComputerByName(Query);
    displayComputerVector(computerVector);


    if(ui->listWidgetComputer->count() > 0)
    {
        ui->listWidgetComputer->item(0)->setSelected(true);
        ui->listWidgetComputer->setCurrentRow(0);
        on_listWidgetComputer_clicked(ui->listWidgetComputer->currentIndex());
    }

}


void ComputerMenu::on_listWidgetComputer_clicked(const QModelIndex &index)
{
    string nameOfSelected = ui->listWidgetComputer->currentItem()->text().toStdString();
    transform(nameOfSelected.begin(), nameOfSelected.end(), nameOfSelected.begin(),::tolower);

    vector<Computer> computerVector = domain.sortComputerVectorByName("Normal");
    string computerName;

    int locationInVector = findComputerInVector(computerVector,nameOfSelected);

    Computer selected = computerVector.at(locationInVector);

    stringstream yearBuilt;
    yearBuilt << selected.getYearBuilt();
    string strYearBuilt = yearBuilt.str();


    ui->labelName->setText(QString::fromStdString(selected.getName()));
    ui->labelType->setText(QString::fromStdString(selected.getComputerType()));
    ui->labelYearBuilt->setText(QString::fromStdString(strYearBuilt));

    ui->lineEditComputerName->setText(QString::fromStdString(selected.getName()));
    ui->lineEditComputerType->setText(QString::fromStdString(selected.getComputerType()));
    ui->lineEditComputerYearBuilt->setText(QString::fromStdString(strYearBuilt));

    if(selected.getWasBuilt()== 1)
    {
        ui->labelWasBuilt->setText("Yes");
        ui->labelYearBuilt->show();
        ui->label4->show();
        ui->label_3->show();
        ui->lineEditComputerYearBuilt->show();
        ui->checkBoxWasBuilt->setChecked(true);

    }

    else
    {
        ui->checkBoxWasBuilt->setChecked(false);
        ui->labelWasBuilt->setText("No");
        ui->labelYearBuilt->hide();
        ui->label4->hide();
        ui->lineEditComputerYearBuilt->hide();
        ui->label_3->hide();

    }

    setComputerID(selected.getID());
}

void ComputerMenu::on_checkBoxWasBuilt_clicked()
{
    if(ui->checkBoxWasBuilt->isChecked())
    {
        ui->lineEditComputerYearBuilt->show();
        ui->label_3->show();
    }
    else
    {
        ui->lineEditComputerYearBuilt->hide();
        ui->lineEditComputerYearBuilt->clear();
        ui->label_3->hide();
    }
}

int ComputerMenu::getComputerID() const
{
    return computerID;
}

void ComputerMenu::setComputerID(int value)
{
    computerID = value;
}

void ComputerMenu::on_ButtonCllose_clicked()
{
    ComputerMenu::close();
}

void ComputerMenu::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void ComputerMenu::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->move(this->pos() + (event->pos() - mLastMousePosition));
    }
}

void ComputerMenu::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}
