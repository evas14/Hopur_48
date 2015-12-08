#ifndef DATALAYER_H
#define DATALAYER_H
#include <vector>
#include <fstream>
#include <person.h>
#include <computer.h>
#include <connections.h>
#include <ui.h>
#include <string>
#include <iostream>
#include <sstream>
#include <Qtsql>
#include <Qtsql/QSqlDatabase>
#include <QSqlQuery>
#include <QCoreApplication>

using namespace std;

class Datalayer
{
public:
    Datalayer();

    bool addPersonToDB(person per);
    bool addComputerToDB(Computer comp);
    bool addConnectionToDB (Connections connection);
    bool removeConnectionFromDB(int id);
    bool removePersonFromDB(int id);
    bool removeComputerFromDB(int id);
    void closeDB();

    //Sort föll
    vector<person>sortPersonByName();
    vector<person>sortPersonByAge();
    vector<Computer>sortComputerByName();
    //Sort eftir id
    vector<person> pullPerson();
    vector<Computer> pullComputer();
    vector<Connections> pullConnections();

    void connectDB();
    void createDB();

private:
    QSqlDatabase db;



};

#endif // DATALAYER_H
