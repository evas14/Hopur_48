#ifndef CONNECTIONS_H
#define CONNECTIONS_H
#include <string>
using namespace std;

/*Class Connections
 * Hefur 5 "private" breytur
 * int ID er auðkenni sem hver ný tenging fær
*/
class Connections
{
private:
    int ID;
    int perID;
    int comID;
    string personName;
    string computerName;

public:
    //Smiður sem frumstillir breytur
    Connections(string personname,string computername);
    //Smiður sem frumstillir breytur
    Connections(int perid,int comid);

    //Sækir ID
    int getID();
    int getPerID();
    int getComID();

    //Föll sem sækja nöfn
    string getPersonName();
    string getComputerName();
    //Föll sem stilla ID
    void setID(int id); 
    void setPerID(int id);
    void setComID(int id);
};

#endif // CONNECTIONS_H
