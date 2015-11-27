#include "ui.h"
#include <iostream>

using namespace std;

UI::UI()
{

}

int UI::mainMenu()
{

    cout << "-----------------------------------------------------" << endl;
    cout << "1. Promote a new CS to the elite ranks(add new).\n"
            "2. Edit an existing scientist.\n"
            "3. Search amongst the elites.\n"
            "4. Display all.\n"
            "5. Demote a CS from the elite ranks(delete).\n"
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
