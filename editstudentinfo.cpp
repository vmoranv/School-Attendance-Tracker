#include "editstudentinfo.h"
#include "ui_editstudentinfo.h"

editstudentinfo::editstudentinfo(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::editstudentinfo)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &editstudentinfo::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &editstudentinfo::on_buttonBox_rejected);
}

editstudentinfo::~editstudentinfo()
{
    delete ui;
}

void editstudentinfo::on_buttonBox_accepted()
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

void editstudentinfo::on_buttonBox_rejected()
{

}
