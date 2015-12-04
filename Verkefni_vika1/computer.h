#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>

using namespace std;


class Computer
{
private:
    string Name;
    int YearBuilt;
    string ComputerType;
    bool WasBuilt;

public:
    Computer(string name,int yearbuilt,string computertype,bool wasbuilt);
    string GetName();
    int GetYearBuilt();
    string GetComputerType();
    bool GetWasBuilt();
};

#endif // COMPUTER_H
