#ifndef COMPUTERTABLEFORM_H
#define COMPUTERTABLEFORM_H

#include <QWidget>

namespace Ui {
class ComputerTableForm;
}

class ComputerTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit ComputerTableForm(QWidget *parent = 0);
    ~ComputerTableForm();

private:
    Ui::ComputerTableForm *ui;
};

#endif // COMPUTERTABLEFORM_H
