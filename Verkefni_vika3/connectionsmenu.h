#ifndef CONNECTIONSMENU_H
#define CONNECTIONSMENU_H

#include <QWidget>
#include <connections.h>
#include <domainlayer.h>
#include <addconnectionform.h>
#include <vector>
#include <person.h>
#include <computer.h>

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
    void displayConnectionsVectorInTable(vector <Connections> connectionsVector);
    void refresh();

private slots:
    void fillComboBoxConnectionID();

    void on_pushButtonRemoveConnection_clicked();

    void on_commandLinkButtonAddNewConnection_clicked();

private:
    Ui::ConnectionsMenu *ui;
    AddConnectionForm addconnectionform;

};


#endif // CONNECTIONSMENU_H
