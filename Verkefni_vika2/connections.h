#ifndef CONNECTIONS_H
#define CONNECTIONS_H
#include <string>
using namespace std;


class Connections
{
private:
    int ID;
    string personName;
    string computerName;
public:
    Connections(string personname,string computername);
    int getID();
    string getPersonName();
    string getComputerName();
    void setID(int id);
};

#endif // CONNECTIONS_H
