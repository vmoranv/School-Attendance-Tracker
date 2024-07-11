#include "csqlite.h"

csqlite::csqlite(const QString& dbName) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbName);
    if (!m_db.open()) {
        qWarning() << "Failed to open database:" << dbName;
        return;
    }

    QSqlQuery query;
    QString sql = ("CREATE TABLE IF NOT EXISTS Members ("
                   "Id INTEGER PRIMARY KEY, "
                   "Name VARCHAR(20) NOT NULL,"
                   "Sex VARCHAR(2),"
                   "Age INTEGER,"
                   "Classname VARCHAR(12)"
                   ");");
    if (!query.exec(sql)) {
        qWarning() << "Failed to create default table in database:" << dbName;
        qDebug() << query.lastQuery();
        return;
    }

    QString sqlAttendance = ("CREATE TABLE IF NOT EXISTS Attendance ("
                             "AttendanceId INTEGER PRIMARY KEY AUTOINCREMENT,"
                             "StudentId INTEGER,"
                             "Coursedate VARCHAR(12),"
                             "Coursenum INTEGER,"
                             "Coursename VARCHAR(12),"
                             "Coursetype VARCHAR(3),"
                             "Credit REAL,"
                             "Courselauchtime VARCHAR(12),"
                             "FOREIGN KEY(StudentId) REFERENCES Members(Id) ON DELETE CASCADE"
                             ");");

    if (!query.exec(sqlAttendance)) {
        qWarning() << "Failed to create Attendance table in database:" << dbName;
        qDebug() << query.lastQuery();
        return;
    }
}

csqlite::~csqlite()
{

}

// 查询所有学生信息
bool csqlite::selectStudentInfo(QList<cstudentinfo> &studentinfolist)
{
    QSqlQuery query;
    query.exec("SELECT A.AttendanceId, M.Id, M.Name, M.Sex, M.Age, M.Classname, A.Coursedate, A.Coursenum, A.Coursename, A.Coursetype, A.Credit, A.Courselauchtime "
               "FROM Attendance A "
               "JOIN Members M ON A.StudentId = M.Id "
               "ORDER BY A.AttendanceId");

    while (query.next()) {
        cstudentinfo info;
        info.setId(query.value(1).toInt());
        info.setAttendanceId(query.value(0).toInt());
        info.setName(query.value(2).toString());
        info.setSex(query.value(3).toString());
        info.setAge(query.value(4).toInt());
        info.setClassname(query.value(5).toString());
        info.setCoursedate(query.value(6).toString());
        info.setCoursenum(query.value(7).toInt());
        info.setCoursename(query.value(8).toString());
        info.setCoursetype(query.value(9).toString());
        info.setCredit(query.value(10).toDouble());
        info.setCourselauchtime(query.value(11).toString());

        studentinfolist.append(info);
    }

    return true;
}

// 添加单条学生信息
bool csqlite::addStudentInfo(cstudentinfo studentInfo)
{
    qDebug() << "Adding student info:" << studentInfo.getId();

    if (!m_db.open()) {
        QMessageBox::critical(0, "Error", "Failed to open database!");
        return false;
    }

    QSqlQuery query;

    // 检查学生是否已存在
    query.prepare("SELECT COUNT(*) FROM Members WHERE Id = :id;");
    query.bindValue(":id", studentInfo.getId());
    if (!query.exec() || !query.next()) {
        qDebug() << "Error checking existing student:" << query.lastQuery();
        return false;
    }
    int count = query.value(0).toInt();

    bool studentExists = (count > 0);
    if (!studentExists) {
        // 插入成员信息到Members表
        query.prepare("INSERT INTO Members (Id, Name, Sex, Age, Classname) "
                      "VALUES (:id, :name, :sex, :age, :classname);");

        query.bindValue(":id", studentInfo.getId());
        query.bindValue(":name", studentInfo.getName());
        query.bindValue(":sex", studentInfo.getSex());
        query.bindValue(":age", studentInfo.getAge());
        query.bindValue(":classname", studentInfo.getClassname());

        qDebug() << "SQL Query to be executed for Members table:" << query.executedQuery();

        if (!query.exec()) {
            qDebug() << "Error inserting into Members table:" << query.lastQuery();
            return false;
        }
    }

    // 处理出勤信息
    if (studentInfo.getCoursedate()!="0") {
        query.prepare("INSERT INTO Attendance (StudentId, Coursedate, Coursenum, Coursename, Coursetype, Credit, Courselauchtime) "
                      "VALUES (:studentId, :coursedate, :coursenum, :coursename, :coursetype, :credit, :courselauchtime);");

        qDebug()<<studentInfo.getId();
        query.bindValue(":studentId", studentInfo.getId());
        query.bindValue(":coursedate", studentInfo.getCoursedate());
        query.bindValue(":coursenum", studentInfo.getCoursenum());
        query.bindValue(":coursename", studentInfo.getCoursename());
        query.bindValue(":coursetype", studentInfo.getCoursetype());
        query.bindValue(":credit", studentInfo.getCredit());
        query.bindValue(":courselauchtime", studentInfo.getCourselauchtime());

        if (!query.exec()) {
            qDebug() << "Error inserting into Attendance table:" << query.lastQuery();
            return false;
        }
    }

    return true;
}

