#ifndef PERSONTABLE_H
#define PERSONTABLE_H

#include <QWidget>
#include <vector>
#include <person.h>
#include <domainlayer.h>
#include <QMessageBox>
#include <algorithm>

namespace Ui {
class PersonTable;
}

class PersonTable : public QWidget
{
    Q_OBJECT

public:
    explicit PersonTable(QWidget *parent = 0);
    ~PersonTable();
    void refresh();
    void displayPersonVectorInTable(vector<person> personVector);

private slots:
    void on_commandLinkButtonRefresh_clicked();

private:
    Ui::PersonTable *ui;
    DomainLayer domain;
};

#endif // PERSONTABLE_H