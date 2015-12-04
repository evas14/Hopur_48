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
#include <computer.h>

using namespace std;


//void föll


//les allan vectorin og kallar á displayperson fyrir öll stökin í vectornum
void readPersonVector(vector <person> per);
void readComputerVector(vector <Computer> comp);

void search(string searchquery,vector<person> personvector);
void removeperson(vector <person> &personvector);
void updatefile(vector<person> per);
void sortvectorbyname(vector<person>personvector);
void sortvectorbynameReverse(vector<person> personvector);

//int föll
int vectorHasPerson(vector<person>per, int id);
int vectorHasComputer(int id);
int currentyear();



//vector föll
/* addpersontovector
 * Tekur inn: vector af taginu person og bætir við persónu í vectorinn
 * Skilar: vector af taginu person
*/
vector<person> addpersontovector(vector<person>personvector);

//bool föll
bool isgreater(person per1,person per2)
{
    return per1.getName() < per2.getName();
}

//string föll
string readsearchquery();

void updatefile(vector<person> per)
{
    //Datalayer writer;
    //writer.AddData(per);
}

int currentyear()
{
    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );
    localTime = localtime( &currentTime );
    int currentYear = localTime->tm_year + 1900;

    return currentYear;
}

//Skilar vector í öfugri stafrófsröð
void sortvectorbynameReverse(vector<person> personvector)
{

    //sort(personvector.begin(),personvector.end(),isgreater);
    reverse(personvector.begin(),personvector.end());

    readPersonVector(personvector);
}

//Skilar vector í stafrófsröð
void sortvectorbyname(vector<person>personvector)
{

    //sort(personvector.begin(),personvector.end(),isgreater);
    readPersonVector(personvector);

}

//removeperson notar þetta fall til að athuga hvort manneskjan
//sé til
int vectorHasPerson(vector <person> per,int id)
{
    for(unsigned int i = 0; i < per.size(); i++)
    {
        if(per.at(i).getID() == id)
        {
            return i;
        }
    }

    return -1;

}

int vectorHasComputer(vector <Computer> comp,int id)
{
    for(unsigned int i = 0; i < comp.size(); i++)
    {
        if(comp.at(i).getID() == id)
        {
            return i;
        }
    }

    return -1;

}



//fjarlægir einstakling úr vector
void removeperson(vector <person> &personvector)
{
    UI toScreen;

    int id = 0,locationinvector=0;
    readPersonVector(personvector);
    toScreen.displayMessage("Enter ID of the person you want to remove: ");
    cin >> id;
    if(vectorHasPerson(personvector,id) != -1)
    {
        locationinvector = vectorHasPerson(personvector,id);
        personvector.erase(personvector.begin()+locationinvector);
        updatefile(personvector);
    }

    else
    {
        UI error;
        error.displayError("Error ID not found!");
    }

}


void readComputerVector(vector <Computer> comp)
{
    UI toScreen;

    for(unsigned int i = 0; i < comp.size(); i++)
    {
        Computer currentcomputer = comp.at(i);
        toScreen.displayComputer(currentcomputer);

    }

}



//Les persónur úr vector til og sendir til UI til
//að prenta út á skjá
void readPersonVector(vector <person> per)
{
    UI toScreen;
    for(unsigned int i = 0; i < per.size(); i++)
    {
        person currentperson = per.at(i);
        toScreen.displayPerson(currentperson);

    }
}

//Bætir persónu við vector
vector<person> addpersontovector(vector<person>personvector)
{
    UI toScreen;
    string name;
    string gender;
    int yearofbirth = 0;
    int yearofdeath = 0;

    toScreen.displayInput("Name: ");
    cin.ignore();
    std::getline(std::cin, name);
    name[0] = toupper(name[0]);

    while(true)
    {
        //Athugar hvort slegið sé inn tölustafur í nafn
        if(name.find_first_of("0123456789")!=std::string::npos)
        {
            UI error;
            error.displayError("Error, name may not contain numbers!");
            toScreen.displayInput("Name: ");
            cin.ignore();
            std::getline(std::cin, name);
            name[0] = toupper(name[0]);

        }

        else
        {
            break;
        }

    }



    toScreen.displayInput("Gender: ");
    cin >> gender;
    gender[0] = toupper(gender[0]);

    while(true)
    {
        if(gender == "Male" || gender == "Female")
        {
            break;
        }
        UI error;
        error.displayError("Error, please enter a valid Gender. Male or Female");
        cin >> gender;
        gender[0] = toupper(gender[0]);

    }



    toScreen.displayInput("Year of birth: ");
    cin >> yearofbirth;
    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    while(cin.fail() || yearofbirth < 999 || yearofbirth > currentyear())
    {
        UI error;
        error.displayError("Error, please enter a valid year");
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearofbirth;
    }

    cout << "Year of death, if the person is still alive please enter 0" << endl;
    cin >> yearofdeath;
    //Athugar hvort slegið sé inn tölustafur, að slegið sé inn 4 stafa ártal, að dánarár sé ekki
    //á undan fæðingarári og að dánarár sé ekki stærra en árið í ár.
    while(cin.fail() || (yearofdeath > 0 && yearofdeath < 999) || (yearofdeath > 0 && yearofdeath < yearofbirth) || yearofdeath > currentyear())
    {
        UI error;
        error.displayError("Error, please enter a valid year");
        cin.clear();
        cin.ignore(256, '\n');
        cin >> yearofdeath;
    }

    person per(name,gender,yearofbirth,yearofdeath);
    per.setID(personvector.size()+1);

    personvector.push_back(per);
    Datalayer writer;
    writer.addPerson(per);
    return personvector;
}

//Leita að persónu í vector
void search(string searchquery, vector<person> personvector)
{
    int queryfoundcounter = 0;
    UI toScreen;


  for(unsigned int i = 0; i < personvector.size(); i++)
  {

      if (personvector.at(i).getName().find(searchquery) != string::npos)
      {
          queryfoundcounter++;
          toScreen.displayPerson(personvector.at(i));
      }
  }

  if(queryfoundcounter == 0)
  {
      UI error;
      error.displayError("No match for: " + searchquery);
  }
}


int main()
{
    string searchquery;
    Datalayer reader;
    vector<person> personvector = reader.pullPerson();
    vector<Computer> computervector = reader.pullComputer();
    UI userInterface;

    while(true)
    {
        switch(userInterface.mainMenu())
        {
            case 1:
                personvector = addpersontovector(personvector);
            break;
            case 2:
                //computervector = addComputerToVector(computervector);
            break;
            case 3:
                //connectionvector = addConnectionToVector(connectionvector);
            break;
            case 4:
                sortvectorbyname(personvector);
            break;

            case 5:
            sortvectorbynameReverse(personvector);
            break;

            case 6:

                searchquery = userInterface.readSearchQuery();
                search(searchquery, personvector);
            break;

            case 7:
                 removeperson(personvector);
            break;
        }
    }


    return 0;
}



