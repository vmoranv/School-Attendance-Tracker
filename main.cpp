#include "mainwindow.h"
#include "csqlite.h"
#include "addstudentinfo.h"
#include "editstudentinfo.h"
#include "analyzestudentinfo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    addstudentinfo testui;
//    testui.show();
//    editstudentinfo testui;
//    testui.show();
//    analyzestudentinfo testui;
//    testui.show();
//    csqlite test;
//    QList<cstudentinfo>list;
//    test.selectStudentInfo(list);
//    qDebug()<<list.size()<<""<<list.at(0).getName();
    return a.exec();
}
