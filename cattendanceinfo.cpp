#include "cattendanceinfo.h"

cattendanceinfo::cattendanceinfo()
    : attendanceId(0), studentId(0), credit(0.0)
{
}

void cattendanceinfo::setData(int attendanceId, int studentId, QString coursedate, int coursenum, QString coursename, QString coursetype, double credit, QString courselauchtime) {
    this->attendanceId = attendanceId;
    this->studentId = studentId;
    this->coursedate = coursedate;
    this->coursenum = coursenum;
    this->coursename = coursename;
    this->coursetype = coursetype;
    this->credit = credit;
    this->courselauchtime = courselauchtime;
}

int cattendanceinfo::getAttendanceId() const {
    return attendanceId;
}

int cattendanceinfo::getStudentId() const {
    return studentId;
}

QString cattendanceinfo::getCoursedate() const {
    return coursedate;
}

int cattendanceinfo::getCoursenum() const {
    return coursenum;
}

QString cattendanceinfo::getCoursename() const {
    return coursename;
}

QString cattendanceinfo::getCoursetype() const {
    return coursetype;
}

double cattendanceinfo::getCredit() const {
    return credit;
}

QString cattendanceinfo::getCourselauchtime() const {
    return courselauchtime;
}

void cattendanceinfo::setAttendanceId(int value)
{
    attendanceId = value;
}

void cattendanceinfo::setStudentId(int value)
{
    studentId = value;
}

void cattendanceinfo::setCoursedate(const QString &value)
{
    coursedate = value;
}

void cattendanceinfo::setCoursenum(int value)
{
    coursenum = value;
}

void cattendanceinfo::setCoursename(const QString &value)
{
    coursename = value;
}

void cattendanceinfo::setCredit(double value)
{
    credit = value;
}

void cattendanceinfo::setCoursetype(const QString &value)
{
    coursetype = value;
}

void cattendanceinfo::setCourselauchtime(const QString &value)
{
    courselauchtime = value;
}
