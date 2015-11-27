#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <person.h>
#include <fstream>
#include <ui.h>

using namespace std;


//void föll
void displayperson(person per);
void readvector(vector <person> per);
void search(string searchquery,vector<person> personvector);

//vector föll
/* addpersontovector
 * Tekur inn: vector af taginu person og bætir við persónu í vectorinn
 * Skilar: vector af taginu person
 * 
 * 
*/
vector<person> addpersontovector(vector<person>personvector);

//string föll
string readsearchquery();



void displayperson( person per)
{
    cout << "----------------------------------------"<<endl;
    cout << "                WELCOME                 "<<endl;
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
    cout << "----------------------------------------"<<endl;
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

    cout << "Year of death: ";
    cin >> yearofdeath;

    person per(name,gender,yearofbirth,yearofdeath);

    if(personvector.size() == 0)
    {
        per.setID(1);
    }

    else
    {
        per.setID(personvector.size()+1);
    }


    personvector.push_back(per);
    return personvector;

}

void search(string searchquery,vector<person> personvector)
{
    int queryfoundcounter=0;


  for(unsigned int i = 0; i < personvector.size();i++)
  {
      if (personvector.at(i).getName() == searchquery)
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
    /*
    int userselection=0;
    string searchquery;
    vector<person> personvector;

    cout << "----------------------------------------"<<endl;
    cout << "1.Enter in new Computer Scientist"<< endl;
    cout << "2.Display all people"<< endl;
    cout << "3.Search"<<endl;
    cout << "4.Edit" << endl;
    cout << "Any other button to Quit"<< endl;
    cin >> userselection;
    cout << "----------------------------------------"<<endl;

    while(userselection >= 1 && userselection <= 4)
    {

        switch(userselection)
        {
            case 1:
                personvector = addpersontovector(personvector);

            break;
            case 2:

                readvector(personvector);
            break;
            case 3:
                searchquery = readsearchquery();
                search(searchquery,personvector);
            break;
            case 4:
                cout << "This feature is not ready"<<endl;
            break;

        }

        cout << "----------------------------------------"<<endl;
        cout << "1.Enter in new Computer Scientist"<< endl;
        cout << "2.Display all people"<< endl;
        cout << "3.Search"<<endl;
        cout << "4.Edit" << endl;
        cout << "Any other button to Quit"<< endl;
        cin >> userselection;
        cout << "----------------------------------------"<<endl;

    }

    */

    UI userInterface;
    userInterface.mainMenu();

    return 0;
}



