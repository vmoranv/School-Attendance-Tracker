#ifndef ADDSTUDENTINFO_H
#define ADDSTUDENTINFO_H

#include <QDialog>
#include <QMessageBox>

#include "cstudentinfo.h"
#include "mainwindow.h"
#include "csqlite.h"

namespace Ui {
class addstudentinfo;
}

class addstudentinfo : public QDialog
{
    Q_OBJECT

public:
    explicit addstudentinfo(QWidget *parent = nullptr);
    ~addstudentinfo();

private slots:
    void on_pushButton_accept_clicked();

    void on_pushButton_cancel_clicked();
public:
    void initUI();

signals:
    void sig_addStuInfo(cstudentinfo& studentInfo);

    void sig_updateStuInfo(cstudentinfo& stuInfo);

private:
    Ui::addstudentinfo *ui;
};

#endif // ADDSTUDENTINFO_H
