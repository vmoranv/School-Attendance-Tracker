#ifndef OPTIONDATABASE_H
#define OPTIONDATABASE_H

#include "studentInfo.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class optionDatabase:public studentInfo
{
public:
    optionDatabase();
    virtual ~optionDatabase()=0;
    virtual bool selectstuInfos(QList<studentInfo> &stuInfosList)=0;
    virtual bool addstuInfos(studentInfo &stuInfos)=0;
    virtual bool delstuInfos(int Id)=0;
    virtual bool editstuInfos(studentInfo &stuInfos)=0;

protected:
    QSqlDatabase students;
    studentInfo *dataSource;
};

#endif // OPTIONDATABASE_H
