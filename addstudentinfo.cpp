#include "addstudentinfo.h"
#include "ui_addstudentinfo.h"

addstudentinfo::addstudentinfo(QWidget *parent) :
    QDialog(parent)
  ,ui(new Ui::addstudentinfo)

{
    ui->setupUi(this);
}

addstudentinfo::~addstudentinfo()
{
    delete ui;
}

void addstudentinfo::on_pushButton_accept_clicked()
{

    int id = ui->lineEdit_id->text().toInt();
    QString name = ui->lineEdit_name->text();
    QString sex = ui->lineEdit_sex->text();
    int age = ui->lineEdit_age->text().toInt();
    QString classname = ui->lineEdit_clasname->text();
    QString coursedate = ui->lineEdit_coursedate->text();
    int coursenum = ui->lineEdit_coursenum->text().toInt();
    QString coursename = ui->lineEdit_coursename->text();
    QString coursetype = ui->lineEdit_coursetype->text();
    double credit = ui->lineEdit_credit->text().toDouble();
    QString courselaunchtime = ui->lineEdit_launchtime->text();

    cstudentinfo studentinfo;
    studentinfo.setData(id, name, sex, age, classname, coursedate, coursenum, coursename, coursetype, credit, courselaunchtime);

    qDebug() << "Emitting sig_addStuInfo with data:" << studentinfo.getName();
    emit sig_addStuInfo(studentinfo);
    close();
}


void addstudentinfo::on_pushButton_cancel_clicked()
{
    close();
}

void addstudentinfo::initUI()
{

}
