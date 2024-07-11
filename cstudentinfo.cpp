#include "cstudentinfo.h"
#include "qdebug.h"
cstudentinfo::cstudentinfo()
{

}

bool cstudentinfo::setData(int id, QString name, QString sex, int age, QString classname, QString coursedate, int coursenum, QString coursename, QString coursetype, double credit, QString courselauchtime)
{
    qDebug()<<"setData id"<<id;
    this->Id = id;
    this->Name = name;
    this->sex = sex;
    this->age = age;
    this->classname = classname;
    this->coursedate = coursedate;
    this->coursenum = coursenum;
    this->coursename = coursename;
    this->coursetype = coursetype;
    this->credit = credit;
    this->courselauchtime = courselauchtime;
    return true;
}

int cstudentinfo::getId() const
{
    return Id;
}

void cstudentinfo::setId(int value)
{
    Id = value;
}

QString cstudentinfo::getName() const
{
    return Name;
}

void cstudentinfo::setName(const QString &value)
{
    Name = value;
}

QString cstudentinfo::getSex() const
{
    return sex;
}

void cstudentinfo::setSex(const QString &value)
{
    sex = value;
}

int cstudentinfo::getAge() const
{
    return age;
}

void cstudentinfo::setAge(int value)
{
    age = value;
}

QString cstudentinfo::getClassname() const
{
    return classname;
}

void cstudentinfo::setClassname(const QString &value)
{
    classname = value;
}

QString cstudentinfo::getCoursedate() const
{
    return coursedate;
}

void cstudentinfo::setCoursedate(const QString &value)
{
    coursedate = value;
}

int cstudentinfo::getCoursenum() const
{
    return coursenum;
}

void cstudentinfo::setCoursenum(int value)
{
    coursenum = value;
}

QString cstudentinfo::getCoursename() const
{
    return coursename;
}

void cstudentinfo::setCoursename(const QString &value)
{
    coursename = value;
}

QString cstudentinfo::getCoursetype() const
{
    return coursetype;
}

void cstudentinfo::setCoursetype(const QString &value)
{
    coursetype = value;
}

double cstudentinfo::getCredit() const
{
    return credit;
}

void cstudentinfo::setCredit(double value)
{
    credit = value;
}

QString cstudentinfo::getCourselauchtime() const
{
    return courselauchtime;
}

void cstudentinfo::setCourselauchtime(const QString &value)
{
    courselauchtime = value;
}

void cstudentinfo::addAttendanceInfo(const cattendanceinfo &attendanceInfo) {
    attendanceInfos.append(attendanceInfo);
}

QList<cattendanceinfo> cstudentinfo::getAttendanceInfos() const {
    return attendanceInfos;
}

void cstudentinfo::setAttendanceInfos(const QList<cattendanceinfo> &attendanceInfos) {
    this->attendanceInfos = attendanceInfos;
}

cattendanceinfo cstudentinfo::getSpecificAttendanceInfo(int attendanceId) const {
    for (const auto& attendanceInfo : attendanceInfos) {
        if (attendanceInfo.getAttendanceId() == attendanceId) {
            return attendanceInfo;
        }
    }
    return cattendanceinfo();
}
