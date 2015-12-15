#ifndef DOMAINLAYER_H
#define DOMAINLAYER_H
#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <person.h>
#include <computer.h>
#include <connections.h>
#include <fstream>
#include <datalayer.h>
#include <algorithm>

using namespace std;


class DomainLayer
{

private:
    Datalayer datalayer;

public:
    DomainLayer();
    //Leitar föll
    vector<person> searchPersonByName(string searchquery);
    vector<Computer> searchComputerByName(string searchquery);

    //Föll sem eyða úr gagnagrunni
    bool removePerson(int id);
    bool removeComputer(int id);
    bool removeConnection(int id);

    //Föll sem raða
    vector<person> sortPersonVectorByID(string sortType);
    vector<person>sortPersonVectorByName(string sortType);
    vector<person> sortPersonVectorByAge(string sortType);
    vector<Computer> sortComputerVectorByID(string sortType);
    vector<Computer> sortComputerVectorByName(string sortType);
    vector<Connections> sortConnectionsVectorByID();

    //Föll sem bæta við gagnagrunn
    bool addPerson(string name,string gender,int yearofbirth,int yearofdeath);
    bool addComputer(string name, string computerType, int yearBuilt, bool wasBuilt);
    void addConnection(int personID,int computerID);

    bool updateComputer(int id,string name,string computerType, int yearBuilt, bool wasBuilt);
    bool updatePerson(int id,string name,string gender,int yearofbirth,int yearofdeath);


    //Athugar hvort stak sé til í vector
    bool vectorHasPerson(vector<person>per, int id);
    bool vectorHasComputer(vector<Computer> comp,int id);
    bool vectorHasConnection(vector<Connections> con,int id);

    //Nær í núverandi ár og skilar sem int tölu
    int currentYear();
};

#endif // DOMAINLAYER_H
