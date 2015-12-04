#include "computer.h"

Computer::Computer(string name,int yearbuilt,string computertype,bool wasbuilt)
{
    Name = name;
    YearBuilt = yearbuilt;
    ComputerType = computertype;
    WasBuilt = wasbuilt;

}

string Computer::GetName()
{
    return Name;
}

int Computer::GetYearBuilt()
{
    return YearBuilt;
}

string Computer::GetComputerType()
{
    return ComputerType;
}
bool Computer::GetWasBuilt()
{
    return WasBuilt;
}

