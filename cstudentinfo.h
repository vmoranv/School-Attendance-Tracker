//此类为student成员类

#ifndef CSTUDENTINFO_H
#define CSTUDENTINFO_H

#include <QString>


class cstudentinfo
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
};

#endif // CSTUDENTINFO_H
