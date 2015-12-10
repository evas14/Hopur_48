#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <ctime>
using namespace std;

/*Class person
 * Hefur 6 "private" breytur
 * int ID er auðkenni sem hver ný persóna fær
*/
class person
{
private:
    int ID;
    string Name;
    string Gender;
    int YearOfbirth;
    int YearOfdeath;
    int Age;

public:
    //Smiður sem frumstillir breytur
    person(string name, string gender, int yearofbirth, int yearofdeath);
    //Föll sem sækja breytur
    int getID();
    string getName();
    string getGender();
    int getYearOfbirth();
    int getYearOfdeath();
    int getAge();
    void setID(int id);
};

#endif // PERSON_H
