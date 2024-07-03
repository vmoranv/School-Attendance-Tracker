//此类为sql操作类

#ifndef CSQLITE_H
#define CSQLITE_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

#include "studentinfo.h"


class csqlite: public studentinfo
{
public:
    csqlite();
    ~csqlite();

// studentinfo interface
    bool selectStudentInfo(QList<cstudentinfo> &studentinfolist);
    bool addStudentInfo(cstudentinfo studentinfos);
    bool editStudentInfo(cstudentinfo studentinfos);
    bool deletStudentInfo(int Id);

private:
    QSqlDatabase m_db;
};

#endif // CSQLITE_H
