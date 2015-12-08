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

void DomainLayer::sortConnectionsVectorByID()
{
    UI toScreen;
    Datalayer Reader;
    vector <Connections>sortedVector = Reader.pullConnections();
    toScreen.displayConnectionVector(sortedVector);

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

void DomainLayer::searchComputerByName(string searchquery)
{
    Datalayer Reader;
    vector<Computer> computerVector = Reader.pullComputer();
    vector<Computer> queryMatchVector;
    UI toScreen;
    string computerName;

    transform(searchquery.begin(), searchquery.end(), searchquery.begin(),::tolower);

    for(unsigned int i = 0; i < computerVector.size(); i++)
    {
        computerName = computerVector.at(i).getName();
        transform(computerName.begin(), computerName.end(), computerName.begin(),::tolower);

        if (computerName.find(searchquery) != string::npos)
        {
            queryMatchVector.push_back(computerVector.at(i));
        }
    }

    if(queryMatchVector.size() == 0)
    {
        UI error;
        error.displayError("No match for: " + searchquery);
    }

    toScreen.displayComputerVector(queryMatchVector);
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

    toScreen.displayMessage("Year of death, if the person is still alive please enter 0");
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
    if(!writer.addPersonToDB(per))
    {
        toScreen.displayError("Oops! something went wrong.");
    }
    else
    {
        toScreen.displayMessage("Operation successful!");
    }
}

void DomainLayer::addComputer()
{
    UI toScreen;
    string name;
    string computertype;
    int yearbuilt = 0;
    bool wasbuilt;

    toScreen.displayInput("Name: ");
    name = toScreen.readStringInputWithSpaces();
    name[0] = toupper(name[0]);


    toScreen.displayInput("Computer type: ");
    computertype = toScreen.readStringInput();
    computertype[0] = toupper(computertype[0]);


    toScreen.displayInput("Year built: ");
    yearbuilt = toScreen.readIntInput();
    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    while(cin.fail() || yearbuilt < 999 || yearbuilt > currentYear())
    {
        UI error;
        error.displayError("Error, please enter a valid year");
        yearbuilt = toScreen.readIntInput();

    }

    toScreen.displayMessage("Was built: 1 for true, 0 for false");
    wasbuilt = toScreen.readIntInput();
    if (wasbuilt == 1){
        wasbuilt = true;
    }else{
        wasbuilt = false;
    }


     Computer comp(name, computertype, yearbuilt, wasbuilt);

     Datalayer writer;
     if(!writer.addComputerToDB(comp))
     {
         toScreen.displayError("Oops! something went wrong.");
     }
     else
     {
         toScreen.displayMessage("Operation successful!");
     }
}

void DomainLayer::addConnection()
{
    UI toScreen;
    Datalayer writer;
    vector <person> personVector = writer.pullPerson();
    vector <Computer> computerVector = writer.pullComputer();

    int pId=0;
    int cId=0;
    toScreen.displayPersonVector(personVector);
    while(true)
    {

        toScreen.displayInput("Person Id: ");
        pId = toScreen.readIntInput();

        if(vectorHasPerson(personVector,pId))
        {
            break;
        }

    }


    toScreen.displayComputerVector(computerVector);
    while(true)
    {
        toScreen.displayInput("Computer Id: ");
        cId = toScreen.readIntInput();

        if(vectorHasComputer(computerVector,cId))
        {
            break;
        }

    }

    Connections connection (pId,cId);
    if(!writer.addConnectionToDB(connection))
    {
        toScreen.displayError("Oops! something went wrong.");
    }
    else
    {
        toScreen.displayMessage("Operation successful!");
    }

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
    UI toScreen;
    Datalayer Reader;
    vector<person> personvector;
    personvector = Reader.pullPerson();

    int id = 0;
    toScreen.displayPersonVector(personvector);
    toScreen.displayMessage("Enter ID of the person you want to remove: ");
    id = toScreen.readIntInput();
    if(vectorHasPerson(personvector,id))
    {
        if(!Reader.removePersonFromDB(id))
        {
            toScreen.displayError("Oops! something went wrong.");
        }
        else
        {
            toScreen.displayMessage("Operation successful!");
        }
    }

    else
    {
        UI error;
        error.displayError("Error ID not found!");
    }

}

void DomainLayer::removeComputer()
{
    UI toScreen;
    Datalayer Reader;
    vector<Computer> computerVector;
    computerVector = Reader.pullComputer();

    int id = 0;
    toScreen.displayComputerVector(computerVector);
    toScreen.displayMessage("Enter ID of the computer you want to remove: ");
    id = toScreen.readIntInput();
    if(vectorHasComputer(computerVector,id))
    {
        if(!Reader.removeComputerFromDB(id))
        {
            toScreen.displayError("Oops! something went wrong.");
        }
        else
        {
            toScreen.displayMessage("Operation successful!");
        }
    }

    else
    {
        UI error;
        error.displayError("Error ID not found!");
    }


}

void DomainLayer::removeConnection()
{
    UI toScreen;
    Datalayer Reader;
    vector<Connections> connectionsvector;
    connectionsvector = Reader.pullConnections();

    int id = 0;
    toScreen.displayConnectionVector(connectionsvector);
    toScreen.displayMessage("Enter ID of the connection you want to remove: ");
    id = toScreen.readIntInput();
    if(vectorHasConnection(connectionsvector,id))
    {
        if(!Reader.removeConnectionFromDB(id))
        {
            toScreen.displayError("Oops! something went wrong.");
        }
        else
        {
            toScreen.displayMessage("Operation successful!");
        }
    }

    else
    {
        UI error;
        error.displayError("Error ID not found!");
    }


}

//removeperson notar þetta fall til að athuga hvort manneskjan
//sé til
bool DomainLayer::vectorHasPerson(vector <person> per,int id)
{
    for(unsigned int i = 0; i < per.size(); i++)
    {
        if(per.at(i).getID() == id)
        {
            return true;
        }
    }

    return false;

}

bool DomainLayer::vectorHasComputer(vector <Computer> comp,int id)
{
    for(unsigned int i = 0; i < comp.size(); i++)
    {
        if(comp.at(i).getID() == id)
        {
            return true;
        }
    }

    return false;

}

bool DomainLayer::vectorHasConnection(vector<Connections> con,int id)
{
    for(unsigned int i = 0; i < con.size(); i++)
    {
        if(con.at(i).getID() == id)
        {
            return true;
        }
    }

    return false;

}
