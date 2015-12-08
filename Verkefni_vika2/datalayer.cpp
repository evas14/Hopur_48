#include "datalayer.h"

//Smiður
Datalayer::Datalayer()
{


}

void Datalayer::connectDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("vln.sqlite");

    if (!db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

}

void Datalayer::closeDB()
{
    db.close();
}

bool Datalayer::addComputerToDB(Computer comp)
{

    QSqlQuery query;
    string name = comp.getName();
    string computerType = comp.getComputerType();
    int yearBuilt = comp.getYearBuilt();
    bool wasBuilt = comp.getWasBuilt();
    stringstream ss1, ss2, ss3;
    string a;

    if (wasBuilt)
    {
        a = "1";
    }
    else
    {
        a = "0";
    }

    ss3 << yearBuilt;
    string str3 = ss3.str();

    if(query.exec("INSERT INTO computers (name,computerType,yearBuilt,wasBuilt) VALUES('" + QString::fromStdString(name.c_str()) + "','" + QString::fromStdString(computerType.c_str()) + "','" + QString::fromStdString(str3.c_str()) + "','" + QString::fromStdString(a.c_str()) + "')"))
    {
        return true;
    }
    else
    {
        return false;
    }
    //qDebug() << query.lastQuery();
}

bool Datalayer::addConnectionToDB(Connections connection)
{

    QSqlQuery query;
    int pId = connection.getPerID();
    int cId = connection.getComID();
    stringstream ss1, ss2;
    ss1 << pId;
    string str1 = ss1.str();
    ss2 << cId;
    string str2 = ss2.str();

    if(query.exec("INSERT into connections (pId,cId) VALUES('"+ QString::fromStdString(str1.c_str()) + "','" + QString::fromStdString(str2.c_str()) + "')"))
    {
        return true;
    }
    else
    {
        return false;
    }
    //qDebug() << query.lastQuery();


}


bool Datalayer::addPersonToDB(person per)
{

    QSqlQuery query;
    string name = per.getName();
    string gender = per.getGender();
    int age = per.getAge();
    int yearOfBirth = per.getYearOfbirth();
    int yearOfDeath = per.getYearOfdeath();
    stringstream ss1, ss2, ss3;
    ss1 << yearOfBirth;
    string str1 = ss1.str();
    ss2 << yearOfDeath;
    string str2 = ss2.str();
    ss3 << age;
    string str3 = ss3.str();

    if(query.exec("INSERT into persons (name,gender,yearOfBirth,yearOfDeath,age) VALUES('" + QString::fromStdString(name.c_str()) + "','" + QString::fromStdString(gender.c_str()) + "','" + QString::fromStdString(str1.c_str()) + "','" + QString::fromStdString(str2.c_str()) + "','" + QString::fromStdString(str3.c_str()) + "')"))
    {
        return true;
    }
    else
    {
        return false;
    }
    //qDebug() << query.lastQuery();
}

bool Datalayer::removeComputerFromDB(int id)
{
    QSqlQuery query;
    stringstream ss1;
    ss1 << id;
    string str1 = ss1.str();

    if(query.exec("DELETE FROM computers where id = " + QString::fromStdString(str1.c_str())))
    {
        return true;
    }
    else
    {
        return false;
    }
    //qDebug() << query.lastQuery();

}

bool Datalayer::removePersonFromDB(int id)
{
    QSqlQuery query;

    stringstream ss1;
    ss1 << id;
    string str1 = ss1.str();

    if(query.exec("DELETE FROM persons where id = " + QString::fromStdString(str1.c_str())))
    {
        return true;
    }
    else
    {
        return false;
    }
    //qDebug() << query.lastQuery();

}

bool Datalayer::removeConnectionFromDB(int id)
{
    QSqlQuery query;

    stringstream ss1;
    ss1 << id;
    string str1 = ss1.str();

    if(query.exec("DELETE FROM connections where id = " + QString::fromStdString(str1.c_str())))
    {
        return true;
    }
    else
    {
        return false;
    }
    //qDebug() << query.lastQuery();

}

