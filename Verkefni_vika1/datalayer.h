#ifndef DATALAYER_H
#define DATALAYER_H
#include <vector>
#include <fstream>
#include <person.h>
using namespace std;


class Datalayer
{
public:
    Datalayer();
    void AddData(vector<person> toFile );
};

#endif // DATALAYER_H
