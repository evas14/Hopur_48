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
#include <ui.h>
#include <datalayer.h>
#include <algorithm>

using namespace std;


class DomainLayer
{
public:
    DomainLayer();
    //Leitar föll
    void searchPersonByName(string searchquery);
    void searchComputerByName(string searchquery);

    //Föll sem eyða úr gagnagrunni
    void removePerson();
    void removeComputer();
    void removeConnection();

    //Föll sem raða
    void sortPersonVectorByID(string sortType);
    void sortPersonVectorByName(string sortType);
    void sortPersonVectorByAge(string sortType);
    void sortComputerVectorByID(string sortType);
    void sortComputerVectorByName(string sortType);
    void sortConnectionsVectorByID();

    //Föll sem bæta við gagnagrunn
    void addPerson();
    void addComputer();
    void addConnection();


    //Athugar hvort stak sé til í vector
    bool vectorHasPerson(vector<person>per, int id);
    bool vectorHasComputer(vector<Computer> comp,int id);
    bool vectorHasConnection(vector<Connections> con,int id);

    //Nær í núverandi ár og skilar sem int tölu
    int currentYear();
};

#endif // DOMAINLAYER_H
