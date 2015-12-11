#ifndef PERSONMENU_H
#define PERSONMENU_H

#include <QWidget>
#include <string>
#include <vector>
#include <person.h>
#include <domainlayer.h>
#include <algorithm>

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


private slots:
    void on_lineEditSearch_textChanged(const QString &arg1);

    void on_listWidgetPerson_clicked(const QModelIndex &index);

    void on_listWidgetPerson_activated(const QModelIndex &index);

private:
    Ui::PersonMenu *ui;
};

#endif // PERSONMENU_H
