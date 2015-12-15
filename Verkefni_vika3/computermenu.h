#ifndef COMPUTERMENU_H
#define COMPUTERMENU_H

#include <QWidget>
#include <vector>
#include <computer.h>
#include <domainlayer.h>
#include <QMessageBox>
#include <algorithm>
#include <computertable.h>
#include <QMoveEvent>


using namespace std;

namespace Ui {
class ComputerMenu;
}

class ComputerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ComputerMenu(QWidget *parent = 0);
    ~ComputerMenu();
    //Tekur hvert stak fyrir sig úr vector og setur í lista
    void displayComputerVector(vector <Computer> compVec);
    //refreshar ef breytingar hafa orðið
    void refresh();
    //Finnur tölvu sem leitað er að
    int findComputerInVector(vector <Computer> computerVector, string nameofSelected);

    //sækir tölvu ID
    int getComputerID() const;
    //breytir gildi tölvu ID
    void setComputerID(int value);

    //Tengjast færslu á músabendli(gerir glugga færanlega)
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);


private slots:
    //útfærlsa á tökkum
    void on_commandLinkButtonAddNewComputer_clicked();

    void on_commandLinkButtonRemoveComputer_clicked();

    void on_commandLinkButtonEditComputer_clicked();

    void on_commandLinkButtonShowTable_clicked();

    void on_lineEditSearchComputer_textChanged(const QString &arg1);

    void on_listWidgetComputer_clicked(const QModelIndex &index);

    void on_checkBoxWasBuilt_clicked();

    void on_ButtonCllose_clicked();

    void on_pushButtonClear_clicked();

private:
    Ui::ComputerMenu *ui;
    DomainLayer domain;
    ComputerTable comptable;
    int computerID;

    //Mouse objects
    QPoint mLastMousePosition;
    bool mMoving;
};

#endif // COMPUTERMENU_H
