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
