#include "addstudentinfo.h"
#include "ui_addstudentinfo.h"
#include "studentInfo.h"

addStudentInfo::addStudentInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStudentInfo)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &addStudentInfo::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &addStudentInfo::on_buttonBox_rejected);
}

addStudentInfo::~addStudentInfo()
{
    delete ui;
}

void addStudentInfo::on_buttonBox_accepted()
{
    studentInfo newStudent;
    newStudent.setId(ui->lineEdit_addid->text().toInt());
    newStudent.setName(ui->lineEdit_addname->text());
    newStudent.setSex(ui->lineEdit_addsex->text());
    newStudent.setAge(ui->lineEdit_addage->text().toInt());
    newStudent.setClassname(ui->lineEdit_addclassname->text());
    newStudent.setCoursedate(ui->lineEdit_addcoursedate->text());
    newStudent.setCoursenum(ui->lineEdit_addcoursenum->text().toInt());
    newStudent.setCoursename(ui->lineEdit_addcoursename->text());
    newStudent.setCoursetype(ui->lineEdit_addcoursetype->text());
    newStudent.setCredit(ui->lineEdit_addcredit->text().toDouble());
    newStudent.setCourselauchtime(ui->lineEdit_addlauchtime->text());

    emit studentAdded(newStudent);
    accept();
}


void addStudentInfo::on_buttonBox_rejected()
{
    reject();
}
