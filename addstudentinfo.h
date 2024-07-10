#ifndef ADDSTUDENTINFO_H
#define ADDSTUDENTINFO_H

#include <QDialog>
#include <QMessageBox>

#include "cstudentinfo.h"
#include "csqlite.h"

namespace Ui {
class addstudentinfo;
}

class MainWindow;

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

    void setEditMode(bool isEditMode, const cstudentinfo& studentInfo);

    MainWindow *mainwin;

signals:
    void sig_addStuInfo(cstudentinfo& studentInfo);

    void sig_updateStuInfo(cstudentinfo& stuInfo);

    void sig_editStuInfo(cstudentinfo& studentinfo);

private:
    Ui::addstudentinfo *ui;
    bool m_isEditMode;
};

#endif // ADDSTUDENTINFO_H
