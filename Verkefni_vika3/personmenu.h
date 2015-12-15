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
#include <persontable.h>
#include <QMessageBox>
#include<QMoveEvent>

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
    int findPersonInVector(vector<person> personVector, string nameOfSelected);
    bool validateInput();

    int getPersonID() const;
    void setPersonID(int value);

    //Mouse event
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private slots:
    void on_lineEditSearch_textChanged(const QString &arg1);

    void on_listWidgetPerson_clicked(const QModelIndex &index);

    void on_listWidgetPerson_activated(const QModelIndex &index);

    void on_commandLinkButtonRemovePerson_clicked();

    void on_commandLinkButtonShowTable_clicked();

    void on_pushButtonClear_clicked();

    void on_checkBoxPersonAlive_clicked();

    void on_pushButton_clicked();

    void on_commandLinkButtonAddNewPerson_clicked();

    void on_commandLinkButtonUpdatePerson_clicked();

private:
    Ui::PersonMenu *ui;
    AddPersonForm addpersonform;
    EditPerson editpersonform;
    DomainLayer domain;
    PersonTable persontable;
    int personID;

    //Mouse Objects
    QPoint mLastMousePosition;
    bool mMoving;

};

#endif // PERSONMENU_H
