#include "ui.h"
#include <iostream>

using namespace std;

UI::UI()
{

}

int UI::mainMenu()
{

    cout << "-----------------------------------------------------" << endl;
    cout << "1. Add New.\n"
            "2. Display Names in Alphabetical Order.\n"
            "3. Display Names in Reverse Alphabetical Order.\n"
            "4. Search By Name.\n"
            "5. Remove From List.\n"
            "Any other choice quits!" << endl;

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
