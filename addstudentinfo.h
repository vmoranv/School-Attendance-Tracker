#ifndef ADDSTUDENTINFO_H
#define ADDSTUDENTINFO_H

#include <QDialog>

namespace Ui {
class addstudentinfo;
}

class addstudentinfo : public QDialog
{
    Q_OBJECT

public:
    explicit addstudentinfo(QWidget *parent = nullptr);
    ~addstudentinfo();

private:
    Ui::addstudentinfo *ui;
};

#endif // ADDSTUDENTINFO_H
