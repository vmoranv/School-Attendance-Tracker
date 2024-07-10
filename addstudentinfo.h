#ifndef ADDSTUDENTINFO_H
#define ADDSTUDENTINFO_H

#include <QDialog>
#include <QDebug>
#include <studentInfo.h>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QListView>


namespace Ui {
class addStudentInfo;
}

class addStudentInfo : public QDialog,public studentInfo
{
    Q_OBJECT

public:
    explicit addStudentInfo(QWidget *parent = nullptr);
    ~addStudentInfo();
    Ui::addStudentInfo *ui;

signals:
    void studentAdded(const studentInfo&);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();
};

#endif // ADDSTUDENTINFO_H
