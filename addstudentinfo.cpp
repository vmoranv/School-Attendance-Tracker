#include "addstudentinfo.h"
#include "ui_addstudentinfo.h"

addstudentinfo::addstudentinfo(QWidget *parent) :
    QDialog(parent)
  ,ui(new Ui::addstudentinfo)
{
    ui->setupUi(this);
    initUI();
}

addstudentinfo::~addstudentinfo()
{
    delete ui;
}

void addstudentinfo::on_pushButton_accept_clicked()
{
    // 尝试将输入转换为所需类型，并捕获可能的异常
    try {
        int id = ui->lineEdit_id->text().toInt();
        QString name = ui->lineEdit_name->text();
        QString sex = ui->lineEdit_sex->text();
        int age = ui->lineEdit_age->text().toInt();
        QString classname = ui->lineEdit_classname->text();
        QString coursedate = ui->lineEdit_coursedate->text();
        int coursenum = ui->lineEdit_coursenum->text().toInt();
        QString coursename = ui->lineEdit_coursename->text();
        QString coursetype = ui->lineEdit_coursetype->text();
        double credit = ui->lineEdit_credit->text().toDouble();
        QString courselaunchtime = ui->lineEdit_launchtime->text();

        // 创建学生信息对象
        cstudentinfo studentinfo;
        studentinfo.setData(id, name, sex, age, classname, coursedate, coursenum, coursename, coursetype, credit, courselaunchtime);

        qDebug() << "addsrudent id" << studentinfo.getId();
        if (m_isEditMode) {
            qDebug() << "before Emitting sig_editStuInfo with data:" << studentinfo.getId();
            emit sig_updateStuInfo(studentinfo);
            qDebug() << "Emitting sig_editStuInfo with data:" << studentinfo.getId();
        } else {
            qDebug() << "before Emitting sig_editStuInfo with data:" << studentinfo.getId();
            emit sig_addStuInfo(studentinfo);
            qDebug() << "Emitting sig_addStuInfo with data:" << studentinfo.getId();
        }
        close();
    } catch (const std::invalid_argument& e) {
        // 输入类型不匹配，弹出提示框
        QMessageBox::warning(this, "输入错误", "请输入正确的数据类型！");
    } catch (const std::out_of_range& e) {
        // 输入范围超出限制，弹出提示框
        QMessageBox::warning(this, "输入错误", "输入的数值超出范围！");
    }
}


void addstudentinfo::on_pushButton_cancel_clicked()
{
    close();
}

void addstudentinfo::initUI()
{

}

void addstudentinfo::setEditMode(bool isEditMode, const cstudentinfo& studentInfo)

{
    m_isEditMode = isEditMode;
    if (isEditMode) {
        ui->pushButton_accept->setText("保存");
        setWindowTitle("编辑");
        ui->lineEdit_attendanceID->setText(QString::number(studentInfo.getAttendanceId()));
        ui->lineEdit_id->setText(QString::number(studentInfo.getId()));
        ui->lineEdit_name->setText(studentInfo.getName());
        ui->lineEdit_sex->setText(studentInfo.getSex());
        ui->lineEdit_age->setText(QString::number(studentInfo.getAge()));
        ui->lineEdit_classname->setText(studentInfo.getClassname());
        ui->lineEdit_coursedate->setText(studentInfo.getCoursedate());
        ui->lineEdit_coursenum->setText(QString::number(studentInfo.getCoursenum()));
        ui->lineEdit_coursename->setText(studentInfo.getCoursename());
        ui->lineEdit_coursetype->setText(studentInfo.getCoursetype());
        ui->lineEdit_credit->setText(QString::number(studentInfo.getCredit()));
        ui->lineEdit_launchtime->setText(studentInfo.getCourselauchtime());

    } else {
        ui->pushButton_accept->setText("添加");
        ui->lineEdit_attendanceID->clear();
        ui->lineEdit_id->clear();
        ui->lineEdit_name->clear();
        ui->lineEdit_sex->clear();
        ui->lineEdit_age->clear();
        ui->lineEdit_classname->clear();
        ui->lineEdit_coursedate->clear();
        ui->lineEdit_coursenum->clear();
        ui->lineEdit_coursename->clear();
        ui->lineEdit_coursetype->clear();
        ui->lineEdit_credit->clear();
        ui->lineEdit_launchtime->clear();

        setWindowTitle("添加");

    }

}
