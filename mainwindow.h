#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QApplication>
#include <QStyleFactory>
#include <QPalette>
#include <QColor>
#include <QSettings>

#include "csqlite.h"
#include "addstudentinfo.h"
#include "analyzestudentinfo.h"

const int CONST_COLUMN_SIZE = 12;

const int CONST_COL_ATTENDANCEID = 0;
const int CONST_COL_ID = 1;
const int CONST_COL_NAME = 2;
const int CONST_COL_SEX = 3;
const int CONST_COL_AGE = 4;
const int CONST_COL_CLASSNAME = 5;
const int CONST_COL_COURSEDATE = 6;
const int CONST_COL_COURSENUM = 7;
const int CONST_COL_COURSENAME = 8;
const int CONST_COL_COURSETYPE = 9;
const int CONST_COL_CREDIT = 10;
const int CONST_COL_COURSELAUNCHTIME = 11;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    bool appendTomodel(cstudentinfo &studentinfo);

    void switchTheme(bool isDarkMode);

    bool isDarkModeEnabled();

    void fillTableView();

    bool saveDataToDatabase(QSqlDatabase &db);

    void savePendingChangesToDatabase();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_query_clicked();

    void on_action_O_triggered();

    void on_action_N_triggered();

    void on_action_S_triggered();

    void on_action_triggered();

    void on_action_R_triggered();

    void on_action_I_triggered();

    void on_action_E_triggered();

    void on_action_Q_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_T_triggered();

    void on_action_Y_triggered();

    bool slot_addStuInfo(cstudentinfo &stuInfo);

    bool slot_editStuInfo(cstudentinfo &stuInfo);

    bool slot_updateStuInfo(cstudentinfo &stuInfo);

public slots:
        void on_action_4_triggered();

signals:
    void checkBoxStateChanged(int row, Qt::CheckState state);

private:
    void initUI();

private:
    Ui::MainWindow *ui;
    csqlite *m_database;
    QStandardItemModel *m_standarditemmodel;
    addstudentinfo *m_addstudentinfo;
    QList<cstudentinfo> m_pendingStudentInfoList;
    cstudentinfo m_pendingCstudentinfo;
    bool isdarkmode;
};
#endif // MAINWINDOW_H
