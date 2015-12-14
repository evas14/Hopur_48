#ifndef ADDPERSONFORM_H
#define ADDPERSONFORM_H

#include <QWidget>
#include <domainlayer.h>
#include <string>

using namespace std;

namespace Ui {
class AddPersonForm;
}

class AddPersonForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddPersonForm(QWidget *parent = 0);
    ~AddPersonForm();

private slots:
    void on_checkBoxPersonAlive_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonAddPerson_clicked();

private:
    Ui::AddPersonForm *ui;
};

#endif // ADDPERSONFORM_H
