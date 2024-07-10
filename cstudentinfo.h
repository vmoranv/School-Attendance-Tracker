//此类为student成员
#ifndef CSTUDENTINFO_H
#define CSTUDENTINFO_H

#include <QString>
#include <QList>
#include "cattendanceinfo.h"

class cstudentinfo:public cattendanceinfo
{
public:
    cstudentinfo();

    bool setData(int id, QString name, QString sex, int age, QString classname,
                 QString coursedate, int coursenum, QString coursename, QString coursetype,
                 double credit, QString courselauchtime);

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getSex() const;
    void setSex(const QString &value);

    int getAge() const;
    void setAge(int value);

    QString getClassname() const;
    void setClassname(const QString &value);

    QString getCoursedate() const;
    void setCoursedate(const QString &value);

    int getCoursenum() const;
    void setCoursenum(int value);

    QString getCoursename() const;
    void setCoursename(const QString &value);

    QString getCoursetype() const;
    void setCoursetype(const QString &value);

    double getCredit() const;
    void setCredit(double value);

    QString getCourselauchtime() const;
    void setCourselauchtime(const QString &value);

    // 添加考勤信息
    void addAttendanceInfo(const cattendanceinfo &attendanceInfo);

    // 获取考勤信息列表
    QList<cattendanceinfo> getAttendanceInfos() const;

    // 设置考勤信息列表
    void setAttendanceInfos(const QList<cattendanceinfo> &attendanceInfos);

private:
    int Id;
    QString Name;
    QString sex;
    int age;
    QString classname;
    QString coursedate;
    int coursenum;
    QString coursename;
    QString coursetype;
    double credit;
    QString courselauchtime;

    // 存储考勤信息
    QList<cattendanceinfo> attendanceInfos;
};

#endif // CSTUDENTINFO_H
