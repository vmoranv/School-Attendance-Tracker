#ifndef TOTALANALYZEINFO_H
#define TOTALANALYZEINFO_H

#include <QDialog>

namespace Ui {
class totalanalyzeinfo;
}

class totalanalyzeinfo : public QDialog
{
    Q_OBJECT

public:
    explicit totalanalyzeinfo(QWidget *parent = nullptr);
    ~totalanalyzeinfo();

private:
    Ui::totalanalyzeinfo *ui;
};

#endif // TOTALANALYZEINFO_H
