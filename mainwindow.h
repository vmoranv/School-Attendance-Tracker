#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QListView>
#include <QFile>
#include <QFileDialog>
#include <QKeyEvent>

#include "optiondatabase.h"
#include "addstudentinfo.h"
#include "ui_addstudentinfo.h"
#include "editstudentinfo.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public optionDatabase
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool selectstuInfos(QList<studentInfo> &stuInfosList) override;
    bool addstuInfos(studentInfo &stuInfos) override;
    bool delstuInfos(int Id) override;
    bool editstuInfos(studentInfo &stuInfos) override;
    void queryAndDisplayWithCondition(const QString &condition);
    void queryAndDisplay();
    void displayStudentRecord(const QSqlQuery &sqlquery);
    void insertStudentToDatabase(const studentInfo &stuInfos);
    void populateStandardModel(QStandardItemModel* model, const QList<studentInfo>& stuInfosList);
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_pushButton_query_clicked();

    void on_action_Globalshow_triggered();

    void on_pushButton_add_clicked();

    void on_action_N_triggered();

    void on_action_S_triggered();

    void on_action_Save_triggered();

    void on_action_Query_triggered();

    void on_action_Open_triggered();

    void on_action_TotalAnalize_triggered();

    void on_action_Insert_triggered();

    void on_action_Delete_triggered();

    void on_pushButton_del_clicked();

    void onStudentAdded(const studentInfo& newstudent);

    void onStudentEdited(const studentInfo& editedStudent);

    void on_pushButton_edit_clicked();

private:
    void initui();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel sqlmodel;
    editstudentinfo *editStudentInfoDialog;

};
#endif // MAINWINDOW_H
