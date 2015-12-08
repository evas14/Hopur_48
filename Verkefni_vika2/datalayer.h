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
    //Sendir domainlayer hvort tekist hafi að bæta við
    bool addPersonToDB(person per);
    bool addComputerToDB(Computer comp);
    bool addConnectionToDB (Connections connection);

    //Sendir domainlayer hvort tekist hafi að eyða
    bool removeConnectionFromDB(int id);
    bool removeComputerFromDB(int id);
    bool removePersonFromDB(int id);

    //lokar gagnagrunni
    void closeDB();

    //Sort föll
    vector<person>sortPersonByName();
    vector<person>sortPersonByAge();
    vector<Computer>sortComputerByName();
    //Sækir eftir id
    vector<person> pullPerson();
    vector<Computer> pullComputer();
    vector<Connections> pullConnections();

    //Tengist gagnagrunni
    void connectDB();
    //Býr til gagnagrunn
    void createDB();

private:
    QSqlDatabase db;



};

#endif // DATALAYER_H
