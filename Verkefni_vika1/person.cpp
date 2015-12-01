#include "person.h"

int person::getAge()
{
    return Age;
}

void person::setID(int id)
{
    ID = id;
}

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

//Reiknar út aldur
person::person(string name, string gender, int yearofbirth, int yearofdeath)
{
    time_t currentTime;
    struct tm * localTime;

    time( &currentTime );
    localTime = localtime( &currentTime );
    int currentYear = localTime-> tm_year + 1900;

    ID = 0;
    Name = name;
    Gender = gender;
    YearOfbirth = yearofbirth;
    YearOfdeath = yearofdeath;

    if(yearofdeath == 0)
    {
        Age = currentYear - yearofbirth;
    }else
    {
       Age = yearofdeath - yearofbirth;
    }
}
