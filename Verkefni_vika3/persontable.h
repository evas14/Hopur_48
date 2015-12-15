#ifndef PERSONTABLE_H
#define PERSONTABLE_H

#include <QWidget>
#include <vector>
#include <person.h>
#include <domainlayer.h>
#include <QMessageBox>
#include <algorithm>
#include <QMoveEvent>

namespace Ui {
class PersonTable;
}

class PersonTable : public QWidget
{
    Q_OBJECT

public:
    explicit PersonTable(QWidget *parent = 0);
    ~PersonTable();
    //refreshar ef breytingar hafa orðið
    void refresh();
    //Tekur hvert stak fyrir sig úr vector og setur í lista
    void displayPersonVectorInTable(vector<person> personVector);

    //Tengjast færslu á músabendli(gerir glugga færanlega)
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private slots:
    //útfærsla á tökkum
    void on_commandLinkButtonRefresh_clicked();

    void on_ButtonClose_clicked();

private:
    Ui::PersonTable *ui;
    DomainLayer domain;

    //mouse variables
    QPoint mLastMousePosition;
    bool mMoving;
};

#endif // PERSONTABLE_H
