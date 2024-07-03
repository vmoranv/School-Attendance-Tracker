#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_database(NULL)
    , m_standarditemmodel(NULL)
{
    ui->setupUi(this);
    m_database = new csqlite();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_clicked()
{

}

void MainWindow::on_pushButton_del_clicked()
{

}

void MainWindow::on_pushButton_edit_clicked()
{

}

void MainWindow::on_pushButton_query_clicked()
{

}

void MainWindow::on_action_O_triggered()
{

}

void MainWindow::on_action_N_triggered()
{

}

void MainWindow::on_action_S_triggered()
{

}

void MainWindow::on_action_triggered()
{

}

void MainWindow::on_action_R_triggered()
{

}

void MainWindow::on_action_I_triggered()
{

}

void MainWindow::on_action_E_triggered()
{

}

void MainWindow::on_action_Q_triggered()
{

}

void MainWindow::on_action_2_triggered()
{

}

void MainWindow::on_action_3_triggered()
{

}

void MainWindow::on_action_4_triggered()
{

}

void MainWindow::on_action_T_triggered()
{

}
