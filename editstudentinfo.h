#ifndef EDITSTUDENTINFO_H
#define EDITSTUDENTINFO_H

#include <QDialog>

namespace Ui {
class editstudentinfo;
}

class editstudentinfo : public QDialog
{
    Q_OBJECT

public:
    explicit editstudentinfo(QWidget *parent = nullptr);
    ~editstudentinfo();

private:
    Ui::editstudentinfo *ui;
};

#endif // EDITSTUDENTINFO_H
