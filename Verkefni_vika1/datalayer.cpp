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
    }
    out.close();

}
vector<person> Datalayer::PullData( )
{
    vector<person>pull;
    ifstream in("data.txt");

    string id, yearofbirth,yearofdeath;
    string name,gender;

    int Yearofbirth = 0,Yearofdeath = 0;

    if (in.is_open())
    {

            while(in.good()&& getline(in,id))
            {

                getline (in,name);
                getline (in,gender);
                getline (in,yearofbirth);
                getline (in,yearofdeath);

                stringstream s1(yearofbirth);
                s1 >> Yearofbirth;

                stringstream s2(yearofdeath);
                s2 >> Yearofdeath;

                person per(name,gender,Yearofbirth,Yearofdeath);
                per.setID(pull.size()+1);

                pull.push_back(per);



            }

    }

    in.close();
    return pull;

}

