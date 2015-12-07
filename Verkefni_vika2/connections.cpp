#include "connections.h"

Connections::Connections(string personname,string computername)
{
    personName = personname;
    computerName = computername;
}

int Connections::getID()
{
  return ID;
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

