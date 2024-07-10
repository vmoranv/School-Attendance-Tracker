#include "studentInfo.h"

studentInfo::studentInfo()
{

}

int studentInfo::getId() const
{
    return Id;
}

void studentInfo::setId(int value)
{
    Id = value;
}

QString studentInfo::getName() const
{
    return Name;
}

void studentInfo::setName(const QString &value)
{
    Name = value;
}

QString studentInfo::getSex() const
{
    return Name;
}

void studentInfo::setSex(const QString &value)
{
    Name = value;
}

int studentInfo::getAge() const
{
    return age;
}

void studentInfo::setAge(int value)
{
    age = value;
}

QString studentInfo::getClassname() const
{
    return classname;
}

void studentInfo::setClassname(const QString &value)
{
    classname = value;
}

QString studentInfo::getCoursedate() const
{
    return coursedate;
}

void studentInfo::setCoursedate(const QString &value)
{
    coursedate = value;
}

int studentInfo::getCoursenum() const
{
    return coursenum;
}

void studentInfo::setCoursenum(int value)
{
    coursenum = value;
}

QString studentInfo::getCoursename() const
{
    return coursename;
}

void studentInfo::setCoursename(const QString &value)
{
    coursename = value;
}

QString studentInfo::getCoursetype() const
{
    return coursetype;
}

void studentInfo::setCoursetype(const QString &value)
{
    coursetype = value;
}

double studentInfo::getCredit() const
{
    return credit;
}

void studentInfo::setCredit(double value)
{
    credit = value;
}

QString studentInfo::getCourselauchtime() const
{
    return courselauchtime;
}

void studentInfo::setCourselauchtime(const QString &value)
{
    courselauchtime = value;
}


bool studentInfo::setData(int Id, QString Name, QString sex, int age, QString classname, QString coursedate, int coursenum, QString coursename, QString coursetype, double credit, QString courselauchtime)
{
    this->Id=Id;
    this->Name=Name;
    this->sex=sex;
    this->age=age;
    this->classname=classname;
    this->coursedate=coursedate;
    this->coursenum=coursenum;
    this->coursename=coursename;
    this->coursetype=coursetype;
    this->credit=credit;
    this->courselauchtime=courselauchtime;

    return true;
}
