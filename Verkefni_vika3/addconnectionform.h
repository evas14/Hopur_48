#ifndef ADDCONNECTIONFORM_H
#define ADDCONNECTIONFORM_H

#include <QWidget>
#include <string>
#include <vector>
#include <person.h>
#include <computer.h>
#include <domainlayer.h>
#include <algorithm>
#include <addpersonform.h>
#include <editperson.h>
#include <QMessageBox>

namespace Ui {
class AddConnectionForm;
}

class AddConnectionForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddConnectionForm(QWidget *parent = 0);
    ~AddConnectionForm();
    void displayPersonVector(vector <person> perVec);
    void displayComputerVector(vector <Computer> compVec);
    int findPersonInVector(vector<person> personVector, string nameOfSelected);
    int findComputerInVector(vector <Computer> computerVector, string nameOfSelected);

private slots:
    void on_pushButtonMakeConnection_clicked();

private:
    Ui::AddConnectionForm *ui;
};

#endif // ADDCONNECTIONFORM_H
