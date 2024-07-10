//此类为api声明

#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QList>

#include "cstudentinfo.h"

class studentinfo
{
public:
    studentinfo();
    virtual ~studentinfo();

    /**
     * @brief selectStudentInfo 查询所有学生信息
     * @param studentinfos 指定学生的信息
     * @return true or false
     */
    virtual bool selectStudentInfo(QList<cstudentinfo> &studentinfolist) =0;

    /**
     * @brief addStudentInfo 添加学生信息
     * @param studentinfos 指定学生信息
     * @return true or false
     */
    virtual bool addStudentInfo(cstudentinfo studentinfos) =0;

    /**
     * @brief updateStudentInfo 修改学生信息
     * @param studentinfos 指定学生信息
     * @return true or false
     */
    virtual bool updateStudentInfo(cstudentinfo studentInfo) =0;

    /**
     * @brief deleteSpecificAttendanceRecord 删除学生信息
     * @param studentId 指定学生Id attendanceId 对应Attendance考勤信息
     * @return true or false
     */
    virtual bool deleteSpecificAttendanceRecord(int attendanceId)=0;


};

#endif // STUDENTINFO_H
