#include "computer.h"

Computer::Computer(string Name,string computertype,int yearbuilt,bool wasbuilt)
{
    name = Name;
    yearBuilt = yearbuilt;
    computerType = computertype;
    wasBuilt = wasbuilt;

}

void Computer:: setID(int ID)
{
    id = ID;
}

int Computer::getID()
{
    return id;
}

string Computer::getName()
{
    return name;
}

int Computer::getYearBuilt()
{
    return yearBuilt;
}

string Computer::getComputerType()
{
    return computerType;
}
bool Computer::getWasBuilt()
{
    return wasBuilt;
}

