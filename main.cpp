#include <iostream>

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
    YearOfdeath = yearofbirth;
    YearOfdeath = yearofdeath;

}

void displayperson( person per)
{
    cout << per.getID() << endl;
    cout << per.getName() << endl;
    cout << per.getGender() << endl;
    cout << per.getYearOfbirth() << endl;
    cout << per.getYearOfdeath()<< endl;
}

int main()
{
    person number1("John Maxwell","Male",1964,2013);
    displayperson(number1);


    return 0;
}
