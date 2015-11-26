#include <iostream>
#include <vector>
#include <string>

using namespace std;

class person
{

  private:
      int ID;
      string Name;
      string Gender;
      int YearOfbirth;
      int YearOfdeath;
  public:
    person(string name,string gender,int yearofbirth,int yearofdeath);
    int getID();
    string getName();
    string getGender();
    int getYearOfbirth();
    int getYearOfdeath();




};

int person::getID()
{
    return ID;
}

int person::getYearOfbirth()
{
    return YearOfbirth;
}

int person::getYearOfdeath()
{
    return YearOfdeath;
}

string person::getName()
{
    return Name;
}

string person::getGender()
{
    return Gender;
}

person::person(string name,string gender,int yearofbirth,int yearofdeath)
{
    ID = 0;
    Name = name;
    Gender = gender;
    YearOfbirth = yearofbirth;
    YearOfdeath = yearofdeath;

}



void displayperson( person per)
{
    cout <<"ID: "<< per.getID() << endl;
    cout <<"Name: " << per.getName() << endl;
    cout <<"Gender: " << per.getGender() << endl;
    cout <<"Year of birth: " << per.getYearOfbirth() << endl;
    cout <<"Year of death: " << per.getYearOfdeath()<< endl;
}

void readvector(vector <person> per)
{
    for(int i = 0; i < per.size(); i++)
    {
        cout << "----------------------------------------"<<endl;
        person currentperson = per.at(i);
        displayperson(currentperson);
        cout << "----------------------------------------"<<endl;

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

    cout << "Gender: ";
    cin >> gender;

    cout << "Year of birth: ";
    cin >> yearofbirth;

    cout << "Year of death: ";
    cin >> yearofdeath;

    person per(name,gender,yearofbirth,yearofdeath);
    personvector.push_back(per);
    return personvector;

}

int main()
{
    int choice=0;
    vector<person> personvector;
    //person number1("John Maxwell","Male",1964,2013);
   // personvector.push_back(number1);

    cout << "1.Enter in new Computer Scientist"<< endl;
    cout << "2.Display people"<< endl;
    cout << "3.Quit"<< endl;
    cin >> choice;

    while(choice != 3)
    {

        switch(choice)
        {
            case 1:
                personvector = addpersontovector(personvector);

            break;

            case 2:
                readvector(personvector);
            break;
        }

        cout << "1.Enter in new Computer Scientist"<< endl;
        cout << "2.Display all people"<< endl;
        cout << "3.Quit"<< endl;
        cin >> choice;

    }


    return 0;
}
