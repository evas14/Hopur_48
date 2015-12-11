#ifndef DISPLAYFORM_H
#define DISPLAYFORM_H

#include <QWidget>
#include <person.h>
#include <domainlayer.h>
#include <connections.h>
#include <string>
#include <vector>

namespace Ui {
class DisplayForm;
}

class DisplayForm : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayForm(QWidget *parent = 0);
    ~DisplayForm();
    void displayPersonVectorInTable(vector <person> perVec);
    void displayComputerVectorInTable(vector<Computer> compVec);
    void displayConnectionsVectorInTable(vector<Connections> conVec);

private slots:
    void on_pushButtonPersonSort_clicked();

    void on_pushButtonComputerSort_clicked();

    void on_pushButtonConnectionsSort_clicked();

    void on_radioButtonAlphabeticalSort_clicked();

private:
    Ui::DisplayForm *ui;
};

#endif // DISPLAYFORM_H
