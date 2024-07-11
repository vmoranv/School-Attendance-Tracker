#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.on_action_4_triggered();
    QMessageBox::information(0, "警告", "请先打开文件或新建文件再操作");

    return a.exec();
}
