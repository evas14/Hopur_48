#ifndef COMPUTERTABLE_H
#define COMPUTERTABLE_H

#include <QWidget>
#include <vector>
#include <computer.h>
#include <domainlayer.h>
#include <QMessageBox>
#include <algorithm>

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

private slots:
    void on_commandLinkButtonRefresh_clicked();

private:
    Ui::ComputerTable *ui;
    DomainLayer domain;
};

#endif // COMPUTERTABLE_H
