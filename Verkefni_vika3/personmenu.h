#ifndef PERSONMENU_H
#define PERSONMENU_H

#include <QWidget>
#include <string>
#include <vector>
#include <person.h>
#include <domainlayer.h>
#include <algorithm>
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
    //Sýnir vector með fólki
    void displayPersonVector(vector <person> perVec);
    //Sækir nýjan lista úr gagnagrunni
    void Refresh();
    //Finnur úr lista persónur og birtir, hægt að leita eftir hlutstreng
    int findPersonInVector(vector<person> personVector, string nameOfSelected);
    //Athugar hvort að slegið sé inn lögleg færsla
    bool validateInput();

    //Sækir persónur
    int getPersonID() const;
    //Gefur persónu gildi
    void setPersonID(int value);

    //Föll sem tengjast mús, hægt að draga glugga til og frá
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private slots:
    //Takkar og töflur
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
    DomainLayer domain;
    PersonTable persontable;
    int personID;

    //Hlutir sem tengjast mús
    QPoint mLastMousePosition;
    bool mMoving;

};

#endif // PERSONMENU_H
