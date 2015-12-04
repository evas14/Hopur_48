#include "datalayer.h"

//Smiður
Datalayer::Datalayer()
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

void Datalayer::addComputerToDB(Computer comp)
{

}

void Datalayer::addConnectionToDB(Connections connection)
{

}


//Skrifar vector í .txt skjal
void Datalayer::addPersonToDB(person per)
{

    /*QSqlQuery query;

    string name = per.getName();
    string gender = per.getGender();
    //query.exec("INSERT into person (name,gender,age,birthyear,deathyear)"
    + "values('" + name + "','" + gender + "','" + )

    query.exec("INSERT INTO customer_details (rationcard_num, aadharcard_num, name)"
                + "values('" + rationcard_num + "','" + aadharcard_num + "','"
                + name + "')");*/




}

void Datalayer::removeComputerFromDB(int id)
{

}

void Datalayer::removePersonFromDB(int id)
{

}

void Datalayer::removeConnectionFromDB(int id)
{

}

vector<Computer> Datalayer::pullComputer()
{

    //Þetta er kommentað út á meðan það er verið að búa til Computer töfluna
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
               int age = query.value("age").toUInt();
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

    if(query.exec("SELECT * FROM connection"))
    {
        while(query.next())
        {
           int id = query.value("id").toUInt();
           int personID = query.value("pId").toUInt();
           int computerID = query.value("cId").toUInt();

           Connections connect(personID,computerID);
           connect.setID(id);

           connectionsVector.push_back(connect);

        }
    }



    return connectionsVector;
}