vector<Computer> Datalayer::pullComputer()
{
    vector<Computer>computervector;

    //Datalayer pull();
    QSqlQuery query(db);

        if(query.exec("SELECT * FROM computers"))
        {
            while(query.next())
            {
               int id = query.value("id").toUInt();
               string name = query.value("name").toString().toStdString();
               string computertype = query.value("computerType").toString().toStdString();
               int yearbuilt = query.value("yearBuilt").toUInt();
               bool wasbuilt = query.value("wasBuilt").toUInt();

               Computer comp(name,computertype,yearbuilt,wasbuilt);
               comp.setID(id);
               computervector.push_back(comp);

            }
        }


    return computervector;

}

//Les af gagnagrunn inn manneskjur setur það í vector
//og skilar honum
vector<person> Datalayer::pullPerson()
{
    vector<person>personvector;

    //Datalayer pull();
    QSqlQuery query(db);

        if(query.exec("SELECT * FROM persons"))
        {
            while(query.next())
            {
               int id = query.value("id").toUInt();
               string name = query.value("name").toString().toStdString();
               string gender = query.value("gender").toString().toStdString();
               int yearofbirth = query.value("yearOfBirth").toUInt();
               int yearofdeath = query.value("yearOfDeath").toUInt();

               person per(name,gender,yearofbirth,yearofdeath);
               per.setID(id);

               personvector.push_back(per);

            }
        }

    return personvector;
}

vector<Connections> Datalayer::pullConnections()
{
    vector<Connections>connectionsVector;

    //Datalayer pull();
    QSqlQuery query(db);

    if(query.exec("SELECT c.id, p.name AS S_Name, cp.name AS CP_Name FROM persons p JOIN connections c ON p.id = c.pId,computers  cp ON cp.id = c.cId"))
    {
        while(query.next())
        {
           int id = query.value("id").toUInt();
           string personName = query.value("S_Name").toString().toStdString();
           string computerName = query.value("CP_Name").toString().toStdString();

           Connections connect(personName,computerName);
           connect.setID(id);

           connectionsVector.push_back(connect);

        }
    }

    return connectionsVector;
}

vector<person> Datalayer::sortPersonByName()
{
    UI toScreen;
    vector<person>sortedVector;
    QSqlQuery query(db);

        if(query.exec("SELECT * FROM persons s ORDER BY s.name ASC"))
        {
            while(query.next())
            {

                int id = query.value("id").toUInt();
                string name = query.value("name").toString().toStdString();
                string gender = query.value("gender").toString().toStdString();
                int yearofbirth = query.value("yearOfBirth").toUInt();
                int yearofdeath = query.value("yearOfDeath").toUInt();

                person per(name,gender,yearofbirth,yearofdeath);
                per.setID(id);

                sortedVector.push_back(per);

            }
        }

        return sortedVector;

}

vector<person> Datalayer::sortPersonByAge()
{
    UI toScreen;
    vector<person>sortedVector;
    QSqlQuery query(db);

        if(query.exec("SELECT * FROM persons s ORDER BY s.age ASC"))
        {
            while(query.next())
            {
                int id = query.value("id").toUInt();
                string name = query.value("name").toString().toStdString();
                string gender = query.value("gender").toString().toStdString();
                int yearofbirth = query.value("yearOfBirth").toUInt();
                int yearofdeath = query.value("yearOfDeath").toUInt();

                person per(name,gender,yearofbirth,yearofdeath);
                per.setID(id);

                sortedVector.push_back(per);

            }
        }

        return sortedVector;

}

vector<Computer> Datalayer::sortComputerByName()
{
    UI toScreen;
    vector<Computer>sortedVector;
    QSqlQuery query(db);

        if(query.exec("SELECT * FROM computers s ORDER BY s.name ASC"))
        {
            while(query.next())
            {
               int id = query.value("id").toUInt();
               string name = query.value("name").toString().toStdString();
               string computertype = query.value("computerType").toString().toStdString();
               int yearbuilt = query.value("yearBuilt").toUInt();
               bool wasbuilt = query.value("wasBuilt").toUInt();

               Computer comp(name,computertype,yearbuilt,wasbuilt);
               comp.setID(id);
               sortedVector.push_back(comp);

            }
        }

        return sortedVector;

}
