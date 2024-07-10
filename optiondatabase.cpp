#include "optiondatabase.h"
#include "studentInfo.h"
#include <QSqlQuery>


optionDatabase::optionDatabase()
    : dataSource(NULL)
{
    students=QSqlDatabase::addDatabase("QSQLITE");
    students.setDatabaseName("./student.db");
    if (!students.open())
    {
        qDebug()<<"Failed to Open database";
        return;
    }
    QSqlQuery query;
    QString defaultsqlcreate=QString("CREATE TABLE if not exists students (id INT PRIMARY KEY,name VARCHAR(255),sex INT,age INT,classname VARCHAR(255),coursedate DATE,coursenum INT,coursename VARCHAR(255),coursetype VARCHAR(255),credit DECIMAL(5, 2),courselauchtime DATETIME);");
    if (!query.exec(defaultsqlcreate))
    {
        qDebug()<<"Failed to create table";
        qDebug()<<query.lastQuery();
        QMessageBox::warning(0,"失败","创建表失败");
        return;
    }
    students.close();
}

optionDatabase::~optionDatabase()
{
    delete dataSource;
}
