//此类为sql操作类

#ifndef CSQLITE_H
#define CSQLITE_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

#include "studentinfo.h"
#include "cattendanceinfo.h"

class csqlite: public studentinfo
{
public:
    csqlite(const QString& dbName);
    ~csqlite();

// studentinfo interface
    bool selectStudentInfo(QList<cstudentinfo> &studentinfolist);
    bool addStudentInfo(cstudentinfo studentinfos);
    bool updateStudentInfo(cstudentinfo studentInfo);
    bool deleteSpecificAttendanceRecord(int attendanceId);
    bool queryStudentInfoByIdOrName(const QString &idCondition, const QString &nameCondition, QList<cstudentinfo> &result);
    bool queryAllStudentInfo(QList<cstudentinfo> &result);
    QSqlDatabase getDatabase();

    QSqlDatabase getDb();
    void setDb(const QSqlDatabase &db);
    QList<cstudentinfo> selectAllStudentInfo();

private:
    QSqlDatabase m_db;
};

#endif // CSQLITE_H
