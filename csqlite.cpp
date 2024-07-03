#include "csqlite.h"

csqlite::csqlite()
{
    m_db= QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("./studentInfoDB.db");
    if (!m_db.open())
    {
        QMessageBox::information(0, "Error", "Failed to open database!");
        return;
    }

    QSqlQuery query;
    QString sql=("CREATE TABLE IF NOT EXISTS Members ("
                 "Id INTEGER PRIMARY KEY,"
                 "Name VARCHAR(20) NOT NULL,"
                 "sex VARCHAR(2),"
                 "age INTEGER,"
                 "classname VARCHAR(20),"
                 "coursedate VARCHAR(20),"
                 "coursenum INTEGER,"
                 "coursename VARCHAR(20),"
                 "coursetype VARCHAR(20),"
                 "credit REAL,"
                 "courselauchtime VARCHAR(20)"
                 ");");
    if(!query.exec(sql))
    {
        QMessageBox::information(0, "Error", "Failed to create default table!");
        qDebug() << query.lastQuery();
        return;
    }
    m_db.close();
}

csqlite::~csqlite()
{

}

bool csqlite::selectStudentInfo(QList<cstudentinfo> &studentinfolist)
{
    if(!m_db.open())
    {
        QMessageBox::information(0, "Error", "Failed to open database when selectStudentInfo!");
        return false;
    }
    QSqlQuery query;
    QString sql=("SELECT * FROM Members;");
    if(!query.exec(sql))
    {
        QMessageBox::information(0, "Error", "Failed to query!");
        return false;
    }
    while(query.next())
    {
        cstudentinfo studentInfoTemp;
        int id = query.value("Id").toInt();
        QString name = query.value("Name").toString();
        QString sex = query.value("sex").toString();
        int age = query.value("age").toInt();
        QString classname = query.value("classname").toString();
        QString coursedate = query.value("coursedate").toString();
        int coursenum = query.value("coursenum").toInt();
        QString coursename = query.value("coursename").toString();
        QString coursetype = query.value("coursetype").toString();
        double credit = query.value("credit").toDouble();
        QString courselauchtime = query.value("courselauchtime").toString();

        studentInfoTemp.setData(id, name, sex, age, classname, coursedate, coursenum, coursename, coursetype, credit, courselauchtime);
        studentinfolist.append(studentInfoTemp);
    }
    m_db.close();
    return true;
}

bool csqlite::addStudentInfo(cstudentinfo studentinfos)
{

    return true;
}

bool csqlite::editStudentInfo(cstudentinfo studentinfos)
{

    return  true;
}

bool csqlite::deletStudentInfo(int Id)
{

    return true;
}
