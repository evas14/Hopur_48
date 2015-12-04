#include "connections.h"

Connections::Connections(int personid,int computerid)
{
    personID = personid;
    computerID = computerid;
}

int Connections::getID()
{
  return ID;
}

int Connections::getPersonID()
{
    return personID;
}

int Connections::getComputerID()
{
    return computerID;
}

void Connections ::setID(int id)
{
    ID = id;
}

