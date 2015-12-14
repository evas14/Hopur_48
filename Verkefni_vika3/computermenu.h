#ifndef COMPUTERMENU_H
#define COMPUTERMENU_H

#include <QWidget>

namespace Ui {
class ComputerMenu;
}

class ComputerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ComputerMenu(QWidget *parent = 0);
    ~ComputerMenu();

private:
    Ui::ComputerMenu *ui;
};

#endif // COMPUTERMENU_H
