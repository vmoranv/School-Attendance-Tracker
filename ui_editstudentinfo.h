/********************************************************************************
** Form generated from reading UI file 'editstudentinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSTUDENTINFO_H
#define UI_EDITSTUDENTINFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_editstudentinfo
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_id;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QLineEdit *lineEdit_sex;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_15;
    QLineEdit *lineEdit_age;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_16;
    QLineEdit *lineEdit_clasname;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_17;
    QLineEdit *lineEdit_coursedate;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_18;
    QLineEdit *lineEdit_coursenum;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_19;
    QLineEdit *lineEdit_coursename;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_20;
    QLineEdit *lineEdit_coursetype;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_21;
    QLineEdit *lineEdit_credit;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_22;
    QLineEdit *lineEdit_launchtime;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *editstudentinfo)
    {
        if (editstudentinfo->objectName().isEmpty())
            editstudentinfo->setObjectName(QString::fromUtf8("editstudentinfo"));
        editstudentinfo->resize(360, 640);
        QFont font;
        font.setPointSize(16);
        editstudentinfo->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/ico/editstudentinfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        editstudentinfo->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(editstudentinfo);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(editstudentinfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 24));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit_id = new QLineEdit(editstudentinfo);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_id->sizePolicy().hasHeightForWidth());
        lineEdit_id->setSizePolicy(sizePolicy);
        lineEdit_id->setMinimumSize(QSize(0, 24));
        lineEdit_id->setFont(font);

        horizontalLayout->addWidget(lineEdit_id);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_13 = new QLabel(editstudentinfo);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(0, 24));
        label_13->setFont(font);

        horizontalLayout_13->addWidget(label_13);

        lineEdit_name = new QLineEdit(editstudentinfo);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        sizePolicy.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy);
        lineEdit_name->setMinimumSize(QSize(0, 24));
        lineEdit_name->setFont(font);

        horizontalLayout_13->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_14 = new QLabel(editstudentinfo);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(0, 24));
        label_14->setFont(font);

        horizontalLayout_14->addWidget(label_14);

        lineEdit_sex = new QLineEdit(editstudentinfo);
        lineEdit_sex->setObjectName(QString::fromUtf8("lineEdit_sex"));
        sizePolicy.setHeightForWidth(lineEdit_sex->sizePolicy().hasHeightForWidth());
        lineEdit_sex->setSizePolicy(sizePolicy);
        lineEdit_sex->setMinimumSize(QSize(0, 24));
        lineEdit_sex->setFont(font);

        horizontalLayout_14->addWidget(lineEdit_sex);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_15 = new QLabel(editstudentinfo);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        horizontalLayout_15->addWidget(label_15);

        lineEdit_age = new QLineEdit(editstudentinfo);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));
        sizePolicy.setHeightForWidth(lineEdit_age->sizePolicy().hasHeightForWidth());
        lineEdit_age->setSizePolicy(sizePolicy);
        lineEdit_age->setMinimumSize(QSize(0, 24));
        lineEdit_age->setFont(font);

        horizontalLayout_15->addWidget(lineEdit_age);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_16 = new QLabel(editstudentinfo);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(0, 24));
        label_16->setFont(font);

        horizontalLayout_16->addWidget(label_16);

        lineEdit_clasname = new QLineEdit(editstudentinfo);
        lineEdit_clasname->setObjectName(QString::fromUtf8("lineEdit_clasname"));
        sizePolicy.setHeightForWidth(lineEdit_clasname->sizePolicy().hasHeightForWidth());
        lineEdit_clasname->setSizePolicy(sizePolicy);
        lineEdit_clasname->setMinimumSize(QSize(0, 24));
        lineEdit_clasname->setFont(font);

        horizontalLayout_16->addWidget(lineEdit_clasname);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_17 = new QLabel(editstudentinfo);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(0, 24));
        label_17->setFont(font);

        horizontalLayout_17->addWidget(label_17);

        lineEdit_coursedate = new QLineEdit(editstudentinfo);
        lineEdit_coursedate->setObjectName(QString::fromUtf8("lineEdit_coursedate"));
        sizePolicy.setHeightForWidth(lineEdit_coursedate->sizePolicy().hasHeightForWidth());
        lineEdit_coursedate->setSizePolicy(sizePolicy);
        lineEdit_coursedate->setMinimumSize(QSize(0, 24));
        lineEdit_coursedate->setFont(font);

        horizontalLayout_17->addWidget(lineEdit_coursedate);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_18 = new QLabel(editstudentinfo);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(0, 24));
        label_18->setFont(font);

        horizontalLayout_18->addWidget(label_18);

        lineEdit_coursenum = new QLineEdit(editstudentinfo);
        lineEdit_coursenum->setObjectName(QString::fromUtf8("lineEdit_coursenum"));
        sizePolicy.setHeightForWidth(lineEdit_coursenum->sizePolicy().hasHeightForWidth());
        lineEdit_coursenum->setSizePolicy(sizePolicy);
        lineEdit_coursenum->setMinimumSize(QSize(0, 24));
        lineEdit_coursenum->setFont(font);

        horizontalLayout_18->addWidget(lineEdit_coursenum);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_19 = new QLabel(editstudentinfo);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(0, 24));
        label_19->setFont(font);

        horizontalLayout_19->addWidget(label_19);

        lineEdit_coursename = new QLineEdit(editstudentinfo);
        lineEdit_coursename->setObjectName(QString::fromUtf8("lineEdit_coursename"));
        sizePolicy.setHeightForWidth(lineEdit_coursename->sizePolicy().hasHeightForWidth());
        lineEdit_coursename->setSizePolicy(sizePolicy);
        lineEdit_coursename->setMinimumSize(QSize(0, 24));
        lineEdit_coursename->setFont(font);

        horizontalLayout_19->addWidget(lineEdit_coursename);


        verticalLayout->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_20 = new QLabel(editstudentinfo);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(0, 24));
        label_20->setFont(font);

        horizontalLayout_20->addWidget(label_20);

        lineEdit_coursetype = new QLineEdit(editstudentinfo);
        lineEdit_coursetype->setObjectName(QString::fromUtf8("lineEdit_coursetype"));
        sizePolicy.setHeightForWidth(lineEdit_coursetype->sizePolicy().hasHeightForWidth());
        lineEdit_coursetype->setSizePolicy(sizePolicy);
        lineEdit_coursetype->setMinimumSize(QSize(0, 24));
        lineEdit_coursetype->setFont(font);

        horizontalLayout_20->addWidget(lineEdit_coursetype);


        verticalLayout->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_21 = new QLabel(editstudentinfo);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMinimumSize(QSize(0, 24));
        label_21->setFont(font);

        horizontalLayout_21->addWidget(label_21);

        lineEdit_credit = new QLineEdit(editstudentinfo);
        lineEdit_credit->setObjectName(QString::fromUtf8("lineEdit_credit"));
        sizePolicy.setHeightForWidth(lineEdit_credit->sizePolicy().hasHeightForWidth());
        lineEdit_credit->setSizePolicy(sizePolicy);
        lineEdit_credit->setMinimumSize(QSize(0, 24));
        lineEdit_credit->setFont(font);

        horizontalLayout_21->addWidget(lineEdit_credit);


        verticalLayout->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_22 = new QLabel(editstudentinfo);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(0, 24));
        label_22->setFont(font);

        horizontalLayout_22->addWidget(label_22);

        lineEdit_launchtime = new QLineEdit(editstudentinfo);
        lineEdit_launchtime->setObjectName(QString::fromUtf8("lineEdit_launchtime"));
        sizePolicy.setHeightForWidth(lineEdit_launchtime->sizePolicy().hasHeightForWidth());
        lineEdit_launchtime->setSizePolicy(sizePolicy);
        lineEdit_launchtime->setMinimumSize(QSize(0, 24));
        lineEdit_launchtime->setFont(font);

        horizontalLayout_22->addWidget(lineEdit_launchtime);


        verticalLayout->addLayout(horizontalLayout_22);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        pushButton_accept = new QPushButton(editstudentinfo);
        pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_accept->sizePolicy().hasHeightForWidth());
        pushButton_accept->setSizePolicy(sizePolicy1);
        pushButton_accept->setMinimumSize(QSize(0, 32));
        pushButton_accept->setFont(font);
        pushButton_accept->setAutoFillBackground(true);

        horizontalLayout_23->addWidget(pushButton_accept);

        pushButton_cancel = new QPushButton(editstudentinfo);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        sizePolicy1.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy1);
        pushButton_cancel->setMinimumSize(QSize(0, 32));
        pushButton_cancel->setFont(font);
        pushButton_cancel->setAutoFillBackground(true);

        horizontalLayout_23->addWidget(pushButton_cancel);


        verticalLayout_2->addLayout(horizontalLayout_23);

        verticalLayout_2->setStretch(0, 92);
        verticalLayout_2->setStretch(1, 8);

        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(editstudentinfo);

        QMetaObject::connectSlotsByName(editstudentinfo);
    } // setupUi

    void retranslateUi(QDialog *editstudentinfo)
    {
        editstudentinfo->setWindowTitle(QCoreApplication::translate("editstudentinfo", "\344\277\256\346\224\271", nullptr));
        label->setText(QCoreApplication::translate("editstudentinfo", "\345\255\246\345\217\267    ", nullptr));
        label_13->setText(QCoreApplication::translate("editstudentinfo", "\345\247\223\345\220\215    ", nullptr));
        label_14->setText(QCoreApplication::translate("editstudentinfo", "\346\200\247\345\210\253    ", nullptr));
        label_15->setText(QCoreApplication::translate("editstudentinfo", "\345\271\264\351\276\204    ", nullptr));
        label_16->setText(QCoreApplication::translate("editstudentinfo", "\347\217\255\347\272\247    ", nullptr));
        label_17->setText(QCoreApplication::translate("editstudentinfo", "\347\274\272\350\257\276\346\227\245\346\234\237", nullptr));
        label_18->setText(QCoreApplication::translate("editstudentinfo", "\347\254\254\345\207\240\350\212\202\350\257\276", nullptr));
        label_19->setText(QCoreApplication::translate("editstudentinfo", "\350\257\276\347\250\213\345\220\215\347\247\260", nullptr));
        label_20->setText(QCoreApplication::translate("editstudentinfo", "\347\274\272\350\257\276\347\261\273\345\236\213", nullptr));
        label_21->setText(QCoreApplication::translate("editstudentinfo", "\345\255\246\345\210\206    ", nullptr));
        label_22->setText(QCoreApplication::translate("editstudentinfo", "\345\274\200\350\257\276\346\227\266\351\227\264", nullptr));
        pushButton_accept->setText(QCoreApplication::translate("editstudentinfo", "\347\241\256\350\256\244", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("editstudentinfo", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editstudentinfo: public Ui_editstudentinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSTUDENTINFO_H
