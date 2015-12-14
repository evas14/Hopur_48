#include "connections.h"

Connections::Connections(string personname,string computername)
{
    personName = personname;
    computerName = computername;
}
Connections::Connections(int perid,int comid)
{
    perID = perid;
    comID = comid;
}

int Connections::getID()
{
    return ID;
}

int Connections::getPerID()
{
    return perID;
}

int Connections::getComID()
{
    return comID;
}

string Connections::getPersonName()
{
    return personName;
}

string Connections::getComputerName()
{
    return computerName;
}

void Connections ::setID(int id)
{
    ID = id;
}

void Connections:: setPerID(int id)
{
    perID = id;
}

void Connections:: setComID(int id)
{
    comID = id;
}

