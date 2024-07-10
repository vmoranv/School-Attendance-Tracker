#include "totalanalyzeinfo.h"
#include "ui_totalanalyzeinfo.h"

totalanalyzeinfo::totalanalyzeinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::totalanalyzeinfo)
{
    ui->setupUi(this);
}

totalanalyzeinfo::~totalanalyzeinfo()
{
    delete ui;
}
