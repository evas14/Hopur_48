#ifndef DATALAYER_H
#define DATALAYER_H
#include <vector>
#include <fstream>
#include <person.h>
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
        void addPerson(person per);
        vector<person> pullPerson();
    private:
        QSqlDatabase db;



};

#endif // DATALAYER_H
