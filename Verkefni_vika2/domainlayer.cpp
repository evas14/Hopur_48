#include "domainlayer.h"

DomainLayer::DomainLayer()
{

}

void DomainLayer::sortPersonVectorByID(string sortType)
{
    UI toScreen;
    Datalayer Reader;
    vector <person>sortedVector = Reader.pullPerson();

    if(sortType == "normal")
    {
       toScreen.displayPersonVector(sortedVector);
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        toScreen.displayPersonVector(sortedVector);
    }

}


//Skilar vector í stafrófsröð
void DomainLayer::sortPersonVectorByName(string sortType)
{
    UI toScreen;
    Datalayer Reader;
    vector <person>sortedVector = Reader.sortPersonByName();


    if(sortType == "normal")
    {
       toScreen.displayPersonVector(sortedVector);
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        toScreen.displayPersonVector(sortedVector);
    }


}

void DomainLayer::sortPersonVectorByAge(string sortType)
{
    UI toScreen;
    Datalayer Reader;
    vector <person>sortedVector = Reader.sortPersonByAge();


    if(sortType == "normal")
    {
       toScreen.displayPersonVector(sortedVector);
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        toScreen.displayPersonVector(sortedVector);
    }


}

void DomainLayer::sortComputerVectorByID(string sortType)
{
    UI toScreen;
    Datalayer Reader;
    vector <Computer> sortedVector = Reader.pullComputer();


    if(sortType == "normal")
    {
       toScreen.displayComputerVector(sortedVector);
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        toScreen.displayComputerVector(sortedVector);
    }


}

void DomainLayer:: sortComputerVectorByName(string sortType)
{
    UI toScreen;
    Datalayer Reader;
    vector <Computer>sortedVector = Reader.sortComputerByName();

    if(sortType == "normal")
    {
       toScreen.displayComputerVector(sortedVector);
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        toScreen.displayComputerVector(sortedVector);
    }



}


//Leita að persónu í vector
void DomainLayer::searchPersonByName(string searchquery)
{
   Datalayer Reader;
   vector<person> personvector = Reader.pullPerson();
   vector<person> queryMatchVector;
   UI toScreen;
   string personName;

   transform(searchquery.begin(), searchquery.end(), searchquery.begin(),::tolower);


  for(unsigned int i = 0; i < personvector.size(); i++)
  {
      personName = personvector.at(i).getName();
      transform(personName.begin(), personName.end(), personName.begin(),::tolower);

      if (personName.find(searchquery) != string::npos)
      {
          queryMatchVector.push_back(personvector.at(i));
      }
  }

  if(queryMatchVector.size() == 0)
  {
      UI error;
      error.displayError("No match for: " + searchquery);
  }

  toScreen.displayPersonVector(queryMatchVector);
}


//Bætir persónu við vector
void DomainLayer::addPerson()
{
    UI toScreen;
    string name;
    string gender;
    int yearofbirth = 0;
    int yearofdeath = 0;

    toScreen.displayInput("Name: ");
    name = toScreen.readStringInputWithSpaces();
    name[0] = toupper(name[0]);

    while(true)
    {
        //Athugar hvort slegið sé inn tölustafur í nafn
        if(name.find_first_of("0123456789")!=std::string::npos)
        {
            UI error;
            error.displayError("Error, name may not contain numbers!");
            toScreen.displayInput("Name: ");
            name = toScreen.readStringInputWithSpaces();
            name[0] = toupper(name[0]);

        }

        else
        {
            break;
        }

    }

    toScreen.displayInput("Gender: ");
    gender = toScreen.readStringInput();
    gender[0] = toupper(gender[0]);

    while(true)
    {
        if(gender == "Male" || gender == "Female")
        {
            break;
        }
        UI error;
        error.displayError("Error, please enter a valid Gender. Male or Female");
        gender = toScreen.readStringInput();
        gender[0] = toupper(gender[0]);

    }

    toScreen.displayInput("Year of birth: ");
    yearofbirth = toScreen.readIntInput();
    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    while(cin.fail() || yearofbirth < 999 || yearofbirth > currentYear())
    {
        UI error;
        error.displayError("Error, please enter a valid year");
        yearofbirth = toScreen.readIntInput();

    }

    cout << "Year of death, if the person is still alive please enter 0" << endl;
    yearofdeath = toScreen.readIntInput();
    //Athugar hvort slegið sé inn tölustafur, að slegið sé inn 4 stafa ártal, að dánarár sé ekki
    //á undan fæðingarári og að dánarár sé ekki stærra en árið í ár.
    while(cin.fail() || (yearofdeath > 0 && yearofdeath < 999) || (yearofdeath > 0 && yearofdeath < yearofbirth) || yearofdeath > currentYear())
    {
        UI error;
        error.displayError("Error, please enter a valid year");
        yearofdeath = toScreen.readIntInput();
    }

    person per(name,gender,yearofbirth,yearofdeath);


    Datalayer writer;
    writer.addPersonToDB(per);
}

void DomainLayer::addComputer()
{

}

void DomainLayer::addConnection()
{

}


int DomainLayer::currentYear()
{
    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );
    localTime = localtime( &currentTime );
    int currentYear = localTime->tm_year + 1900;

    return currentYear;
}

vector<person> DomainLayer::updatePersonVector()
{
    Datalayer reader;
    return reader.pullPerson();
}

vector<Computer> DomainLayer::updateComputerVector()
{
    Datalayer reader;
    return reader.pullComputer();
}

vector<Connections> DomainLayer::updateConnectionsVector()
{
    Datalayer reader;
    return reader.pullConnections();
}


//fjarlægir einstakling úr vector
void DomainLayer::removePerson()
{
    /*UI toScreen;
    vector<Person> personvector;
    Datalayer Reader;
    personvector = Reader.pullPerson();

    int id = 0,locationinvector=0;
    toScreen.displayPersonVector(personvector);
    toScreen.displayMessage("Enter ID of the person you want to remove: ");
    cin >> id;
    if(vectorHasPerson(personvector,id) != -1)
    {
        locationinvector = vectorHasPerson(personvector,id);
        personvector.erase(personvector.begin()+locationinvector);
        //updatefile(personvector);
    }

    else
    {
        UI error;
        error.displayError("Error ID not found!");
    }*/

}

//removeperson notar þetta fall til að athuga hvort manneskjan
//sé til
int DomainLayer::vectorHasPerson(vector <person> per,int id)
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

int DomainLayer::vectorHasComputer(vector <Computer> comp,int id)
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
