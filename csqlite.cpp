#include "csqlite.h"

csqlite::csqlite()
{
    m_db= QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("./studentInfoDB.db");
    if (!m_db.open())
    {
        QMessageBox::information(0, "Error", "Failed to open database!");
        return;
    }

    QSqlQuery query;
    QString sql=("CREATE TABLE IF NOT EXISTS Members ("
                 "Id INTEGER PRIMARY KEY,"
                 "Name VARCHAR(20) NOT NULL,"
                 "sex VARCHAR(2),"
                 "age INTEGER,"
                 "classname VARCHAR(12),"
                 "coursedate VARCHAR(12),"
                 "coursenum INTEGER,"
                 "coursename VARCHAR(12),"
                 "coursetype VARCHAR(3),"
                 "credit REAL,"
                 "courselauchtime VARCHAR(12)"
                 ");");
    if(!query.exec(sql))
    {
        QMessageBox::information(0, "Error", "Failed to create default table!");
        qDebug() << query.lastQuery();
        return;
    }
    m_db.close();
}

csqlite::~csqlite()
{

}

bool csqlite::selectStudentInfo(QList<cstudentinfo> &studentinfolist)
{
    if(!m_db.open())
    {
        QMessageBox::information(0, "Error", "Failed to open database when selectStudentInfo!");
        return false;
    }
    QSqlQuery query;
    QString sql=("SELECT * FROM Members;");
    if(!query.exec(sql))
    {
        QMessageBox::information(0, "Error", "Failed to query!");
        return false;
    }
    while(query.next())
    {
        cstudentinfo studentInfoTemp;
        int id = query.value("Id").toInt();
        QString name = query.value("Name").toString();
        QString sex = query.value("sex").toString();
        int age = query.value("age").toInt();
        QString classname = query.value("classname").toString();
        QString coursedate = query.value("coursedate").toString();
        int coursenum = query.value("coursenum").toInt();
        QString coursename = query.value("coursename").toString();
        QString coursetype = query.value("coursetype").toString();
        double credit = query.value("credit").toDouble();
        QString courselauchtime = query.value("courselauchtime").toString();

        studentInfoTemp.setData(id, name, sex, age, classname, coursedate, coursenum, coursename, coursetype, credit, courselauchtime);
        studentinfolist.append(studentInfoTemp);
    }
    m_db.close();
    return true;
}

bool csqlite::addStudentInfo(cstudentinfo studentInfo)
{
    if (!m_db.open()) {
        QMessageBox::critical(0, "Error", "Failed to open database!");
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Members (Id, Name, sex, age, classname, coursedate, coursenum, coursename, coursetype, credit, courselauchtime) "
                  "VALUES (:id, :name, :sex, :age, :classname, :coursedate, :coursenum, :coursename, :coursetype, :credit, :courselauchtime);");

    query.bindValue(":id", studentInfo.getId());
    query.bindValue(":name", studentInfo.getName());
    query.bindValue(":sex", studentInfo.getSex());
    query.bindValue(":age", studentInfo.getAge());
    query.bindValue(":classname", studentInfo.getClassname());
    query.bindValue(":coursedate", studentInfo.getCoursedate());
    query.bindValue(":coursenum", studentInfo.getCoursenum());
    query.bindValue(":coursename", studentInfo.getCoursename());
    query.bindValue(":coursetype", studentInfo.getCoursetype());
    query.bindValue(":credit", studentInfo.getCredit());
    query.bindValue(":courselauchtime", studentInfo.getCourselauchtime());

    if (!query.exec()) {
        qDebug() << "Error adding student info:" << query.lastQuery();
        m_db.close();
        return false;
    }

    m_db.close();
    return true;
}

bool csqlite::editStudentInfo(cstudentinfo studentInfo)
{
    if (!m_db.open()) {
        QMessageBox::critical(0, "Error", "Failed to open database!");
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE Members SET Name = :name, sex = :sex, age = :age, classname = :classname, "
                  "coursedate = :coursedate, coursenum = :coursenum, coursename = :coursename, "
                  "coursetype = :coursetype, credit = :credit, courselauchtime = :courselauchtime WHERE Id = :id");

    query.bindValue(":id", studentInfo.getId());
    query.bindValue(":name", studentInfo.getName());
    query.bindValue(":sex", studentInfo.getSex());
    query.bindValue(":age", studentInfo.getAge());
    query.bindValue(":classname", studentInfo.getClassname());
    query.bindValue(":coursedate", studentInfo.getCoursedate());
    query.bindValue(":coursenum", studentInfo.getCoursenum());
    query.bindValue(":coursename", studentInfo.getCoursename());
    query.bindValue(":coursetype", studentInfo.getCoursetype());
    query.bindValue(":credit", studentInfo.getCredit());
    query.bindValue(":courselauchtime", studentInfo.getCourselauchtime());

    if (!query.exec()) {
        qDebug() << "Error editing student info:" << query.lastQuery();
        m_db.close();
        return false;
    }

    m_db.close();
    return true;
}

bool csqlite::deletStudentInfo(int Id)
{
    if (!m_db.open()) {
        QMessageBox::critical(0, "Error", "Failed to open database!");
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM Members WHERE Id = :id");
    query.bindValue(":id", Id);

    if (!query.exec()) {
        qDebug() << "Error deleting student info:" << query.lastQuery();
        m_db.close();
        return false;
    }

    m_db.close();
    return true;
}
