#include "editstudentinfo.h"
#include "ui_editstudentinfo.h"

editstudentinfo::editstudentinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editstudentinfo)
{
    ui->setupUi(this);
}

editstudentinfo::~editstudentinfo()
{
    delete ui;
}

void editstudentinfo::on_pushButton_cancel_clicked()
{
    close();
}
