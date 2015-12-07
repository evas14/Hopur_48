#include "ui.h"
#include <iostream>

using namespace std;

UI::UI()
{
}

//Valmynd
void UI::mainMenu()
{

    cout << "-----------------------------------------------------" << endl;
    cout << "1. Add New\n"
            "2. Display Names\n"
            "3. Display Computers\n"
            "4. Show Connections\n"
            "5. Search\n"
            "6. Remove from List.\n" << endl;
    cout << "Any other Choice will Terminate Program! \n" << endl;


    switch(userInput())
    {
        case 1:
            displayAddMenu();
            break;
        case 2:
            displayPersonMenu();
            break;
        case 3:
            displayComputerMenu();
            break;
        case 4:
            displayConnectionsMenu();
            break;
        case 5:
            displaySearchMenu();
            break;
        case 6:
            displayRemoveMenu();
            break;
        default:
            exit(0);
    }
}

void UI::displayAddMenu()
{
    int userSelection = 0;
    cout << "1.Add New Person\n"
            "2.Add New Computer\n"
            "3.Add New Connection\n";
    userSelection = userInput();

}

int UI::userInput()
{
    int choice = 0;
    cin >> choice;
    return choice;
}

//Verður notað í næsta skilaverkefni.
void UI::displaySearchMenu()
{
    string searchQuery;
    DomainLayer domain;
    int userSelection=0;

    cout << "1.Search By Person Name\n"
            "2.Search By Computer Name\n";

    while(true)
    {
        userSelection = readIntInput();
        if(userSelection >= 1 && userSelection <= 2)
        {
            break;
        }
        else
        {
            displayError("Error unknown command!");
            displayError("Select 1 or 2");
        }

    }

    switch(userSelection)
    {
        case 1:
            displayInput("Who are you looking for?: ");
            searchQuery = readStringInputWithSpaces();
            domain.searchPersonByName(searchQuery);

        break;
        case 2:
            cout << "Coming soon"<<endl;

        break;

    }

}

void UI::displayRemoveMenu()
{
    int userSelection=0;

    cout << "1.Remove Person\n"
            "2.Remove Computer\n"
            "3.Remove Connection\n";
    userSelection = userInput();
}

//Skrifar persónu út á skjá
void UI::displayPersonVector(vector <person> perVec)
{

    for(unsigned int i = 0; i < perVec.size(); i++)
    {
        person per = perVec.at(i);

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



}

void UI::displayComputerVector(vector <Computer> compVec)
{

    for(unsigned int i = 0; i < compVec.size(); i++)
    {
        Computer comp = compVec.at(i);

        cout << "----------------------------------------"<<endl;
        cout <<"ID: "<< comp.getID() << endl;
        cout <<"Name: " << comp.getName() << endl;
        cout <<"Type: " << comp.getComputerType() << endl;
        cout <<"Year built: " << comp.getYearBuilt() << endl;
        if (comp.getWasBuilt())
        {
          cout <<"Was it Built: Yes"<<endl;
        }
        else
        {
           cout <<"Was it Built: No"<<endl;
        }

    }

}

void UI::displayConnectionVector(vector <Connections> conVec)
{

    displayMessage("id\t Name\t\t\t Computer");
    for(unsigned int i = 0; i < conVec.size(); i++)
    {
        Connections con = conVec.at(i);

        cout << con.getID() << "\t ";
        cout << con.getPersonName() << "\t ";
        cout << con.getComputerName() << endl;

    }

}

void UI::displayPersonMenu()
{
    int userSelection = 0;
    DomainLayer domain;

    cout << "1.Display Names From Lowest to Highest ID\n"
            "2.Display Names From Highest to Lowest ID\n"
            "3.Display Names in Alphabetical Order\n"
            "4.Display Names in Reverse Alphabetical Order\n"
            "5.Display Names From Youngest to Oldest\n"
            "6.Display Names From Oldest to Youngest\n"

         << endl;
    while(true)
    {
        userSelection = readIntInput();
        if(userSelection >= 1 && userSelection <= 6)
        {
            break;
        }
        else
        {
            displayError("Error unknown command!");
            displayError("Select 1,2,3,4,5 or 6");
        }

    }

    switch(userSelection)
    {
        case 1:
            domain.sortPersonVectorByID("normal");
        break;

        case 2:
            domain.sortPersonVectorByID("reverse");

        break;
        case 3:
            domain.sortPersonVectorByName("normal");
        break;
        case 4:
            domain.sortPersonVectorByName("reverse");

        break;
        case 5:
            domain.sortPersonVectorByAge("normal");

        break;
        case 6:
            domain.sortPersonVectorByAge("reverse");

        break;

    }



}

void UI::displayComputerMenu()
{
    DomainLayer domain;
    int userSelection = 0;

    cout << "1.Display Computers From Lowest to Highest ID\n"
            "2.Display Computers From Highest to Lowest ID\n"
            "3.Display Computer Names in Alphabetical Order\n"
            "4.Display Computer Names in Reverse Alphabetical Order"
         << endl;

    while(true)
    {
        userSelection = readIntInput();
        if(userSelection >= 1 && userSelection <= 4)
        {
            break;
        }
        else
        {
            displayError("Error unknown command!");
            displayError("Select 1,2,3 or 4");
        }

    }

    switch(userSelection)
    {
        case 1:
            domain.sortComputerVectorByID("normal");
        break;

        case 2:
            domain.sortComputerVectorByID("reverse");
        break;

        case 3:
            domain.sortComputerVectorByName("normal");
        break;

        case 4:
            domain.sortComputerVectorByName("reverse");
        break;

    }

}

void UI::displayConnectionsMenu()
{
    Datalayer data;
    vector <Connections> connectionvec = data.pullConnections();
    displayConnectionVector(connectionvec);

}


void UI::displayError(string error)
{
    cout << error << endl;
}

void UI::displayMessage(string message)
{
    cout << message << endl;
}
void UI::displayInput(string input)
{
    cout << input;
}

string UI::readStringInput()
{
    string str;
    cin >> str;

    return str;
}

string UI::readStringInputWithSpaces()
{
    string str;
    cin.ignore();
    std::getline(std::cin, str);

    return str;
}

int UI::readIntInput()
{
    int num=0;

    cin.clear();
    cin.ignore(256, '\n');
    cin >> num;

    return num;

}

