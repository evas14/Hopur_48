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
//skrifar út eina persónu í einu
void displayperson(person per);

//les allan vectorin og kallar á displayperson fyrir öll stökin í vectornum
void readvector(vector <person> per);

void search(string searchquery,vector<person> personvector);
void removeperson(vector <person> &personvector);
void updatefile(vector<person> per);
void sortvectorbyname(vector<person>personvector);
void sortvectorbynameReverse(vector<person> personvector);

//int föll
int vectorhasperson(int id);
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
    Datalayer writer;
    writer.AddData(per);
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

    sort(personvector.begin(),personvector.end(),isgreater);
    reverse(personvector.begin(),personvector.end());

    readvector(personvector);
}

//Skilar vector í stafrófsröð
void sortvectorbyname(vector<person>personvector)
{

    sort(personvector.begin(),personvector.end(),isgreater);
    readvector(personvector);

}

//removeperson notar þetta fall til að athuga hvort manneskjan
//sé til
int vectorhasperson(vector <person> per,int id)
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

//fjarlægir einstakling úr vector
void removeperson(vector <person> &personvector)
{
    int id = 0,locationinvector=0;
    readvector(personvector);
    cout << "Enter ID of the person you want to remove: ";
    cin >> id;
    if(vectorhasperson(personvector,id) != -1)
    {
        locationinvector = vectorhasperson(personvector,id);
        personvector.erase(personvector.begin()+locationinvector);
        updatefile(personvector);
    }

    else
    {
        cout << "Error ID not found!"<<endl;
    }

}


//Skrifar persónu út á skjá
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

//Les persónur úr vector til að setja á skjá
void readvector(vector <person> per)
{
    for(unsigned int i = 0; i < per.size(); i++)
    {
        person currentperson = per.at(i);
        displayperson(currentperson);

    }
}

//Bætir persónu við vector
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

    while(true)
    {
        //Athugar hvort slegið sé inn tölustafur í nafn
        if(name.find_first_of("0123456789")!=std::string::npos)
        {
            cout << "Error, name may not contain numbers!" << endl;
            cout << "Name: ";
            cin.ignore();
            std::getline(std::cin, name);
            name[0] = toupper(name[0]);

        }

        else
        {
            break;
        }

    }



    cout << "Gender: ";
    cin >> gender;
    gender[0] = toupper(gender[0]);

    while(true)
    {
        if(gender == "Male" || gender == "Female")
        {
            break;
        }

        cout << "Error, please enter a valid Gender. Male or Female" << endl;
        cin >> gender;
        gender[0] = toupper(gender[0]);

    }



    cout << "Year of birth: ";
    cin >> yearofbirth;
    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    while(cin.fail() || yearofbirth < 999 || yearofbirth > currentyear())
    {
        cout << "Error, please enter a valid year" << endl;
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

//Leita að persónu í vector
void search(string searchquery, vector<person> personvector)
{
    int queryfoundcounter = 0;


  for(unsigned int i = 0; i < personvector.size(); i++)
  {

      if (personvector.at(i).getName().find(searchquery) != string::npos)
      {
          queryfoundcounter++;
          displayperson(personvector.at(i));
      }
  }

  if(queryfoundcounter == 0)
  {
      cout << "No match for: " << searchquery << endl;
  }
}

//Skilaboð til notanda um leit.
string readsearchquery()
{
    string searchquery;
    cout << "Who are you looking for?: ";
    cin.ignore();
    getline(cin, searchquery);
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
                sortvectorbyname(personvector);
            break;

            case 3:
            sortvectorbynameReverse(personvector);
            break;

            case 4:
                searchquery = readsearchquery();
                search(searchquery, personvector);
            break;

            case 5:
                 removeperson(personvector);
            break;
        }
    }


    return 0;
}



