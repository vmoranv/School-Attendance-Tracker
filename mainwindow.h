#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "csqlite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

    void on_action_4_triggered();

    void on_action_T_triggered();

private:
    Ui::MainWindow *ui;
    csqlite *m_database;
    QStandardItemModel *m_standarditemmodel;
};
#endif // MAINWINDOW_H
