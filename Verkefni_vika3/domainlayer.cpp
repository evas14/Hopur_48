#include "domainlayer.h"

DomainLayer::DomainLayer()
{

}

vector<person> DomainLayer::sortPersonVectorByID(string sortType)
{

    Datalayer Reader;
    vector <person>sortedVector = Reader.pullPerson();

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

    Datalayer Reader;
    vector <person>sortedVector = Reader.sortPersonByName();

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

    Datalayer Reader;
    vector <person>sortedVector = Reader.sortPersonByAge();

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

    Datalayer Reader;
    vector <Computer> sortedVector = Reader.pullComputer();

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

    Datalayer Reader;
    vector <Computer>sortedVector = Reader.sortComputerByName();

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
    Datalayer Reader;
    vector <Connections>sortedVector = Reader.pullConnections();
    return sortedVector;
}


//Leita að persónu í vector
vector<person> DomainLayer::searchPersonByName(string searchquery)
{
    Datalayer Reader;
    vector<person> personvector = Reader.sortPersonByName();
    vector<person> queryMatchVector;
    //UI //toScreen;
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
    Datalayer Reader;
    vector<Computer> computerVector = Reader.pullComputer();
    vector<Computer> queryMatchVector;
    //UI //toScreen;
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
        //UI //error;
        //error.display//error("No match for: " + searchquery);
    }

    //toScreen.displayComputerVector(queryMatchVector);
}

//Bætir persónu við vector
bool DomainLayer::addPerson(string name, string gender, int yearofbirth, int yearofdeath)
{


    name[0] = toupper(name[0]);

    //Athugar hvort slegið sé inn tölustafur í nafn
    if(name.find_first_of("0123456789")!=std::string::npos)
    {
       return false;
    }

    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    if(yearofbirth < 999 || yearofbirth > currentYear())
    {
        return false;
    }

    //Athugar hvort slegið sé inn tölustafur, að slegið sé inn 4 stafa ártal, að dánarár sé ekki
    //á undan fæðingarári og að dánarár sé ekki stærra en árið í ár.
    if((yearofdeath > 0 && yearofdeath < 999) || (yearofdeath > 0 && yearofdeath < yearofbirth) || yearofdeath > currentYear())
    {
        return false;
    }

    person per(name,gender,yearofbirth,yearofdeath);

    Datalayer writer;
    if(!writer.addPersonToDB(per))
    {
        return false;
    }
    else
    {
        return true;
    }
}


/*
void DomainLayer::addComputer()
{
    //UI //toScreen;
    string name;
    string computertype;
    int yearb//UIlt = 0;
    bool wasb//UIlt;

    //toScreen.displayInput("Name: ");
    name = //toScreen.readStringInputWithSpaces();
    name[0] = toupper(name[0]);

    //toScreen.displayInput("Computer type: ");
    computertype = //toScreen.readStringInput();
    computertype[0] = toupper(computertype[0]);

    //toScreen.displayInput("Year b//UIlt: ");
    yearb//UIlt = //toScreen.readIntInput();

    //Athugar hvort að slegið sé inn tölustafur, 4 stafa ártal og að
    //ártalið sé ekki meira en árið í ár.
    while(cin.fail() || yearb//UIlt < 999 || yearb//UIlt > currentYear())
    {
        //UI //error;
        //error.display//error("//error, please enter a valid year");
        yearb//UIlt = //toScreen.readIntInput();

    }

    //toScreen.displayMessage("Was b//UIlt: 1 for true, 0 for false");
    wasb//UIlt = //toScreen.readIntInput();
    if (wasb//UIlt == 1)
    {
        wasb//UIlt = true;
    }else
    {
        wasb//UIlt = false;
    }

    Computer comp(name, computertype, yearb//UIlt, wasb//UIlt);

    Datalayer writer;
    if(!writer.addComputerToDB(comp))
    {
        //toScreen.display//error("Oops! something went wrong.");
    }
    else
    {
        //toScreen.displayMessage("Operation successful!");
    }
}
*/

/*

void DomainLayer::addConnection()
{
    //UI //toScreen;
    Datalayer writer;
    vector <person> personVector = writer.pullPerson();
    vector <Computer> computerVector = writer.pullComputer();

    int pId = 0;
    int cId = 0;
    //toScreen.displayPersonVector(personVector);
    while(true)
    {
        //toScreen.displayInput("Person Id: ");
        pId = //toScreen.readIntInput();

        if(vectorHasPerson(personVector,pId))
        {
            break;
        }

    }

    //toScreen.displayComputerVector(computerVector);
    while(true)
    {
        //toScreen.displayInput("Computer Id: ");
        cId = //toScreen.readIntInput();

        if(vectorHasComputer(computerVector,cId))
        {
            break;
        }

    }

    Connections connection (pId,cId);
    if(!writer.addConnectionToDB(connection))
    {
        //toScreen.display//error("Oops! something went wrong.");
    }
    else
    {
        //toScreen.displayMessage("Operation successful!");
    }

}
*/

int DomainLayer::currentYear()
{
    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );
    localTime = localtime( &currentTime );
    int currentYear = localTime->tm_year + 1900;

    return currentYear;
}

//fjarlægir einstakling úr vector
void DomainLayer::removePerson(int id)
{
    //UI //toScreen;
    Datalayer Reader;
    vector<person> personvector;
    personvector = Reader.pullPerson();

    Reader.removePersonFromDB(id);

}


/*
void DomainLayer::removeComputer()
{
    //UI //toScreen;
    Datalayer Reader;
    vector<Computer> computerVector;
    computerVector = Reader.pullComputer();

    int id = 0;
    //toScreen.displayComputerVector(computerVector);
    //toScreen.displayMessage("Enter ID of the computer you want to remove: ");
    id = //toScreen.readIntInput();
    if(vectorHasComputer(computerVector,id))
    {
        if(!Reader.removeComputerFromDB(id))
        {
            //toScreen.display//error("Oops! something went wrong.");
        }
        else
        {
            //toScreen.displayMessage("Operation successful!");
        }
    }
    else
    {
        //UI //error;
        //toScreen.displayMessage("\n");
        //error.display//error("//error ID not found!\n");
        //toScreen.displayRemoveMenu();
    }

}
*/
/*
void DomainLayer::removeConnection()
{
    //UI //toScreen;
    Datalayer Reader;
    vector<Connections> connectionsvector;
    connectionsvector = Reader.pullConnections();

    int id = 0;
    //toScreen.displayConnectionVector(connectionsvector);
    //toScreen.displayMessage("Enter ID of the connection you want to remove: ");
    id = //toScreen.readIntInput();
    if(vectorHasConnection(connectionsvector,id))
    {
        if(!Reader.removeConnectionFromDB(id))
        {
            //toScreen.display//error("Oops! something went wrong.");
        }
        else
        {
            //toScreen.displayMessage("Operation successful!");
        }
    }
    else
    {
        //UI //error;
        //toScreen.displayMessage("\n");
        //error.display//error("//error ID not found!\n");
        //toScreen.displayRemoveMenu();
    }

}

*/
/*
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
*/
