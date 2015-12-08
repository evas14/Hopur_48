#ifndef UI_H
#define UI_H
#include <person.h>
#include <computer.h>
#include <connections.h>
#include <domainlayer.h>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

/*Sér um samskipti við notanda, og villutékkar áður en eitthvað er sent niður í domain*/
class UI
{
public:
    UI();
    //Menu föll
    void mainMenu();
    void displaySearchMenu();
    void displayPersonMenu();
    void displayComputerMenu();
    void displayConnectionsMenu();
    void displayRemoveMenu();
    void displayAddMenu();

    //Display föll
    void displayPersonVector(vector <person> perVec);
    void displayComputerVector(vector <Computer> compVec);
    void displayConnectionVector(vector <Connections> conVec);
    void displayError(string error);
    void displayMessage(string message);
    void displayInput(string input);

    //Input föll
    string readStringInput();
    string readStringInputWithSpaces();
    int readIntInput();
    int userInput();
};

#endif // UI_H
