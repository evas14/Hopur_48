#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <person.h>
#include <datalayer.h>
#include <fstream>
#include <ui.h>
#include <datalayer.h>
#include <algorithm>

using namespace std;


//void föll
void displayperson(person per);
void readvector(vector <person> per);
void search(string searchquery,vector<person> personvector);
void editperson(vector <person> per);
void removeperson(vector <person> per);
bool vectorhasperson(int id);
int currentyear();



//vector föll
/* addpersontovector
 * Tekur inn: vector af taginu person og bætir við persónu í vectorinn
 * Skilar: vector af taginu person
 *
 *
*/
vector<person> addpersontovector(vector<person>personvector);
void sortvectorbyname(vector<person>personvector);
void sortvectorbynameReverse(vector<person> personvector);
bool isgreater(person per1,person per2)
{
    return per1.getName() < per2.getName();
}

//string föll
string readsearchquery();

int currentyear()
{
    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );
    localTime = localtime( &currentTime );
    int currentYear = localTime->tm_year + 1900;

    return currentYear;
}

void sortvectorbynameReverse(vector<person> personvector)
{
    vector <person> reverseperson;
    sort(personvector.begin(),personvector.end(),isgreater);

    for(int i = personvector.size(); i >= 0; i--)
    {
        reverseperson.push_back(personvector.at(i));
    }

    readvector(reverseperson);
}

void sortvectorbyname(vector<person>personvector)
{

    sort(personvector.begin(),personvector.end(),isgreater);
    readvector(personvector);

}

/*
//removeperson notar þetta fall
bool vectorhasperson(vector <person> per,int id)
{
    for(unsigned int i = 0; i < per.size(); i++)
    {

    }

    return true;

}
*/

void removeperson(vector<person> per)
{
    int id = 0;
    readvector(per);
    cout << "Enter ID of the person you want to remove: ";
    cin >> id;




}

void editperson(vector <person> per)
{
    int id = 0;
    readvector(per);
    cout << "Enter ID of the person you want to edit: ";
    cin >> id;

}


void displayperson( person per)
{

    cout << "----------------------------------------"<<endl;
    cout <<"ID: "<< per.getID() << endl;
    cout <<"Name: " << per.getName() << endl;
    cout <<"Gender: " << per.getGender() << endl;
    cout <<"Age: " << per.getAge() << endl;
    cout <<"Year of birth: " << per.getYearOfbirth() << endl;
    if (per.getYearOfdeath() > 0)
    {
        cout <<"Year of death: " << per.getYearOfdeath()<< endl;
    }

}

void readvector(vector <person> per)
{
    for(unsigned int i = 0; i < per.size(); i++)
    {
        person currentperson = per.at(i);
        displayperson(currentperson);

    }
}

vector<person> addpersontovector(vector<person>personvector)
{


    string name;
    string gender;
    int yearofbirth = 0;
    int yearofdeath = 0;

    cout << "Name: ";
    cin.ignore();
    std::getline(std::cin, name);
    name[0] = toupper(name[0]);

    cout << "Gender: ";
    cin >> gender;

    cout << "Year of birth: ";
    cin >> yearofbirth;
    while(cin.fail() || yearofbirth < 999 || yearofbirth > currentyear())
    {
        cout << "Error, please enter a valid year" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearofbirth;
    }

    cout << "Year of death, if the person is still alive please enter 0" << endl;
    cin >> yearofdeath;
    while(cin.fail() || yearofdeath < 999 || yearofdeath < yearofbirth || yearofdeath > currentyear() )
    {
        if(yearofdeath == 0)
        {
            break;
        }
        cout << "Error, please enter a valid year" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearofdeath;
    }

    person per(name,gender,yearofbirth,yearofdeath);
    per.setID(personvector.size()+1);



    personvector.push_back(per);
    Datalayer writer;
    writer.AddData(personvector);
    return personvector;

}

void search(string searchquery,vector<person> personvector)
{
    int queryfoundcounter=0;


  for(unsigned int i = 0; i < personvector.size();i++)
  {

      if (personvector.at(i).getName().find(searchquery) != string::npos)
      {
          queryfoundcounter++;
          displayperson(personvector.at(i));

      }


  }

  if(queryfoundcounter == 0)
  {
      cout << "No match for: " << searchquery<<endl;
  }


}

string readsearchquery()
{
    string searchquery;
    cout << "Who are you looking for?: ";
    cin.ignore();
    getline(cin,searchquery);
    searchquery[0] = toupper(searchquery[0]);

    return searchquery;

}


int main()
{

    string searchquery;
    Datalayer reader;
    vector<person> personvector = reader.PullData();
    UI userInterface;



    while(true)
    {
        switch(userInterface.mainMenu())
        {
            case 1:
                personvector = addpersontovector(personvector);

            break;
            case 2:
            editperson(personvector);


            break;
            case 3:
            searchquery = readsearchquery();
            search(searchquery,personvector);


            break;
            case 4:
                //readvector(personvector);
                //sortvectorbyname(personvector);
                sortvectorbynameReverse(personvector);

            break;
            case 5:

            break;

        }

    }


    return 0;
}



