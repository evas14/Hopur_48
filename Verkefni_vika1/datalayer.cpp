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
vector<person> Datalayer::PullData( )
{
    vector<person>pull;
    ifstream in("data.txt");

    //int ID,yearofbirth,yearofdeath;
    string name;

    if (in.is_open())
    {
        while( getline(in,name))
        {


           cout<<name<<endl;
            /*getline(in,name);
            in >>  >> endl;
            in >>  >> endl;
            in >> >> endl;
            in >> ';' << endl;*/
        }
        in.close();
    }

    return pull;

}