bool csqlite::updateStudentInfo(cstudentinfo studentInfo)
{
    qDebug()<<"Updating student info and specific attendance record:"<< studentInfo.getId()<<studentInfo.getAttendanceId();


    if (!m_db.open()) {
        QMessageBox::critical(0, "Error", "Failed to open database!");
        return false;
    }

    QSqlQuery query;

    // 更新学生基本信息
    query.prepare("UPDATE Members SET Name = :name, Sex = :sex, Age = :age, Classname = :classname "
                  "WHERE Id = :id");

    query.bindValue(":id", studentInfo.getId());
    query.bindValue(":name", studentInfo.getName());
    query.bindValue(":sex", studentInfo.getSex());
    query.bindValue(":age", studentInfo.getAge());
    query.bindValue(":classname", studentInfo.getClassname());

    if (!query.exec()) {
        qDebug() << "Error updating Members table:" << query.lastQuery();
        return false;
    }
    qDebug()<<"Success updating Members table" << query.lastQuery();

    qDebug()<<studentInfo.getAttendanceId()<<studentInfo.getCoursedate();

    if (studentInfo.getAttendanceId() != 0) {
        // 更新考勤信息
        query.prepare("UPDATE Attendance SET StudentId = :studentId, Coursedate = :coursedate, "
                      "Coursenum = :coursenum, Coursename = :coursename, Coursetype = :coursetype, "
                      "Credit = :credit, Courselauchtime = :courselauchtime "
                      "WHERE AttendanceId = :attendanceId");

        query.bindValue(":attendanceId", studentInfo.getAttendanceId());
        query.bindValue(":studentId", studentInfo.getId());
        query.bindValue(":coursedate", studentInfo.getCoursedate());
        query.bindValue(":coursenum", studentInfo.getCoursenum());
        query.bindValue(":coursename", studentInfo.getCoursename());
        query.bindValue(":coursetype", studentInfo.getCoursetype());
        query.bindValue(":credit", studentInfo.getCredit());
        query.bindValue(":courselauchtime", studentInfo.getCourselauchtime());

        qDebug()<<query.lastQuery();
        if (!query.exec()) {
            qDebug() << "Error updating Attendance table:" << query.lastQuery();
            return false;
        }
        qDebug()<<"Success updating Attendance table for attendance ID:" << studentInfo.getAttendanceId();
    }

    return true;
}

// 删除指定考勤记录
bool csqlite::deleteSpecificAttendanceRecord(int attendanceId)
{
    if (!m_db.open()) {
        QMessageBox::critical(0, "Error", "Failed to open database!");
        return false;
    }

    QSqlQuery query;
    // 只使用attendanceId作为WHERE子句的条件
    query.prepare("DELETE FROM Attendance WHERE AttendanceId = :attendanceId");
    query.bindValue(":attendanceId", attendanceId);

    if (!query.exec()) {
        qDebug() << "Error deleting specific attendance record:" << query.lastQuery();
        return false;
    }

    return true;
}

// 根据学号或姓名查询学生信息
bool csqlite::queryStudentInfoByIdOrName(const QString &idCondition, const QString &nameCondition, QList<cstudentinfo> &result)
{
    qDebug()<<idCondition;
    qDebug()<<nameCondition;
    if (!m_db.isOpen() && !m_db.open()) {
        qDebug() << "Failed to open database.";
        return false;
    }

    QSqlQuery query(m_db);
    QString sql;
    if (!idCondition.isEmpty() && !nameCondition.isEmpty()) {
        sql = QString("SELECT * FROM Members WHERE Id = '%1' AND Name = '%2';").arg(idCondition).arg(nameCondition);
    } else if (!idCondition.isEmpty()) {
        sql = QString("SELECT * FROM Members WHERE Id = '%1';").arg(idCondition);
        qDebug()<<sql;
    } else if (!nameCondition.isEmpty()) {
        sql = QString("SELECT * FROM Members WHERE Name = '%1';").arg(nameCondition);
    } else {
        qDebug() << "Neither ID nor Name provided for query.";
        return false;
    }

    qDebug()<< query.exec(sql);

    bool hasResults = false;
    while (query.next()) {
        hasResults = true;
        cstudentinfo stuInfo;
        stuInfo.setId(query.value("Id").toInt());
        stuInfo.setName(query.value("Name").toString());
        stuInfo.setSex(query.value("Sex").toString());
        stuInfo.setAge(query.value("Age").toInt());
        stuInfo.setClassname(query.value("Classname").toString());

        QSqlQuery attendanceQuery(m_db);
        attendanceQuery.prepare("SELECT * FROM Attendance WHERE StudentId = ?");
        attendanceQuery.bindValue(0, stuInfo.getId());
        qDebug()<<attendanceQuery.lastQuery();
        if (!attendanceQuery.exec()) {
            qDebug() << "Failed to query attendance information: " << attendanceQuery.lastQuery();
        }
        while (attendanceQuery.next()) {
            cattendanceinfo attendanceInfo;
            attendanceInfo.setAttendanceId(attendanceQuery.value("AttendanceId").toInt());
            attendanceInfo.setCoursedate(attendanceQuery.value("Coursedate").toString());
            attendanceInfo.setCoursenum(attendanceQuery.value("Coursenum").toInt());
            attendanceInfo.setCoursename(attendanceQuery.value("Coursename").toString());
            attendanceInfo.setCoursetype(attendanceQuery.value("Coursetype").toString());
            attendanceInfo.setCredit(attendanceQuery.value("Credit").toDouble());
            attendanceInfo.setCourselauchtime(attendanceQuery.value("Courselauchtime").toString());

            stuInfo.addAttendanceInfo(attendanceInfo);
            qDebug()<<attendanceInfo.getCredit();
        }

        qDebug()<<stuInfo.getCourselauchtime();
        result.append(stuInfo);
    }
    if (!hasResults) {
        qDebug() << "No records found that match the query criteria.";
    }

    return true;
}

