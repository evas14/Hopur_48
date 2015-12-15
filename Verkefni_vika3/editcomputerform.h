#ifndef EDITCOMPUTERFORM_H
#define EDITCOMPUTERFORM_H

#include <QWidget>
#include "computer.h"
#include "domainlayer.h"
#include "string"
#include "vector"

namespace Ui {
class EditComputerForm;
}

class EditComputerForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditComputerForm(QWidget *parent = 0);
    ~EditComputerForm();
    void fillInfo(int ID);

    int getComputerID() const;
    void setComputerID(int value);

private slots:
    void on_checkBoxWasBuilt_clicked();

    void on_pushButtonUpdateComputer_clicked();

private:
    Ui::EditComputerForm *ui;
    int computerID;
};

#endif // EDITCOMPUTERFORM_H
