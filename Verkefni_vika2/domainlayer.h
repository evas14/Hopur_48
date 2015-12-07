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

    void searchPersonByName(string searchquery);
    void removePerson(vector <person> &personvector);

    //Sort föll
    void sortPersonVectorByID(string sortType);
    void sortPersonVectorByName(string sortType);
    void sortPersonVectorByAge(string sortType);
    void sortComputerVectorByID(string sortType);
    void sortComputerVectorByName(string sortType);


    //Vector Föll
    vector<person> updatePersonVector();
    vector<Computer>updateComputerVector();
    vector<Connections>updateConnectionsVector();

    //Add Föll
    void addPerson();
    vector<Computer> addComputer(vector<person>computerVector);
    vector<Connections> addConnection(vector<person>connectionsVector);

    //Athugar hvort stak sé til í vector og skilar
    //staðsetningu á stakinu. Ef stakið er ekki til skila
    //föllin -1
    int vectorHasPerson(vector<person>per, int id);
    int vectorHasComputer(vector<Computer> comp,int id);

    //Nær í núverandi ár og skilar sem int tölu
    int currentYear();
};

#endif // DOMAINLAYER_H
