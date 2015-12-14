#ifndef EDITPERSON_H
#define EDITPERSON_H

#include <QWidget>
#include "person.h"
#include "domainlayer.h"
#include "string"
#include "vector"

using namespace std;

namespace Ui {
class EditPerson;
}

class EditPerson : public QWidget
{
    Q_OBJECT

public:
    explicit EditPerson(QWidget *parent = 0);
    ~EditPerson();
    void fillInfo(int ID);


private slots:
    void on_checkBoxPersonAlive_clicked();

    void on_pushButton_clicked();

    void on_pushButtonPersonUpdate_clicked();

private:
    Ui::EditPerson *ui;

};

#endif // EDITPERSON_H
