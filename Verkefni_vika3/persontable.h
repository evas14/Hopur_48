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
    void refresh();
    void displayPersonVectorInTable(vector<person> personVector);

    //mouse events
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private slots:
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
