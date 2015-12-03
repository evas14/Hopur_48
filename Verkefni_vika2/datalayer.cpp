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


//Skrifar vector í .txt skjal
void Datalayer::addPerson(person per)
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

vector<Computer> Datalayer::pullComputer()
{
   /* vector<Computer>computervector;

    //Datalayer pull();
    QSqlQuery query(db);

        if(query.exec("SELECT * FROM computer"))
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


     db.close();


    return personvector;

    */



}

//Les af gagnagrunn inn manneskjur setur það í vector
//skilar
vector<person> Datalayer::pullPerson()
{
    vector<person>personvector;

    //Datalayer pull();
    QSqlQuery query(db);

        if(query.exec("SELECT * FROM person"))
        {
            while(query.next())
            {
               int id = query.value("id").toUInt();
               string name = query.value("name").toString().toStdString();
               string gender = query.value("gender").toString().toStdString();
               int age = query.value("age").toUInt();
               int yearofbirth = query.value("yearofbirth").toUInt();
               int yearofdeath = query.value("yearofdeath").toUInt();

               person per(name,gender,yearofbirth,yearofdeath);
               per.setID(id);

               personvector.push_back(per);

            }
        }


     db.close();


    return personvector;
}
