//操作attendance
#ifndef CATTENDANCEINFO_H
#define CATTENDANCEINFO_H

#include <QString>

class cattendanceinfo {
public:
    cattendanceinfo();

    void setData(int attendanceId, int studentId, QString coursedate, int coursenum, QString coursename, QString coursetype, double credit, QString courselauchtime);
    int getAttendanceId() const;
    int getStudentId() const;
    QString getCoursedate() const;
    int getCoursenum() const;
    QString getCoursename() const;
    QString getCoursetype() const;
    double getCredit() const;
    QString getCourselauchtime() const;

    void setAttendanceId(int value);

    void setStudentId(int value);

    void setCoursedate(const QString &value);

    void setCoursenum(int value);

    void setCoursename(const QString &value);

    void setCredit(double value);

    void setCoursetype(const QString &value);

    void setCourselauchtime(const QString &value);


private:
    int attendanceId;
    int studentId;
    QString coursedate;
    int coursenum;
    QString coursename;
    QString coursetype;
    double credit;
    QString courselauchtime;
};

#endif // CATTENDANCEINFO_H
