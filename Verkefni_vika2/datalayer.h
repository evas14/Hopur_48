#ifndef DATALAYER_H
#define DATALAYER_H
#include <vector>
#include <fstream>
#include <person.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Datalayer
{
    public:
        Datalayer();
        void AddData(vector<person> toFile );
        vector<person> PullData();
};

#endif // DATALAYER_H
