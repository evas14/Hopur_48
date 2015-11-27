#include "ui.h"
#include <iostream>

using namespace std;

UI::UI()
{

}

void UI::mainMenu()
{
    cout << "Welcome to the database of elite computer scientists!" << endl << endl;
    cout << "What would you like to do?" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "1. Promote a new CS to the elite ranks(add new).\n"
            "2. Edit an existing scientist.\n"
            "3. Search amongst the elites.\n"
            "4. Sort the elites by order of your choice.\n"
            "5. Demote a CS from the elite ranks(delete).\n"
            "Any other choice quits!" << endl;

    switch(userInput())
    {
    case 1:
        cout << "case 1" << endl;
        break;
    case 2:
        cout << "case 2" << endl;
        break;
    case 3:
        cout << "case 3" << endl;
        break;
    case 4:
        cout << "case 4" << endl;
        break;
    case 5:
        cout << "case 5" << endl;
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
