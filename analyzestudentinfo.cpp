#include "analyzestudentinfo.h"
#include "ui_analyzestudentinfo.h"

analyzestudentinfo::analyzestudentinfo(QWidget *parent) :
QDialog(parent),
ui(new Ui::analyzestudentinfo)
{
    ui->setupUi(this);
    m_standarditemmodel = new QStandardItemModel(this);
    ui->tableView->setModel(m_standarditemmodel);
    initUI();

}

analyzestudentinfo::~analyzestudentinfo()
{
    delete ui;
}

bool analyzestudentinfo::appendTomodel(cstudentinfo &studentinfo)
{
    QStandardItem *itemAttendaceid = new QStandardItem(QString::number(studentinfo.getAttendanceId()));
    QStandardItem *itemId = new QStandardItem(QString::number(studentinfo.getId()));
    QStandardItem *itemName = new QStandardItem(studentinfo.getName());
    QStandardItem *itemSex = new QStandardItem(studentinfo.getSex());
    QStandardItem *itemAge = new QStandardItem(QString::number(studentinfo.getAge()));
    QStandardItem *itemClassname = new QStandardItem(studentinfo.getClassname());
    QStandardItem *itemCoursedate = new QStandardItem(studentinfo.getCoursedate());
    QStandardItem *itemCoursenum = new QStandardItem(QString::number(studentinfo.getCoursenum()));
    QStandardItem *itemCoursename = new QStandardItem(studentinfo.getCoursename());
    QStandardItem *itemCoursetype = new QStandardItem(studentinfo.getCoursetype());
    QStandardItem *itemCredit = new QStandardItem(QString::number(studentinfo.getCredit()));
    QStandardItem *itemCourselauchtime = new QStandardItem(studentinfo.getCourselauchtime());
    QList<QStandardItem*> rowItems;
    rowItems << itemAttendaceid << itemId << itemName << itemSex << itemAge << itemClassname << itemCoursedate << itemCoursenum << itemCoursename << itemCoursetype << itemCredit << itemCourselauchtime;
    m_standarditemmodel->appendRow(rowItems);
    return true;

}

void analyzestudentinfo::fillTableView(QList<cstudentinfo>& result)
{
    int rowCount = m_standarditemmodel->rowCount();

    if (rowCount > 0)
    {
        m_standarditemmodel->removeRows(0, rowCount);
    }

    for (auto &stuInfo : result) {
    appendTomodel(stuInfo);
    }
}

QList<cstudentinfo> analyzestudentinfo::passedStudentInfoList() const
{
    return m_passedStudentInfoList;
}

void analyzestudentinfo::setPassedStudentInfoList(const QList<cstudentinfo> &passedStudentInfoList)
{
    m_passedStudentInfoList = passedStudentInfoList;
}

void analyzestudentinfo::initUI()
{
    QStringList headerList;
    headerList << "考勤ID" <<"学号" << "姓名" << "性别" << "年龄" << "班级" << "缺课日期" << "第几节课" << "课程名称" << "缺课类型" << "学分" << "开课时间";
    m_standarditemmodel = new QStandardItemModel(this);
    m_standarditemmodel->setHorizontalHeaderLabels(headerList);
    ui->tableView->setModel(m_standarditemmodel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSortingEnabled(true);
    QTimer::singleShot(100, this, [this]() { on_pushButton_clicked(); });

}

void analyzestudentinfo::on_pushButton_clicked()
{
    QMap<QString, QString> fieldNameMap = {
        {"考勤ID", "attendanceId"},
        {"学号", "Id"},
        {"姓名", "Name"},
        {"年龄", "age"},
        {"班级", "classname"},
        {"缺课日期", "coursedate"},
        {"第几节课", "coursenum"},
        {"课程名称", "coursename"},
        {"缺课类型", "coursetype"},
    };

    QString field = ui->comboBox->currentText();
    QString value = ui->lineEdit->text();
    if (field.isEmpty() || value.isEmpty()) {
        fillTableView(m_passedStudentInfoList);
        return;
    }

    QString fieldEng = fieldNameMap[field];
    int rowCount = m_standarditemmodel->rowCount();
    if (rowCount > 0)
    {
        m_standarditemmodel->removeRows(0, rowCount);
    }

    for (auto &stuInfo : m_passedStudentInfoList)
    {
        if(fieldEng == "attendanceId" && stuInfo.getAttendanceId() == value.toInt())
        {
            appendTomodel(stuInfo);
        }
        else if (fieldEng == "Id" && stuInfo.getId() == value.toInt())
        {
            appendTomodel(stuInfo);

        } else if (fieldEng == "Name" && stuInfo.getName() == value)
        {
            appendTomodel(stuInfo);
        } else if (fieldEng == "age" && stuInfo.getAge() == value.toInt())
        {
            appendTomodel(stuInfo);
        } else if (fieldEng == "classname" && stuInfo.getClassname() == value)
        {
            appendTomodel(stuInfo);
        } else if (fieldEng == "coursedate" && stuInfo.getCoursedate() == value)
        {
            appendTomodel(stuInfo);
        } else if (fieldEng == "coursenum" && stuInfo.getCoursenum() == value.toInt())
        {
            appendTomodel(stuInfo);
        } else if (fieldEng == "coursename" && stuInfo.getCoursename() == value)
        {
            appendTomodel(stuInfo);
        } else if (fieldEng == "coursetype" && stuInfo.getCoursetype() == value)
        {
            appendTomodel(stuInfo);
        }
    }
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
