#ifndef PERSONMENU_H
#define PERSONMENU_H

#include <QWidget>
#include <string>
#include <vector>
#include <person.h>
#include <domainlayer.h>
#include <algorithm>
#include <addpersonform.h>
#include <editperson.h>
#include <QMessageBox>

using namespace std;

namespace Ui {
class PersonMenu;
}

class PersonMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PersonMenu(QWidget *parent = 0);
    ~PersonMenu();
    void displayPersonVector(vector <person> perVec);
    void Refresh();


private slots:
    void on_lineEditSearch_textChanged(const QString &arg1);

    void on_listWidgetPerson_clicked(const QModelIndex &index);

    void on_listWidgetPerson_activated(const QModelIndex &index);

    void on_commandLinkButtonRemovePerson_clicked();

    int findPersonInVector(vector<person> personVector, string nameOfSelected);

    void on_commandLinkButtonAddNewPerson_clicked();

    void on_commandLinkButtonEditPerson_clicked();

    void on_commandLinkButtonShowTable_clicked();



private:
    Ui::PersonMenu *ui;
    AddPersonForm addpersonform;
    EditPerson editpersonform;


};

#endif // PERSONMENU_H
