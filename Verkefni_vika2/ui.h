#ifndef UI_H
#define UI_H
#include <person.h>
#include <computer.h>
#include <connections.h>
#include <ostream>
#include <string>
using namespace std;

/*Sér um samskipti við notanda, og villutékkar áður en eitthvað er sent niður í domain*/
class UI
{
    public:
        UI();
        int mainMenu();
        int userInput();
        int searchMenu();
        //skrifar út eina persónu í einu
        void displayPerson(person per);
        void displayComputer(Computer comp);
        void displayConnection(Connections con);
        void displayError(string error);
        void displayMessage(string message);
        void displayInput(string input);
        string readSearchQuery();
};

#endif // UI_H
