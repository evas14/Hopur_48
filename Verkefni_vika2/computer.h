#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>
#include <person.h>
#include <computer.h>

using namespace std;

/*Class Computer
 * Hefur 5 "private" breytur
 * int ID er auðkenni sem hver ný persóna fær
*/
class Computer
{
private:
    int id;
    string name;
    string computerType;
    int yearBuilt;
    bool wasBuilt;

public:
    //Smiður sem frumstillir breytur
    Computer(string Name,string computertype,int yearbuilt,bool wasbuilt);
    //Sækir ID
    int getID();
    //Sækir árið sem tölva er byggð
    int getYearBuilt();
    //Sækir nafn á tölvu
    string getName();
    //Sækir gerð tölvu
    string getComputerType();
    //Athugar hvort tölva hafi verið smíðuð
    bool getWasBuilt();
    //Stillir ID
    void setID(int ID);
};

#endif // COMPUTER_H
