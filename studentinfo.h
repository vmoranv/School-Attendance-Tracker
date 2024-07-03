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
     * @brief editStudentInfo 修改学生信息
     * @param studentinfos 指定学生信息
     * @return true or false
     */
    virtual bool editStudentInfo(cstudentinfo studentinfos) =0;

    /**
     * @brief deletStudentInfo 删除学生信息
     * @param Id 指定学生Id
     * @return true or false
     */
    virtual bool deletStudentInfo(int Id)=0;

};

#endif // STUDENTINFO_H
