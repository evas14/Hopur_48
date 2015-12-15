#ifndef ADDCOMPUTERFORM_H
#define ADDCOMPUTERFORM_H

#include <QWidget>
#include <string>
#include <domainlayer.h>

using namespace std;

namespace Ui {
class AddComputerForm;
}

class AddComputerForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddComputerForm(QWidget *parent = 0);
    ~AddComputerForm();

private slots:
    void on_pushButtonAddComputer_clicked();

private:
    Ui::AddComputerForm *ui;
};

#endif // ADDCOMPUTERFORM_H
