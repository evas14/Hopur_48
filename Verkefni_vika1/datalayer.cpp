#include "datalayer.h"

Datalayer::Datalayer()
{
}

void Datalayer::AddData(vector<person> toFile )
{
    ofstream out;
    out.open("data.txt");

    for(unsigned int i = 0; i < toFile.size(); i++)
    {

        person currentperson = toFile.at(i);
        out << currentperson.getID() << endl;
        out << currentperson.getName() << endl;
        out << currentperson.getGender() << endl;
        out << currentperson.getYearOfbirth() << endl;
        out << currentperson.getYearOfdeath() << endl;
        out << ';' << endl;
    }
    out.close();

}

