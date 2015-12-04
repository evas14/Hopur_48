#include "ui.h"
#include <iostream>

using namespace std;

UI::UI()
{
}

//Valmynd
int UI::mainMenu()
{
    cout << "-----------------------------------------------------" << endl;
    cout << "1. Add New Person.\n"
            "2. Add New Computer.\n"
            "3. Add New Connection.\n"
            "4. Display Names\n"
            "5. Display Computers\n"
            "6. Show Connections\n"
            "7. Search by Name.\n"
            "8. Remove from List.\n" << endl;
    cout << "Any other Choice will Terminate Program! \n" << endl;

    switch(userInput())
    {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 4;
            break;
        case 5:
            return 5;
            break;
        case 6:
            return 6;
            break;
        case 7:
            return 7;
            break;
        case 8:
            return 8;
            break;
        default:
            exit(0);
    }
}

int UI::userInput()
{
    int choice = 0;
    cin >> choice;
    return choice;
}

//Verður notað í næsta skilaverkefni.
int UI::searchMenu()
{
        /*cout << "-----------------------------------------------------" << endl;
        cout << "8.Search by Name\n"
        "9.Search by Age\n"
        "10.Search by Gender.\n"
        "11.Search by Year of Birth.\n"
        "12.Search by Year of Death.\n" << endl;
        int userinput = userInput();
        */
        return 0;
}

//Skrifar persónu út á skjá
void UI::displayPerson( person per)
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

void UI::displayComputer(Computer comp)
{
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

void UI::displayConnection(Connections con)
{

    cout <<"ID: "<< con.getID();
    cout <<"Name: " << con.getPersonID();
    cout <<"Type: " << con.getComputerID() << endl;

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

string UI::readSearchQuery()
{
    string searchquery;
    cout << "Who are you looking for?: ";
    cin.ignore();
    getline(cin, searchquery);

    return searchquery;
}

