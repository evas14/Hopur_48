#include "domainlayer.h"

DomainLayer::DomainLayer()
{

}

vector<person> DomainLayer::sortPersonVectorByID(string sortType)
{

    vector <person>sortedVector = datalayer.pullPerson();

    if(sortType == "normal")
    {
        return sortedVector;
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        return sortedVector;
    }

}

//Skilar vector í stafrófsröð
vector<person> DomainLayer::sortPersonVectorByName(string sortType)
{


    vector <person>sortedVector = datalayer.sortPersonByName();

    if(sortType == "normal")
    {

        return sortedVector;
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        return sortedVector;
    }

}

vector<person> DomainLayer::sortPersonVectorByAge(string sortType)
{


    vector <person>sortedVector = datalayer.sortPersonByAge();

    if(sortType == "normal")
    {
       //toScreen.displayPersonVector(sortedVector);
        return sortedVector;
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        return sortedVector;
    }

}

vector<Computer> DomainLayer::sortComputerVectorByID(string sortType)
{


    vector <Computer> sortedVector = datalayer.pullComputer();

    if(sortType == "normal")
    {
       return sortedVector;
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        return sortedVector;
    }

}

vector<Computer> DomainLayer:: sortComputerVectorByName(string sortType)
{


    vector <Computer>sortedVector = datalayer.sortComputerByName();

    if(sortType == "normal")
    {
       return sortedVector;
    }

    else
    {
        reverse(sortedVector.begin(),sortedVector.end());
        return sortedVector;
    }

}

vector<Connections> DomainLayer::sortConnectionsVectorByID()
{

    vector <Connections>sortedVector = datalayer.pullConnections();
    return sortedVector;
}


//Leita að persónu í vector
vector<person> DomainLayer::searchPersonByName(string searchquery)
{

    vector<person> personvector = datalayer.sortPersonByName();
    vector<person> queryMatchVector;

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


    return queryMatchVector;
}

vector<Computer> DomainLayer::searchComputerByName(string searchquery)
{

    vector<Computer> computerVector = datalayer.pullComputer();
    vector<Computer> queryMatchVector;

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

    return queryMatchVector;
}

//Bætir persónu við vector
int DomainLayer::addPerson(string name, string gender, int yearofbirth, int yearofdeath)
{


    name[0] = toupper(name[0]);

    //Athugar hvort slegið sé inn tölustafur í nafn
    if(name.find_first_of("0123456789")!=std::string::npos)
    {
       return 1;
    }

    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    if(yearofbirth < 999 || yearofbirth > currentYear())
    {
        return 2;
    }

    //Athugar hvort slegið sé inn tölustafur, að slegið sé inn 4 stafa ártal, að dánarár sé ekki
    //á undan fæðingarári og að dánarár sé ekki stærra en árið í ár.
    if((yearofdeath > 0 && yearofdeath < 999) || (yearofdeath > 0 && yearofdeath < yearofbirth) || yearofdeath > currentYear())
    {
        return 3;
    }

    person per(name,gender,yearofbirth,yearofdeath);

    if(!datalayer.addPersonToDB(per))
    {

        return 4;
    }
    else
    {
        return 0;
    }
}



int DomainLayer::addComputer(string name,string computerType,int yearBuilt,bool wasBuilt)
{

    name[0] = toupper(name[0]);

    computerType[0] = toupper(computerType[0]);

    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    if(yearBuilt < 999 || yearBuilt > currentYear())
    {
        return 1;
    }

    if (wasBuilt == 1)
    {
       wasBuilt = true;
    }
    else
    {
        wasBuilt = false;
    }

    Computer comp(name, computerType, yearBuilt, wasBuilt);


    if(!datalayer.addComputerToDB(comp))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}




bool DomainLayer::addConnection(int personID, int computerID)
{

    Connections connection (personID,computerID);
    if(!datalayer.addConnectionToDB(connection))
    {
        return false;
    }
    else
    {
        return true;
    }

}

int DomainLayer::updateComputer(int id, string name, string computerType, int yearBuilt, bool wasBuilt)
{

    name[0] = toupper(name[0]);

    computerType[0] = toupper(computerType[0]);

    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    if(yearBuilt < 0 || yearBuilt > currentYear())
    {
        return 1;
    }

    if (wasBuilt == 1)
    {
       wasBuilt = true;
    }
    else
    {
        wasBuilt = false;
    }

    Computer comp(name, computerType, yearBuilt, wasBuilt);
    comp.setID(id);


    if(!datalayer.updateComputerToDB(comp))
    {
        return 2;
    }
    else
    {
        return 0;
    }


}

int DomainLayer::updatePerson(int id, string name, string gender, int yearofbirth, int yearofdeath)
{

    name[0] = toupper(name[0]);

    //Athugar hvort slegið sé inn tölustafur í nafn
    if(name.find_first_of("0123456789")!=std::string::npos)
    {
       return 1;
    }

    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    if(yearofbirth < 999 || yearofbirth > currentYear())
    {
        return 2;
    }

    //Athugar hvort slegið sé inn tölustafur, að slegið sé inn 4 stafa ártal, að dánarár sé ekki
    //á undan fæðingarári og að dánarár sé ekki stærra en árið í ár.
    if((yearofdeath > 0 && yearofdeath < 999) || (yearofdeath > 0 && yearofdeath < yearofbirth) || yearofdeath > currentYear())
    {
        return 3;
    }

    person per(name,gender,yearofbirth,yearofdeath);
    per.setID(id);

    if(!datalayer.updatePersonToDB(per))
    {
        return 4;
    }
    else
    {
        return 0;
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


bool DomainLayer::removePerson(int id)
{

    if(!datalayer.removePersonFromDB(id))
    {
        return false;
    }
    else
    {
        return true;
    }

}



bool DomainLayer::removeComputer(int id)
{
    vector<Computer> computerVector;
    computerVector = datalayer.pullComputer();

    {
        if(!datalayer.removeComputerFromDB(id))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

}


bool DomainLayer::removeConnection(int id)
{

    if(!datalayer.removeConnectionFromDB(id))
    {
        return false;
    }
    else
    {
        return true;
    }
}


