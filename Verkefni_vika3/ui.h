#ifndef UI_H
#define UI_H
#include <person.h>
#include <computer.h>
#include <connections.h>
#include <domainlayer.h>
#include <ostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/*Sér um samskipti við notanda, og villutékkar áður en eitthvað er sent niður í domain*/
class UI
{
public:
    UI();
    //Föll sem birta valmyndir
    void mainMenu();
    void displaySearchMenu();
    void displayPersonMenu();
    void displayComputerMenu();
    void displayConnectionsMenu();
    void displayRemoveMenu();
    void displayAddMenu();

    //Föll sem birta gögn úr gagnagrunni
    void displayPersonVector(vector <person> perVec);
    void displayComputerVector(vector <Computer> compVec);
    void displayConnectionVector(vector <Connections> conVec);

    //Föll sem birta ýmis skilaboð
    void displayError(string error);
    void displayMessage(string message);
    void displayInput(string input);

    //Föll sem lesa inn upplýsingar frá notanda
    string readStringInput();
    string readStringInputWithSpaces();
    int readIntInput();
    int userInput();
};

#endif // UI_H
