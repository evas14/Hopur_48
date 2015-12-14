#ifndef CONNECTIONSMENU_H
#define CONNECTIONSMENU_H

#include <QWidget>
#include <connections.h>
#include <domainlayer.h>
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

private:
    Ui::ConnectionsMenu *ui;
};

#endif // CONNECTIONSMENU_H
