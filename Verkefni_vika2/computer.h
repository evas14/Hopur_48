#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>

using namespace std;


class Computer
{
private:
    int id;
    string name;
    int yearBuilt;
    string computerType;
    bool wasBuilt;

public:
    Computer(string Name,int yearbuilt,string computertype,bool wasbuilt);
    int getID();
    string getName();
    int getYearBuilt();
    string getComputerType();
    bool getWasBuilt();
};

#endif // COMPUTER_H
