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
    qDebug() << "MainWindow constructed, m_database created";

    addstudentinfo *m_addstudentinfo = new addstudentinfo(this);
    connect(m_addstudentinfo, &addstudentinfo::sig_addStuInfo, this, &MainWindow::slot_addStuInfo);
    connect(m_addstudentinfo,&addstudentinfo::sig_updateStuInfo,this,&MainWindow::slot_updateStuInfo);
    qDebug() << "Signal and slot connected";

    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::appendTomodel(cstudentinfo &studentinfo)
{
    qDebug() << "appendTomodel called with data:" << studentinfo.getName();
    QStandardItem *itemId = new QStandardItem(QString("%1").arg(studentinfo.getId(), 4, 10, QLatin1Char('0')));
    itemId->setCheckable(true);
    itemId->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemName = new QStandardItem(studentinfo.getName());
    itemName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemSex = new QStandardItem(studentinfo.getSex());
    itemSex->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemAge = new QStandardItem(QString::number(studentinfo.getAge()));
    itemAge->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemClassname = new QStandardItem(studentinfo.getClassname());
    itemClassname->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemCoursedate = new QStandardItem(studentinfo.getCoursedate());
    itemCoursedate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemCoursenum = new QStandardItem(QString::number(studentinfo.getCoursenum()));
    itemCoursenum->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemCoursename = new QStandardItem(studentinfo.getCoursename());
    itemCoursename->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemCoursetype = new QStandardItem(studentinfo.getCoursetype());
    itemCoursetype->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemCredit = new QStandardItem(QString::number(studentinfo.getCredit()));
    itemCredit->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QStandardItem *itemCourselauchtime = new QStandardItem(studentinfo.getCourselauchtime());
    itemCourselauchtime->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QList<QStandardItem*> rowItems;
    rowItems.append(itemId);
    rowItems.append(itemName);
    rowItems.append(itemSex);
    rowItems.append(itemAge);
    rowItems.append(itemClassname);
    rowItems.append(itemCoursedate);
    rowItems.append(itemCoursenum);
    rowItems.append(itemCoursename);
    rowItems.append(itemCoursetype);
    rowItems.append(itemCredit);
    rowItems.append(itemCourselauchtime);

    m_standarditemmodel->appendRow(rowItems);
    qDebug() << "appendTomodel finished processing data:" << studentinfo.getName();
    return true;
}



void MainWindow::on_pushButton_add_clicked()
{
    addstudentinfo addDialog(this);
    addDialog.exec();
}


void MainWindow::on_pushButton_del_clicked()
{

}

void MainWindow::on_pushButton_edit_clicked()
{
    editstudentinfo editDialog(this);
    editDialog.exec();
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
    analyzestudentinfo analyzeDialog(this);
    analyzeDialog.exec();
}

void MainWindow::initUI()
{

    m_standarditemmodel = new QStandardItemModel(this);
    //实例化菜单以及菜单项
//    m_menu = new QMenu(this);
//    m_actUpdate = new QAction("修改",m_menu);
//    m_actDelete = new QAction("删除",m_menu);
//    m_menu->addAction(m_actUpdate);
//    m_menu->addAction(m_actDelete);

    //设置tableView 菜单策略 customContextMenuRequested(const QPoint &pos)
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    QList<cstudentinfo> stuInfoList;
    bool res = m_database->selectStudentInfo(stuInfoList);
    if(!res)
    {
        QMessageBox::information(this,"提示","查询学生信息失败");
        return;
    }
    qDebug() << stuInfoList.size();
    for(int i=0;i<stuInfoList.size();++i)
    {
        appendTomodel(stuInfoList[i]);
    }
    QStringList headerList;
    headerList << "学号" << "姓名" << "性别" << "年龄" << "班级" << "缺课日期" << "第几节课" << "课程名称" << "学生姓名" << "缺课类型" << "课程名" << "学分" << "开课时间";
    m_standarditemmodel->setHorizontalHeaderLabels(headerList);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(m_standarditemmodel);
    for (int col=0;col<CONST_COLUMN_SIZE;++col) {
        ui->tableView->setColumnWidth(col,(width()-28)/14);
    }
    qDebug()<<"Succeed in set tableview";
}

bool MainWindow::slot_addStuInfo(cstudentinfo &stuInfo)
{
    bool res = m_database->addStudentInfo(stuInfo);
    if(!res)
    {
        QMessageBox::information(this,"提示","插入失败！！！");
        return false;
    }
    appendTomodel(stuInfo);
    return true;
}

bool MainWindow::slot_updateStuInfo(cstudentinfo &stuInfo)
{
    int res = m_database->editStudentInfo(stuInfo);
    if(!res)
    {
        QMessageBox::information(this,"提示","修改失败！！！");
        return false;
    }
    int row = ui->tableView->currentIndex().row();
    m_standarditemmodel->setData(m_standarditemmodel->item(row,CONST_COL_NAME)->index(),stuInfo.getName());

    QMessageBox::information(this,"提示","修改成功！！！");
    return true;
}
