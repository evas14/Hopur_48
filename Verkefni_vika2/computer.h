#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>
#include <person.h>
#include <computer.h>

using namespace std;


class Computer
{
private:
    int id;
    string name;
    string computerType;
    int yearBuilt;
    bool wasBuilt;

public:
    Computer(string Name,string computertype,int yearbuilt,bool wasbuilt);
    int getID();
    int getYearBuilt();
    string getName();
    string getComputerType();
    bool getWasBuilt();
    void setID(int ID);
};

#endif // COMPUTER_H
