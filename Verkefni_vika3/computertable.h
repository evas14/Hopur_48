#ifndef COMPUTERTABLE_H
#define COMPUTERTABLE_H

#include <QWidget>
#include <vector>
#include <computer.h>
#include <domainlayer.h>
#include <QMessageBox>
#include <algorithm>
#include <QMoveEvent>

using namespace std;

namespace Ui {
class ComputerTable;
}

class ComputerTable : public QWidget
{
    Q_OBJECT

public:
    explicit ComputerTable(QWidget *parent = 0);
    ~ComputerTable();
    void refresh();
    void displayComputerVectorInTable(vector<Computer> computerVector);

    //mouse functions
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private slots:
    void on_commandLinkButtonRefresh_clicked();

    void on_ButtonClose_clicked();

private:
    Ui::ComputerTable *ui;
    DomainLayer domain;

    //mouse variables
    QPoint mLastMousePosition;
    bool mMoving;
};

#endif // COMPUTERTABLE_H
