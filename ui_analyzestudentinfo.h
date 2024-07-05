/********************************************************************************
** Form generated from reading UI file 'analyzestudentinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYZESTUDENTINFO_H
#define UI_ANALYZESTUDENTINFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_analyzestudentinfo
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_id_11;
    QCheckBox *checkBox_id_8;
    QCheckBox *checkBox_id_7;
    QCheckBox *checkBox_id_4;
    QCheckBox *checkBox_id_10;
    QCheckBox *checkBox_id_5;
    QCheckBox *checkBox_id_9;
    QCheckBox *checkBox_id_3;
    QCheckBox *checkBox_id_6;
    QCheckBox *checkBox_id;
    QCheckBox *checkBox_id_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTableView *tableView;

    void setupUi(QDialog *analyzestudentinfo)
    {
        if (analyzestudentinfo->objectName().isEmpty())
            analyzestudentinfo->setObjectName(QString::fromUtf8("analyzestudentinfo"));
        analyzestudentinfo->resize(1920, 1280);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/ico/analyzestudentinfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        analyzestudentinfo->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(analyzestudentinfo);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_id_11 = new QCheckBox(analyzestudentinfo);
        checkBox_id_11->setObjectName(QString::fromUtf8("checkBox_id_11"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox_id_11->sizePolicy().hasHeightForWidth());
        checkBox_id_11->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        checkBox_id_11->setFont(font);

        horizontalLayout->addWidget(checkBox_id_11);

        checkBox_id_8 = new QCheckBox(analyzestudentinfo);
        checkBox_id_8->setObjectName(QString::fromUtf8("checkBox_id_8"));
        sizePolicy.setHeightForWidth(checkBox_id_8->sizePolicy().hasHeightForWidth());
        checkBox_id_8->setSizePolicy(sizePolicy);
        checkBox_id_8->setFont(font);

        horizontalLayout->addWidget(checkBox_id_8);

        checkBox_id_7 = new QCheckBox(analyzestudentinfo);
        checkBox_id_7->setObjectName(QString::fromUtf8("checkBox_id_7"));
        sizePolicy.setHeightForWidth(checkBox_id_7->sizePolicy().hasHeightForWidth());
        checkBox_id_7->setSizePolicy(sizePolicy);
        checkBox_id_7->setFont(font);

        horizontalLayout->addWidget(checkBox_id_7);

        checkBox_id_4 = new QCheckBox(analyzestudentinfo);
        checkBox_id_4->setObjectName(QString::fromUtf8("checkBox_id_4"));
        sizePolicy.setHeightForWidth(checkBox_id_4->sizePolicy().hasHeightForWidth());
        checkBox_id_4->setSizePolicy(sizePolicy);
        checkBox_id_4->setFont(font);

        horizontalLayout->addWidget(checkBox_id_4);

        checkBox_id_10 = new QCheckBox(analyzestudentinfo);
        checkBox_id_10->setObjectName(QString::fromUtf8("checkBox_id_10"));
        sizePolicy.setHeightForWidth(checkBox_id_10->sizePolicy().hasHeightForWidth());
        checkBox_id_10->setSizePolicy(sizePolicy);
        checkBox_id_10->setFont(font);

        horizontalLayout->addWidget(checkBox_id_10);

        checkBox_id_5 = new QCheckBox(analyzestudentinfo);
        checkBox_id_5->setObjectName(QString::fromUtf8("checkBox_id_5"));
        sizePolicy.setHeightForWidth(checkBox_id_5->sizePolicy().hasHeightForWidth());
        checkBox_id_5->setSizePolicy(sizePolicy);
        checkBox_id_5->setFont(font);

        horizontalLayout->addWidget(checkBox_id_5);

        checkBox_id_9 = new QCheckBox(analyzestudentinfo);
        checkBox_id_9->setObjectName(QString::fromUtf8("checkBox_id_9"));
        sizePolicy.setHeightForWidth(checkBox_id_9->sizePolicy().hasHeightForWidth());
        checkBox_id_9->setSizePolicy(sizePolicy);
        checkBox_id_9->setFont(font);

        horizontalLayout->addWidget(checkBox_id_9);

        checkBox_id_3 = new QCheckBox(analyzestudentinfo);
        checkBox_id_3->setObjectName(QString::fromUtf8("checkBox_id_3"));
        sizePolicy.setHeightForWidth(checkBox_id_3->sizePolicy().hasHeightForWidth());
        checkBox_id_3->setSizePolicy(sizePolicy);
        checkBox_id_3->setFont(font);

        horizontalLayout->addWidget(checkBox_id_3);

        checkBox_id_6 = new QCheckBox(analyzestudentinfo);
        checkBox_id_6->setObjectName(QString::fromUtf8("checkBox_id_6"));
        sizePolicy.setHeightForWidth(checkBox_id_6->sizePolicy().hasHeightForWidth());
        checkBox_id_6->setSizePolicy(sizePolicy);
        checkBox_id_6->setFont(font);

        horizontalLayout->addWidget(checkBox_id_6);

        checkBox_id = new QCheckBox(analyzestudentinfo);
        checkBox_id->setObjectName(QString::fromUtf8("checkBox_id"));
        sizePolicy.setHeightForWidth(checkBox_id->sizePolicy().hasHeightForWidth());
        checkBox_id->setSizePolicy(sizePolicy);
        checkBox_id->setFont(font);

        horizontalLayout->addWidget(checkBox_id);

        checkBox_id_2 = new QCheckBox(analyzestudentinfo);
        checkBox_id_2->setObjectName(QString::fromUtf8("checkBox_id_2"));
        sizePolicy.setHeightForWidth(checkBox_id_2->sizePolicy().hasHeightForWidth());
        checkBox_id_2->setSizePolicy(sizePolicy);
        checkBox_id_2->setFont(font);

        horizontalLayout->addWidget(checkBox_id_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        lineEdit = new QLineEdit(analyzestudentinfo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(30, 0));
        lineEdit->setFont(font);
        lineEdit->setAutoFillBackground(true);

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(analyzestudentinfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(90, 45));
        pushButton->setFont(font);
        pushButton->setAutoFillBackground(true);

        horizontalLayout_2->addWidget(pushButton);

        horizontalLayout_2->setStretch(0, 85);
        horizontalLayout_2->setStretch(1, 10);
        horizontalLayout_2->setStretch(2, 5);

        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(analyzestudentinfo);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 95);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(analyzestudentinfo);

        QMetaObject::connectSlotsByName(analyzestudentinfo);
    } // setupUi

    void retranslateUi(QDialog *analyzestudentinfo)
    {
        analyzestudentinfo->setWindowTitle(QCoreApplication::translate("analyzestudentinfo", "\347\273\237\350\256\241", nullptr));
        checkBox_id_11->setText(QCoreApplication::translate("analyzestudentinfo", "\345\255\246\345\217\267", nullptr));
        checkBox_id_8->setText(QCoreApplication::translate("analyzestudentinfo", "\345\247\223\345\220\215", nullptr));
        checkBox_id_7->setText(QCoreApplication::translate("analyzestudentinfo", "\346\200\247\345\210\253", nullptr));
        checkBox_id_4->setText(QCoreApplication::translate("analyzestudentinfo", "\345\271\264\351\276\204", nullptr));
        checkBox_id_10->setText(QCoreApplication::translate("analyzestudentinfo", "\347\217\255\347\272\247", nullptr));
        checkBox_id_5->setText(QCoreApplication::translate("analyzestudentinfo", "\347\274\272\350\257\276\346\227\245\346\234\237", nullptr));
        checkBox_id_9->setText(QCoreApplication::translate("analyzestudentinfo", "\347\254\254\345\207\240\350\212\202\350\257\276", nullptr));
        checkBox_id_3->setText(QCoreApplication::translate("analyzestudentinfo", "\350\257\276\347\250\213\345\220\215\347\247\260", nullptr));
        checkBox_id_6->setText(QCoreApplication::translate("analyzestudentinfo", "\347\274\272\350\257\276\347\261\273\345\236\213", nullptr));
        checkBox_id->setText(QCoreApplication::translate("analyzestudentinfo", "\345\255\246\345\210\206", nullptr));
        checkBox_id_2->setText(QCoreApplication::translate("analyzestudentinfo", "\345\274\200\350\257\276\346\227\266\351\227\264", nullptr));
        pushButton->setText(QCoreApplication::translate("analyzestudentinfo", "\347\273\237\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class analyzestudentinfo: public Ui_analyzestudentinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYZESTUDENTINFO_H
