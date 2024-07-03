#include "analyzestudentinfo.h"
#include "ui_analyzestudentinfo.h"

analyzestudentinfo::analyzestudentinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::analyzestudentinfo)
{
    ui->setupUi(this);
}

analyzestudentinfo::~analyzestudentinfo()
{
    delete ui;
}
