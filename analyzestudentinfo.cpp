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

void analyzestudentinfo::setTheme(bool isDarkMode)
{

    if (!isDarkMode) {
        this->setStyleSheet("QWidget { background-color: black; color: white; } ");
        ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: #333; color: white; }");
        ui->tableView->setStyleSheet("QTableView { background-color: #333; color: white; }");
        ui->lineEdit->setStyleSheet("QLineEdit { background-color: #333; color: white; }");
        ui->comboBox->setStyleSheet("QComboBox { background-color: #333; color: white; }");
        ui->comboBox_2->setStyleSheet("QComboBox { background-color: #333; color: white; }");
        ui->lineEdit_2->setStyleSheet("QLineEdit { background-color: #333; color: white; }");
        ui->pushButton->setStyleSheet("QPushButton { background-color: #555; color: white; }");
    } else {
        this->setStyleSheet("QWidget { background-color: white; color: black; } ");
        ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: #DDD; color: black; }");
        ui->tableView->setStyleSheet("QTableView { background-color: white; color: black; }");
        ui->lineEdit->setStyleSheet("QLineEdit { background-color: white; color: black; border: 1px solid #CCC; }");
        ui->comboBox->setStyleSheet("QComboBox { background-color: white; color: black; border: 1px solid #AAA; }");
        ui->comboBox_2->setStyleSheet("QComboBox { background-color: white; color: black; border: 1px solid #AAA; }");
        ui->lineEdit_2->setStyleSheet("QLineEdit { background-color: white; color: black; border: 1px solid #CCC; }");
        ui->pushButton->setStyleSheet("QPushButton { background-color: #EEE; color: black; border: 1px solid #AAA; }");
    }
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

    // 获取第一个查询字段和值
    QString field1 = ui->comboBox->currentText();
    QString value1 = ui->lineEdit->text();
    QString fieldEng1 = fieldNameMap[field1];

    // 获取第二个查询字段和值
    QString field2 = ui->comboBox_2->currentText();
    QString value2 = ui->lineEdit_2->text();
    QString fieldEng2 = fieldNameMap[field2];

    // 清空tableView
    int rowCount = m_standarditemmodel->rowCount();
    if (rowCount > 0)
    {
        m_standarditemmodel->removeRows(0, rowCount);
    }

    if (!value1.isEmpty() && !value2.isEmpty()) {
        // 两个输入都有值，进行复合查询
        for (auto &stuInfo : m_passedStudentInfoList)
        {
            bool matchField1 = false;
            bool matchField2 = false;

            // 检查fieldEng1
            if (fieldEng1 == "Id" && stuInfo.getId() == value1.toInt()) {
                matchField1 = true;
            } else if (fieldEng1 == "Name" && stuInfo.getName() == value1) {
                matchField1 = true;
            } else if (fieldEng1 == "age" && stuInfo.getAge() == value1.toInt()) {
                matchField1 = true;
            } else if (fieldEng1 == "classname" && stuInfo.getClassname() == value1) {
                matchField1 = true;
            } else if (fieldEng1 == "coursedate" && stuInfo.getCoursedate() == value1) {
                matchField1 = true;
            } else if (fieldEng1 == "coursenum" && stuInfo.getCoursenum() == value1.toInt()) {
                matchField1 = true;
            } else if (fieldEng1 == "coursename" && stuInfo.getCoursename() == value1) {
                matchField1 = true;
            } else if (fieldEng1 == "coursetype" && stuInfo.getCoursetype() == value1) {
                matchField1 = true;
            }

            // 检查fieldEng2
            if (fieldEng2 == "attendanceId" && stuInfo.getAttendanceId() == value2.toInt()) {
                matchField2 = true;
            } else if (fieldEng2 == "coursedate" && stuInfo.getCoursedate() == value2) {
                matchField2 = true;
            } else if (fieldEng2 == "coursenum" && stuInfo.getCoursenum() == value2.toInt()) {
                matchField2 = true;
            } else if (fieldEng2 == "coursename" && stuInfo.getCoursename() == value2) {
                matchField2 = true;
            } else if (fieldEng2 == "coursetype" && stuInfo.getCoursetype() == value2) {
                matchField2 = true;
            }

            // 如果同时满足两个条件，则添加到模型中
            if (matchField1 && matchField2) {
                appendTomodel(stuInfo);
            }
        }
    } else if (!value1.isEmpty()) {
        // 只有第一个输入有值
        for (auto &stuInfo : m_passedStudentInfoList)
        {
            if (fieldEng1 == "Id" && stuInfo.getId() == value1.toInt()) {
                appendTomodel(stuInfo);
            } else if (fieldEng1 == "Name" && stuInfo.getName() == value1) {
                appendTomodel(stuInfo);
            } else if (fieldEng1 == "age" && stuInfo.getAge() == value1.toInt()) {
                appendTomodel(stuInfo);
            } else if (fieldEng1 == "classname" && stuInfo.getClassname() == value1) {
                appendTomodel(stuInfo);
            } else if (fieldEng1 == "coursedate" && stuInfo.getCoursedate() == value1) {
                appendTomodel(stuInfo);
            } else if (fieldEng1 == "coursenum" && stuInfo.getCoursenum() == value1.toInt()) {
                appendTomodel(stuInfo);
            } else if (fieldEng1 == "coursename" && stuInfo.getCoursename() == value1) {
                appendTomodel(stuInfo);
            } else if (fieldEng1 == "coursetype" && stuInfo.getCoursetype() == value1) {
                appendTomodel(stuInfo);
            }
        }
    } else if (!value2.isEmpty()) {
        // 只有第二个输入有值
        for (auto &stuInfo : m_passedStudentInfoList)
        {
            if (fieldEng2 == "attendanceId" && stuInfo.getAttendanceId() == value2.toInt()) {
                appendTomodel(stuInfo);
            } else if (fieldEng2 == "coursedate" && stuInfo.getCoursedate() == value2) {
                appendTomodel(stuInfo);
            } else if (fieldEng2 == "coursenum" && stuInfo.getCoursenum() == value2.toInt()) {
                appendTomodel(stuInfo);
            } else if (fieldEng2 == "coursename" && stuInfo.getCoursename() == value2) {
                appendTomodel(stuInfo);
            } else if (fieldEng2 == "coursetype" && stuInfo.getCoursetype() == value2) {
                appendTomodel(stuInfo);
            }
        }
    } else {
        // 两个输入都没有值，显示所有数据
        fillTableView(m_passedStudentInfoList);
    }

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
