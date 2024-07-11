#ifndef ANALYZESTUDENTINFO_H
#define ANALYZESTUDENTINFO_H

#include <QDialog>
#include <QStandardItemModel>
#include <QList>
#include <QTimer>
#include <QStyledItemDelegate>

#include "cstudentinfo.h"

namespace Ui {

class analyzestudentinfo;

}

    class analyzestudentinfo : public QDialog

{

Q_OBJECT

public:

    explicit analyzestudentinfo(QWidget *parent = nullptr);

    ~analyzestudentinfo();

    bool appendTomodel(cstudentinfo &studentinfo);

    void fillTableView(QList<cstudentinfo>& result);

    QList<cstudentinfo> passedStudentInfoList() const;

    void setPassedStudentInfoList(const QList<cstudentinfo> &passedStudentInfoList);

    void setTheme(bool isDarkMode);

private slots:

    void on_pushButton_clicked();

private:

    void initUI();

private:

    Ui::analyzestudentinfo *ui;

    QList<cstudentinfo> m_passedStudentInfoList;

    QStandardItemModel *m_standarditemmodel;

};

#endif // ANALYZESTUDENTINFO_H
