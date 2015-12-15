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
    //sækir alla töfluna
    void refresh();
    //setur allar upplýsingar úr vector og setur í töflu
    void displayComputerVectorInTable(vector<Computer> computerVector);

    //föll sem tengjast færslu á músabendli(gerir gluggan færanlegan)
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private slots:
    //kallar á refresh fallið
    void on_commandLinkButtonRefresh_clicked();

    //Close takkin.
    void on_ButtonClose_clicked();

private:
    Ui::ComputerTable *ui;
    //býr til tilvik af DomainLayer
    DomainLayer domain;

    //Breytur fyrir mús
    QPoint mLastMousePosition;
    bool mMoving;
};

#endif // COMPUTERTABLE_H
