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

        void addPersonToDB(person per);
        void addComputerToDB(Computer comp);
        void addConnectionToDB (Connections connection);
        void removeConnectionFromDB(int id);
        void removePersonFromDB(int id);
        void removeComputerFromDB(int id);
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
    private:
        QSqlDatabase db;



};

#endif // DATALAYER_H
