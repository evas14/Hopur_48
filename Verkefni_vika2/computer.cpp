#include "computer.h"

Computer::Computer(string Name,int yearbuilt,string computertype,bool wasbuilt)
{
    name = Name;
    yearBuilt = yearbuilt;
    computerType = computertype;
    wasBuilt = wasbuilt;

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

