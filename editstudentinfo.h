#ifndef EDITSTUDENTINFO_H
#define EDITSTUDENTINFO_H

#include <QDialog>
#include "studentInfo.h"

namespace Ui {
class editstudentinfo;
}

class editstudentinfo : public QDialog
{
    Q_OBJECT

public:
    explicit editstudentinfo(QDialog *parent = nullptr);
    ~editstudentinfo();

signals:
    void studentAdded(const studentInfo& newstudent);
    void studentEdited(const studentInfo& editedStudent);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::editstudentinfo *ui;
};

#endif // EDITSTUDENTINFO_H