QSqlDatabase csqlite::getDb()
{
    if(!m_db.isOpen())
    {
        qDebug()<<"m_db is not open!";
    }
    return m_db;
}

void csqlite::setDb(const QSqlDatabase &db)
{
    m_db = db;
}

// 查询所有学生信息并返回为缓存格式的QList
QList<cstudentinfo> csqlite::selectAllStudentInfo()
{
    QList<cstudentinfo> studentInfoList;

    QSqlQuery query(m_db);
    query.exec("SELECT * FROM Members");

    while (query.next()) {
        cstudentinfo stuInfo;
        stuInfo.setId(query.value("Id").toInt());
        stuInfo.setName(query.value("Name").toString());
        stuInfo.setSex(query.value("sex").toString());
        stuInfo.setAge(query.value("age").toInt());
        stuInfo.setClassname(query.value("classname").toString());

        // Query attendance information for the student and add it to the cstudentinfo object.
        QSqlQuery attendanceQuery(m_db);
        attendanceQuery.prepare("SELECT * FROM Attendance WHERE StudentId = ?");
        attendanceQuery.addBindValue(stuInfo.getId());
        attendanceQuery.exec();

        while (attendanceQuery.next()) {
            cattendanceinfo attendanceInfo;
            attendanceInfo.setAttendanceId(attendanceQuery.value("AttendanceId").toInt());
            attendanceInfo.setStudentId(attendanceQuery.value("StudentId").toInt());
            attendanceInfo.setCoursedate(attendanceQuery.value("Coursedate").toString());
            attendanceInfo.setCoursenum(attendanceQuery.value("Coursenum").toInt());
            attendanceInfo.setCoursename(attendanceQuery.value("Coursename").toString());
            attendanceInfo.setCoursetype(attendanceQuery.value("Coursetype").toString());
            attendanceInfo.setCredit(attendanceQuery.value("Credit").toDouble());
            attendanceInfo.setCourselauchtime(attendanceQuery.value("Courselauchtime").toString());

            stuInfo.addAttendanceInfo(attendanceInfo);
        }

        studentInfoList.append(stuInfo);
    }

    return studentInfoList;
}

// 查询所有学生信息并返回为缓存格式的QList,使用bool型
bool csqlite::queryAllStudentInfo(QList<cstudentinfo> &result)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * FROM Members");
    if (!query.exec())
    {
        qDebug() << "Failed to execute query: " << query.lastQuery();
        return false;
    }

    while (query.next()) {
        cstudentinfo stuInfo;
        stuInfo.setId(query.value("id").toInt());
        stuInfo.setName(query.value("name").toString());
        stuInfo.setSex(query.value("sex").toString());
        stuInfo.setAge(query.value("age").toInt());
        stuInfo.setClassname(query.value("classname").toString());

        QSqlQuery attendanceQuery(m_db);
        attendanceQuery.prepare("SELECT * FROM Attendance WHERE StudentId = ?");
        attendanceQuery.bindValue(0, stuInfo.getId());
        if (!attendanceQuery.exec()) {
            qDebug() << "Failed to execute attendance query: " << attendanceQuery.lastQuery();
            return false;
        }

        while (attendanceQuery.next()) {
            cattendanceinfo attendanceInfo;
            attendanceInfo.setAttendanceId(attendanceQuery.value("AttendanceId").toInt());
            attendanceInfo.setStudentId(attendanceQuery.value("StudentId").toInt());
            attendanceInfo.setCoursedate(attendanceQuery.value("Coursedate").toString());
            attendanceInfo.setCoursenum(attendanceQuery.value("Coursenum").toInt());
            attendanceInfo.setCoursename(attendanceQuery.value("Coursename").toString());
            attendanceInfo.setCoursetype(attendanceQuery.value("Coursetype").toString());
            attendanceInfo.setCredit(attendanceQuery.value("Credit").toDouble());
            attendanceInfo.setCourselauchtime(attendanceQuery.value("Courselauchtime").toString());

            stuInfo.addAttendanceInfo(attendanceInfo);
        }

        result.append(stuInfo);
    }

    return true;
}
