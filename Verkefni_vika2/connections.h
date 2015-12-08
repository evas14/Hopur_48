#ifndef CONNECTIONS_H
#define CONNECTIONS_H
#include <string>
using namespace std;


class Connections
{
private:
    int ID;
    int perID;
    int comID;
    string personName;
    string computerName;

public:
    Connections(string personname,string computername);
    Connections(int perid,int comid);
    int getID();
    int getPerID();
    int getComID();

    string getPersonName();
    string getComputerName();
    void setID(int id);
    void setPerID(int id);
    void setComID(int id);
};

#endif // CONNECTIONS_H
