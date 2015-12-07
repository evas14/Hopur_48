#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <person.h>
#include <computer.h>
#include <connections.h>
#include <fstream>
#include <ui.h>
#include <datalayer.h>
#include <algorithm>
#include <domainlayer.h>

using namespace std;

int main()
{
    UI userInterface;
    while(true)
    {
        userInterface.mainMenu();
    }

    return 0;
}



