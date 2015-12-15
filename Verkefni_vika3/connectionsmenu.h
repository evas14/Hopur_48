#ifndef CONNECTIONSMENU_H
#define CONNECTIONSMENU_H

#include <QWidget>
#include <connections.h>
#include <domainlayer.h>
#include <addconnectionform.h>
#include <vector>
#include <person.h>
#include <computer.h>
#include <QMessageBox>
#include <QMoveEvent>

using namespace std;

namespace Ui {
class ConnectionsMenu;
}

class ConnectionsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionsMenu(QWidget *parent = 0);
    ~ConnectionsMenu();
    //birtir allar upplýsingar um tengingar í töflunni vinstra megin
    void displayConnectionsVectorInTable(vector <Connections> connectionsVector);
    //birtir alla scientists í listanum vinstra megin
    void displayPersonVector(vector <person> perVec);
    //birtir allar tölvur í listanum hægra megin
    void displayComputerVector(vector <Computer> compVec);
    //finnur valda persónu í vectornum og skilar staðsetningu á persónunni í þeim vector
    int findPersonInVector(vector<person> personVector, string nameOfSelected);
    //sama og með persónur
    int findComputerInVector(vector <Computer> computerVector, string nameOfSelected);
    void refresh();

    //Mouse functions
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);


private slots:
    void fillComboBoxConnectionID();

    void on_commandLinkButtonAddNewConnection_clicked();

    void on_pushButtonMakeConnection_clicked();

    void on_commandLinkButtonRemoveConnection_clicked();

    void on_pushButtonRefresh_clicked();

    void on_ButtonClose_clicked();

private:
    Ui::ConnectionsMenu *ui;
    AddConnectionForm addconnectionform;
    DomainLayer domain;

    //mouse variables
    QPoint mLastMousePosition;
    bool mMoving;

};


#endif // CONNECTIONSMENU_H
