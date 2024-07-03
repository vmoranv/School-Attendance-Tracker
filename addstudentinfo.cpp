#include "addstudentinfo.h"
#include "ui_addstudentinfo.h"

addstudentinfo::addstudentinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstudentinfo)
{
    ui->setupUi(this);
}

addstudentinfo::~addstudentinfo()
{
    delete ui;
}
