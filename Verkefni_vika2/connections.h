#ifndef CONNECTIONS_H
#define CONNECTIONS_H


class Connections
{
private:
    int ID;
    int personID;
    int computerID;
public:
    Connections(int personid,int computerid);
    int getID();
    int getPersonID();
    int getComputerID();
    void setID(int id);
};

#endif // CONNECTIONS_H
