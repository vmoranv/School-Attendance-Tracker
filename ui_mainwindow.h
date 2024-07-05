/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_O;
    QAction *action_N;
    QAction *action_S;
    QAction *action;
    QAction *action_R;
    QAction *action_I;
    QAction *action_E;
    QAction *action_Q;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_T;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_add;
    QPushButton *pushButton_del;
    QPushButton *pushButton_edit;
    QPushButton *pushButton_query;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_S;
    QMenu *menu_E;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1280);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/ico/mainwindow.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        action_O = new QAction(MainWindow);
        action_O->setObjectName(QString::fromUtf8("action_O"));
        action_N = new QAction(MainWindow);
        action_N->setObjectName(QString::fromUtf8("action_N"));
        action_S = new QAction(MainWindow);
        action_S->setObjectName(QString::fromUtf8("action_S"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_R = new QAction(MainWindow);
        action_R->setObjectName(QString::fromUtf8("action_R"));
        action_I = new QAction(MainWindow);
        action_I->setObjectName(QString::fromUtf8("action_I"));
        action_E = new QAction(MainWindow);
        action_E->setObjectName(QString::fromUtf8("action_E"));
        action_Q = new QAction(MainWindow);
        action_Q->setObjectName(QString::fromUtf8("action_Q"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_T = new QAction(MainWindow);
        action_T->setObjectName(QString::fromUtf8("action_T"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_id = new QLabel(centralwidget);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(16);
        label_id->setFont(font);

        horizontalLayout_2->addWidget(label_id);

        lineEdit_id = new QLineEdit(centralwidget);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));
        lineEdit_id->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(lineEdit_id);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setMinimumSize(QSize(0, 30));
        label_name->setFont(font);

        horizontalLayout_4->addWidget(label_name);

        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_add->sizePolicy().hasHeightForWidth());
        pushButton_add->setSizePolicy(sizePolicy);
        pushButton_add->setMinimumSize(QSize(90, 30));
        pushButton_add->setFont(font);

        horizontalLayout->addWidget(pushButton_add);

        pushButton_del = new QPushButton(centralwidget);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        sizePolicy.setHeightForWidth(pushButton_del->sizePolicy().hasHeightForWidth());
        pushButton_del->setSizePolicy(sizePolicy);
        pushButton_del->setMinimumSize(QSize(90, 30));
        pushButton_del->setFont(font);

        horizontalLayout->addWidget(pushButton_del);

        pushButton_edit = new QPushButton(centralwidget);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));
        sizePolicy.setHeightForWidth(pushButton_edit->sizePolicy().hasHeightForWidth());
        pushButton_edit->setSizePolicy(sizePolicy);
        pushButton_edit->setMinimumSize(QSize(90, 30));
        pushButton_edit->setFont(font);

        horizontalLayout->addWidget(pushButton_edit);

        pushButton_query = new QPushButton(centralwidget);
        pushButton_query->setObjectName(QString::fromUtf8("pushButton_query"));
        sizePolicy.setHeightForWidth(pushButton_query->sizePolicy().hasHeightForWidth());
        pushButton_query->setSizePolicy(sizePolicy);
        pushButton_query->setMinimumSize(QSize(90, 30));
        pushButton_query->setFont(font);

        horizontalLayout->addWidget(pushButton_query);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_S = new QMenu(menubar);
        menu_S->setObjectName(QString::fromUtf8("menu_S"));
        menu_E = new QMenu(menubar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_S->menuAction());
        menubar->addAction(menu_E->menuAction());
        menu_F->addAction(action_N);
        menu_F->addAction(action_O);
        menu_F->addAction(action_S);
        menu_F->addAction(action);
        menu_S->addAction(action_I);
        menu_S->addAction(action_R);
        menu_S->addAction(action_E);
        menu_S->addAction(action_Q);
        menu_S->addAction(action_T);
        menu_E->addAction(action_2);
        menu_E->addAction(action_3);
        menu_E->addAction(action_4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\350\200\203\345\213\244\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        action_O->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
#if QT_CONFIG(shortcut)
        action_O->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_N->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", nullptr));
#if QT_CONFIG(shortcut)
        action_N->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_S->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
#if QT_CONFIG(shortcut)
        action_S->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(shortcut)
        action->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_R->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244(&W)", nullptr));
#if QT_CONFIG(shortcut)
        action_R->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        action_I->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240(&I)", nullptr));
#if QT_CONFIG(shortcut)
        action_I->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        action_E->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271(&E)", nullptr));
#if QT_CONFIG(shortcut)
        action_E->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Q->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242(&Q)", nullptr));
#if QT_CONFIG(shortcut)
        action_Q->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_2->setText(QCoreApplication::translate("MainWindow", "\346\267\261\350\211\262(&D)", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\346\265\205\350\211\262(&L)", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\350\267\237\351\232\217\347\263\273\347\273\237(&S)", nullptr));
        action_T->setText(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241(&T)", nullptr));
#if QT_CONFIG(shortcut)
        action_T->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        label_id->setText(QCoreApplication::translate("MainWindow", "\345\255\246\345\217\267", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        pushButton_edit->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        pushButton_query->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_S->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256(&D)", nullptr));
        menu_E->setTitle(QCoreApplication::translate("MainWindow", "\345\244\226\350\247\202(&P)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
