#ifndef ANALYZESTUDENTINFO_H
#define ANALYZESTUDENTINFO_H

#include <QDialog>

namespace Ui {
class analyzestudentinfo;
}

class analyzestudentinfo : public QDialog
{
    Q_OBJECT

public:
    explicit analyzestudentinfo(QWidget *parent = nullptr);
    ~analyzestudentinfo();

private:
    Ui::analyzestudentinfo *ui;
};

#endif // ANALYZESTUDENTINFO_H
