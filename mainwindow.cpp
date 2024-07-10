#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_database(NULL)
    , m_standarditemmodel(NULL)
    , m_addstudentinfo(NULL)
{
    ui->setupUi(this);
    qDebug() << "MainWindow constructed, m_database created";

    m_addstudentinfo = new addstudentinfo(this);

    connect(m_addstudentinfo, &addstudentinfo::sig_addStuInfo, this, &MainWindow::slot_addStuInfo);

    connect(m_addstudentinfo, &addstudentinfo::sig_editStuInfo, this, &MainWindow::slot_editStuInfo);

    connect(m_addstudentinfo, &addstudentinfo::sig_updateStuInfo, this, &MainWindow::slot_updateStuInfo);

    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//初始化UI
void MainWindow::initUI()
{
    m_standarditemmodel = new QStandardItemModel(this);
    ui->tableView->setModel(m_standarditemmodel);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList headerList;
    headerList << "考勤ID" << "学号" << "姓名" << "性别" << "年龄" << "班级" << "缺课日期" << "第几节课" << "课程名称" << "缺课类型" << "学分" << "开课时间";
    m_standarditemmodel->setHorizontalHeaderLabels(headerList);

    qDebug() << "Succeed in set tableview";
}

// 将缓存保存到数据库中
void MainWindow::savePendingChangesToDatabase()
{
    // 遍历缓存列表
    for (cstudentinfo &cachedStuInfo : m_pendingStudentInfoList) {
        // 如果学生信息存在，调用数据库更新方法
        if (m_database->updateStudentInfo(cachedStuInfo)) {
            qDebug() << "Student Info Updated Successfully";
        } else {
            qDebug() << "Failed to Update Student Info";
        }
    }

    // 清空缓存列表
    m_pendingStudentInfoList.clear();
}

// 将学生信息添加到模型中
bool MainWindow::appendTomodel(cstudentinfo &studentinfo)
{
    qDebug() << "appendTomodel called with data:" << studentinfo.getName();

    QList<cattendanceinfo> attendanceInfos = studentinfo.getAttendanceInfos();

    for (const cattendanceinfo &attendanceInfo : attendanceInfos)
    {
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(QString::number(attendanceInfo.getAttendanceId()));
        rowItems << new QStandardItem(QString::number(studentinfo.getId()));
        rowItems << new QStandardItem(studentinfo.getName());
        rowItems << new QStandardItem(studentinfo.getSex());
        rowItems << new QStandardItem(QString::number(studentinfo.getAge()));
        rowItems << new QStandardItem(studentinfo.getClassname());
        rowItems << new QStandardItem(attendanceInfo.getCoursedate());
        rowItems << new QStandardItem(QString::number(attendanceInfo.getCoursenum()));
        rowItems << new QStandardItem(attendanceInfo.getCoursename());
        rowItems << new QStandardItem(attendanceInfo.getCoursetype());
        rowItems << new QStandardItem(QString::number(attendanceInfo.getCredit()));
        rowItems << new QStandardItem(attendanceInfo.getCourselauchtime());

        qDebug()<<rowItems.count();
        for (auto& item : rowItems)
        {
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        }

        m_standarditemmodel->appendRow(rowItems);
    }

    qDebug() << "appendTomodel finished processing data:" << studentinfo.getCourselauchtime();

    return true;
}

// 此函数用于从数据库中获取所有学生信息，并填充到表格视图中。
void MainWindow::fillTableView()
{
    // 从数据库中获取最新的学生信息列表
    QList<cstudentinfo> studentInfoList = m_database->selectAllStudentInfo();

    // 清空模型中的数据
    m_standarditemmodel->clear();

    // 遍历学生信息列表
    for (const cstudentinfo &stuInfo : studentInfoList) {
        // 创建表格行数据
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(QString::number(stuInfo.getAttendanceId())); // 考勤ID
        rowItems << new QStandardItem(QString::number(stuInfo.getId())); // 学号
        rowItems << new QStandardItem(stuInfo.getName()); // 姓名
        rowItems << new QStandardItem(stuInfo.getSex()); // 性别
        rowItems << new QStandardItem(QString::number(stuInfo.getAge())); // 年龄
        rowItems << new QStandardItem(stuInfo.getClassname()); // 班级
        rowItems << new QStandardItem(stuInfo.getCoursedate()); // 缺课日期
        rowItems << new QStandardItem(QString::number(stuInfo.getCoursenum())); // 第几节课
        rowItems << new QStandardItem(stuInfo.getCoursename()); // 课程名称
        rowItems << new QStandardItem(stuInfo.getCoursetype()); // 缺课类型
        rowItems << new QStandardItem(QString::number(stuInfo.getCredit())); // 学分
        rowItems << new QStandardItem(stuInfo.getCourselauchtime()); // 开课时间

        // 将行数据添加到模型中
        m_standarditemmodel->appendRow(rowItems);
    }
}

// 当接收到更新学生信息的信号时，此函数处理更新逻辑，将更新后的学生信息保存到数据库中。
bool MainWindow::slot_updateStuInfo(cstudentinfo &stuInfo)
{
    bool res = m_database->updateStudentInfo(stuInfo);
    if(!res)
    {
        QMessageBox::information(this, "提示", "修改失败!!!");
        return false;
    }

    // 获取当前选中行的索引
    int row = ui->tableView->currentIndex().row();

    // 更新学生基本信息
    m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_ID), stuInfo.getId());
    m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_NAME), stuInfo.getName());
    m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_SEX), stuInfo.getSex());
    m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_AGE), stuInfo.getAge());
    m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_CLASSNAME), stuInfo.getClassname());

    // 更新出勤信息
    // 假设只有一个出勤信息，获取第一个出勤信息
    QList<cattendanceinfo> attendanceInfos = stuInfo.getAttendanceInfos();
    if (!attendanceInfos.isEmpty()) {
        cattendanceinfo attendanceInfo = attendanceInfos.first();

        m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_COURSEDATE), attendanceInfo.getCoursedate());
        m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_COURSENUM), attendanceInfo.getCoursenum());
        m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_COURSENAME), attendanceInfo.getCoursename());
        m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_COURSETYPE), attendanceInfo.getCoursetype());
        m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_CREDIT), attendanceInfo.getCredit());
        m_standarditemmodel->setData(m_standarditemmodel->index(row, CONST_COL_COURSELAUNCHTIME), attendanceInfo.getCourselauchtime());
    }

    QMessageBox::information(this, "提示", "修改成功!!!");
    this->on_action_Y_triggered();
    return true;
}

// 当添加按钮被点击时，初始化一个空白的学生信息对象，并设置添加对话框为添加模式。
void MainWindow::on_pushButton_add_clicked()
{
    cstudentinfo emptyStudentInfo;
    m_addstudentinfo->setEditMode(false, emptyStudentInfo);
    m_addstudentinfo->exec();
}

// 当添加学生信息的信号被接收时，此函数将新的学生信息添加到模型中，并更新表格视图。
bool MainWindow::slot_addStuInfo(cstudentinfo &stuInfo)
{
    qDebug()<<"slot_addStuInfo id"<<stuInfo.getStudentId();
    bool res = m_database->addStudentInfo(stuInfo);
    if(!res)
    {
        QMessageBox::information(this,"提示","插入失败！！！");
        return false;
    }
    appendTomodel(stuInfo);
    return true;
    this->on_action_Y_triggered();

}

// 当编辑按钮被点击时，检查是否有行被选中，如果有，则从缓存中查找对应的学生信息并开启编辑模式。
void MainWindow::on_pushButton_edit_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (selectedIndexes.empty())
    {
        QMessageBox::information(this, "提示", "请选择一行进行编辑！");
        return;
    }

    QModelIndex index = selectedIndexes.first();
    int row = index.row();

    // 获取选中行的学生信息
    cstudentinfo stuInfo;
    stuInfo.setId(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_ID)).toInt());
    stuInfo.setName(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_NAME)).toString());
    stuInfo.setSex(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_SEX)).toString());
    stuInfo.setAge(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_AGE)).toInt());
    stuInfo.setClassname(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_CLASSNAME)).toString());
    stuInfo.setCoursedate(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSEDATE)).toString());
    stuInfo.setCoursenum(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSENUM)).toInt());
    stuInfo.setCoursename(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSENAME)).toString());
    stuInfo.setCoursetype(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSETYPE)).toString());
    stuInfo.setCredit(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_CREDIT)).toDouble());
    stuInfo.setCourselauchtime(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSELAUNCHTIME)).toString());
    stuInfo.setAttendanceId(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_ATTENDANCEID)).toInt());

    qDebug()<<stuInfo.getId();
    m_addstudentinfo->setEditMode(true, stuInfo);
    m_addstudentinfo->exec();
}

// 当接收到编辑学生信息的信号时，更新缓存中对应的学生信息，并显示更新成功的消息。
bool MainWindow::slot_editStuInfo(cstudentinfo &stuInfo)
{
    qDebug() << "Received edit signal with data:" << stuInfo.getName();

    // 直接调用数据库更新函数
    if (m_database->updateStudentInfo(stuInfo)) {
        QMessageBox::information(this, "提示", "更新成功！");
        return true;
    } else {
        QMessageBox::critical(this, "错误", "更新失败！");
        return false;
    }
}

// 当删除按钮被点击时，此函数用于删除被选中的学生信息。
void MainWindow::on_pushButton_del_clicked()
{
    // 获取选中的行
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();
    if (selectedIndexes.isEmpty())
    {
        QMessageBox::information(this, "提示", "请选择一行进行删除！");
        return;
    }

    // 弹出确认对话框询问用户是否真的要删除
    int res = QMessageBox::question(this, "提示", "是否真的要删除？",
                                    QMessageBox::Yes | QMessageBox::No,
                                    QMessageBox::No); // 默认选择"No"
    if (res == QMessageBox::No)
        return;

    // 从最后一行开始遍历，避免删除过程中影响行号
    for (int i = selectedIndexes.size() - 1; i >= 0; --i)
    {
        // 获取当前行的索引
        QModelIndex index = selectedIndexes.at(i);
        int row = index.row();

        // 获取当前行的考勤ID
        int attendanceId = m_standarditemmodel->data(index).toInt();

        // 从数据库中删除对应的考勤记录
        if (m_database->deleteSpecificAttendanceRecord(attendanceId))
        {
            // 从模型中移除当前行
            m_standarditemmodel->removeRow(row);
        }
    }
}

//通过ID或姓名查询消息。
void MainWindow::on_pushButton_query_clicked()

{

    QString studentID = ui->lineEdit_id->text();
    QString studentName = ui->lineEdit_name->text();
    m_standarditemmodel->clear();
    m_standarditemmodel->setHorizontalHeaderLabels(QStringList() << "考勤ID" << "学号" << "姓名" << "性别" << "年龄" << "班级" << "缺课日期" << "第几节课" << "课程名称" << "缺课类型" << "学分" << "开课时间");

    if (studentID.isEmpty() && studentName.isEmpty()) {
        QList<cstudentinfo> allStudentInfo;
        bool allRes = m_database->queryAllStudentInfo(allStudentInfo);

        if (!allRes) {
            QMessageBox::information(this, "提示", "获取所有数据失败！");
            return;
        }

    for (auto &stuInfo : allStudentInfo) {
        appendTomodel(stuInfo);
        }

    QMessageBox::information(this, "提示", "未输入查询条件，显示所有数据！");
    }
    else {
    QList<cstudentinfo> queryResult;
    bool res = m_database->queryStudentInfoByIdOrName(studentID, studentName, queryResult);
    if (!res) {
    QMessageBox::information(this, "提示", "查询失败！");
    return;
    }

    if (queryResult.isEmpty()) {

    QList<cstudentinfo> allStudentInfo;

    bool allRes = m_database->queryAllStudentInfo(allStudentInfo);

    if (!allRes) {

    QMessageBox::information(this, "提示", "获取所有数据失败！");

    return;

    }

    for (auto &stuInfo : allStudentInfo) {

    appendTomodel(stuInfo);

    }

    QMessageBox::information(this, "提示", "未找到符合条件的记录，显示所有数据！");

    } else {



        for (auto &stuInfo : queryResult) {

        appendTomodel(stuInfo);

        }

    }

    }

}

// 当用户选择打开外部数据库时，此函数负责关闭当前数据库连接（如果存在），打开用户选择的新数据库，并将其中的学生信息和考勤记录加载到表格视图中以供查看。
void MainWindow::on_action_O_triggered()
{
    // 弹出文件选择对话框
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Database"), QDir::homePath(), tr("SQLite Database (*.db *.sqlite)"));
    if (!fileName.isEmpty()) {
        // 关闭当前数据库连接（如果有）
        if (m_database) {
            m_database->getDb().close();
            delete m_database;
            m_database = nullptr;
        }

        // 创建一个新的数据库连接
        m_database = new csqlite(fileName);
        if (!m_database->getDb().isOpen()) {
            QMessageBox::critical(this, tr("Error"), tr("Failed to open the database!"));
            delete m_database;
            m_database = nullptr;
            return;
        }

        // 清除tableView上的数据，保留表头
        m_standarditemmodel->clear();
        m_standarditemmodel->setHorizontalHeaderLabels(QStringList() << "考勤ID" << "学号" << "姓名" << "性别" << "年龄" << "班级" << "缺课日期" << "第几节课" << "课程名称" << "缺课类型" << "学分" << "开课时间");

        // 从新打开的数据库中加载数据到tableView
        QList<cstudentinfo> stuInfoList;
        bool res = m_database->selectStudentInfo(stuInfoList);
        if (!res) {
            QMessageBox::information(this, "提示", "查询学生信息失败");
            return;
        }

        // 清除现有数据后，重新填充数据
        for (const cstudentinfo &stuInfo : stuInfoList) {
            // 为每个学生信息对象添加其考勤信息
            QList<cattendanceinfo> attendanceInfos = stuInfo.getAttendanceInfos();
            for (const cattendanceinfo &attendanceInfo : attendanceInfos) {
                // 创建表格行数据
                QList<QStandardItem*> rowItems;
                rowItems << new QStandardItem(QString::number(attendanceInfo.getAttendanceId()));
                rowItems << new QStandardItem(QString::number(stuInfo.getId()));
                rowItems << new QStandardItem(stuInfo.getName());
                rowItems << new QStandardItem(stuInfo.getSex());
                rowItems << new QStandardItem(QString::number(stuInfo.getAge()));
                rowItems << new QStandardItem(stuInfo.getClassname());
                rowItems << new QStandardItem(attendanceInfo.getCoursedate());
                rowItems << new QStandardItem(QString::number(attendanceInfo.getCoursenum()));
                rowItems << new QStandardItem(attendanceInfo.getCoursename());
                rowItems << new QStandardItem(attendanceInfo.getCoursetype());
                rowItems << new QStandardItem(QString::number(attendanceInfo.getCredit()));
                rowItems << new QStandardItem(attendanceInfo.getCourselauchtime());

                // 将行数据添加到模型中
                m_standarditemmodel->appendRow(rowItems);
            }
        }
    }
    MainWindow::on_action_Y_triggered();
}

// 从数据库中查询所有考勤记录和相关联的学生信息，并将这些数据加载到表格视图中，以便用户查看所有的考勤详情。
void MainWindow::on_action_Y_triggered()
{
    // 清空模型中的数据
    m_standarditemmodel->clear();

    // 设置表头
    m_standarditemmodel->setHorizontalHeaderLabels(QStringList() << "考勤ID" << "学号" << "姓名" << "性别" << "年龄" << "班级" << "缺课日期" << "第几节课" << "课程名称" << "缺课类型" << "学分" << "开课时间");

    // 执行一次查询获取所有考勤记录和相关的学生信息
    QSqlQuery query(m_database->getDb());
    query.exec("SELECT A.AttendanceId, M.Id AS StudentId, M.Name, M.Sex, M.Age, M.Classname, A.Coursedate, A.Coursenum, A.Coursename, A.Coursetype, A.Credit, A.Courselauchtime "
               "FROM Attendance A "
               "JOIN Members M ON A.StudentId = M.Id "
               "ORDER BY A.AttendanceId");

    while (query.next()) {
        // 创建表格行数据
        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(QString::number(query.value("AttendanceId").toInt()));
        rowItems << new QStandardItem(QString::number(query.value("StudentId").toInt()));
        rowItems << new QStandardItem(query.value("Name").toString());
        rowItems << new QStandardItem(query.value("Sex").toString());
        rowItems << new QStandardItem(QString::number(query.value("Age").toInt()));
        rowItems << new QStandardItem(query.value("Classname").toString());
        rowItems << new QStandardItem(query.value("Coursedate").toString());
        rowItems << new QStandardItem(QString::number(query.value("Coursenum").toInt()));
        rowItems << new QStandardItem(query.value("Coursename").toString());
        rowItems << new QStandardItem(query.value("Coursetype").toString());
        rowItems << new QStandardItem(QString::number(query.value("Credit").toDouble()));
        rowItems << new QStandardItem(query.value("Courselauchtime").toString());

        // 将行数据添加到模型中
        m_standarditemmodel->appendRow(rowItems);
    }
}

// 关闭当前的数据库连接（如果存在），创建用户指定的新数据库，并在其中初始化成员和考勤相关的数据表。完成后，函数还会更新表格视图，准备显示新数据库中的数据。
void MainWindow::on_action_N_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Create New Database"), QDir::homePath(), tr("SQLite Database (*.db *.sqlite)"));
    if (!fileName.isEmpty()) {
        // 关闭当前数据库连接（如果有）
        if (m_database) {
            delete m_database;
            m_database = nullptr;
        }

        // 创建一个新的数据库连接
        m_database = new csqlite(fileName);
        if (!m_database->getDb().isOpen()) {
            QMessageBox::critical(this, tr("Error"), tr("Failed to create database!"));
            delete m_database;
            m_database = nullptr;
            return;
        }

        // 初始化Members和Attendance表
        QSqlQuery query(m_database->getDb());
        query.exec("CREATE TABLE IF NOT EXISTS Members ("
                   "Id INTEGER PRIMARY KEY,"
                   "Name TEXT NOT NULL,"
                   "Sex TEXT,"
                   "Age INTEGER,"
                   "Classname TEXT)");
        query.exec("CREATE TABLE IF NOT EXISTS Attendance ("
                   "AttendanceId INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "StudentId INTEGER,"
                   "Coursedate TEXT,"
                   "Coursenum INTEGER,"
                   "Coursename TEXT,"
                   "Coursetype TEXT,"
                   "Credit REAL,"
                   "Courselauchtime TEXT,"
                   "FOREIGN KEY(StudentId) REFERENCES Members(Id) ON DELETE CASCADE)");

        // 更新tableView
        m_standarditemmodel->clear();
        m_standarditemmodel->setHorizontalHeaderLabels(QStringList() << "考勤ID" << "学号" << "姓名" << "性别" << "年龄" << "班级" << "缺课日期" << "第几节课" << "课程名称" << "缺课类型" << "学分" << "开课时间");
    }
}

// 从当前显示的表格中收集所有学生信息，包括学生的基本资料和考勤记录，然后将这些信息传递给专门的分析对话框进行进一步的处理和展示。
void MainWindow::on_action_T_triggered()

{

    QList<cstudentinfo> allData;

    for (int row = 0; row < m_standarditemmodel->rowCount(); ++row)
    {
        cstudentinfo stuInfo;
        stuInfo.setAttendanceId(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_ATTENDANCEID)).toInt());
        stuInfo.setId(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_ID)).toInt());
        stuInfo.setName(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_NAME)).toString());
        stuInfo.setSex(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_SEX)).toString());
        stuInfo.setAge(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_AGE)).toInt());
        stuInfo.setClassname(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_CLASSNAME)).toString());
        stuInfo.setCoursedate(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSEDATE)).toString());
        stuInfo.setCoursenum(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSENUM)).toInt());
        stuInfo.setCoursename(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSENAME)).toString());
        stuInfo.setCoursetype(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSETYPE)).toString());
        stuInfo.setCredit(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_CREDIT)).toDouble());
        stuInfo.setCourselauchtime(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_COURSELAUNCHTIME)).toString());
        allData.append(stuInfo);

    }

    analyzestudentinfo analyzeDialog(this);
    analyzeDialog.setPassedStudentInfoList(allData);
    analyzeDialog.exec();

}

// 将缓存中的数据保存到数据库。
bool MainWindow::saveDataToDatabase(QSqlDatabase &db)
{
    // 开始事务
    if (!db.transaction()) {
        qDebug() << "Failed to start transaction.";
        return false;
    }

    try {
        // 遍历m_standarditemmodel的所有行
        for (int row = 0; row < m_standarditemmodel->rowCount(); ++row) {
            cstudentinfo stuInfo;

            // 提取学生基本信息
            stuInfo.setId(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_ID)).toInt());
            stuInfo.setName(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_NAME)).toString());
            stuInfo.setSex(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_SEX)).toString());
            stuInfo.setAge(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_AGE)).toInt());
            stuInfo.setClassname(m_standarditemmodel->data(m_standarditemmodel->index(row, CONST_COL_CLASSNAME)).toString());

            // 保存学生基本信息到Members表
            QSqlQuery membersQuery(db);
            membersQuery.prepare("INSERT OR REPLACE INTO Members (Id, Name, Sex, Age, Classname) VALUES (?, ?, ?, ?, ?)");
            membersQuery.addBindValue(stuInfo.getId());
            membersQuery.addBindValue(stuInfo.getName());
            membersQuery.addBindValue(stuInfo.getSex());
            membersQuery.addBindValue(stuInfo.getAge());
            membersQuery.addBindValue(stuInfo.getClassname());

            membersQuery.exec();

            // 保存考勤信息到Attendance表
            for (const auto& attendanceInfo : stuInfo.getAttendanceInfos()) {
                QSqlQuery attendanceQuery(db);
                attendanceQuery.prepare("INSERT OR REPLACE INTO Attendance (AttendanceId, StudentId, Coursedate, Coursenum, Coursename, Coursetype, Credit, Courselauchtime) "
                                        "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
                attendanceQuery.addBindValue(attendanceInfo.getAttendanceId());
                attendanceQuery.addBindValue(attendanceInfo.getStudentId());
                attendanceQuery.addBindValue(attendanceInfo.getCoursedate());
                attendanceQuery.addBindValue(attendanceInfo.getCoursenum());
                attendanceQuery.addBindValue(attendanceInfo.getCoursename());
                attendanceQuery.addBindValue(attendanceInfo.getCoursetype());
                attendanceQuery.addBindValue(attendanceInfo.getCredit());
                attendanceQuery.addBindValue(attendanceInfo.getCourselauchtime());

                attendanceQuery.exec();
            }
        }

        // 提交事务
        db.commit();
    } catch (const std::exception& e) {
        qDebug() << "Exception caught: " << e.what();
        db.rollback();
        return false;
    }

    return true;
}

//保存当前数据到已连接的数据库。
void MainWindow::on_action_S_triggered()
{
    // 获取当前数据库连接
    QSqlDatabase currentDb = QSqlDatabase::database();

    // 检查数据库连接
    if (!currentDb.isOpen()) {
        QMessageBox::critical(this, tr("Error"), tr("No active database connection!"));
        return;
    }

    // 调用保存数据到数据库的函数
    if (!saveDataToDatabase(currentDb)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to save data to the current database!"));
        return;
    }
}

//另存为当前数据到外部数据库。
void MainWindow::on_action_triggered()
{
    // 1. 选择保存文件
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Database As"), QDir::homePath(), tr("SQLite Database (*.db *.sqlite)"));
    if (fileName.isEmpty()) {
        return; // 用户取消了操作
    }

    // 2. 创建新的数据库连接
    QSqlDatabase newDb = QSqlDatabase::addDatabase("QSQLITE");
    newDb.setDatabaseName(fileName);
    if (!newDb.open()) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to create new database!"));
        return;
    }

    // 3. 创建表结构
    QSqlQuery query(newDb);
    query.exec("CREATE TABLE IF NOT EXISTS Members ("
               "Id INTEGER PRIMARY KEY,"
               "Name TEXT NOT NULL,"
               "Sex TEXT,"
               "Age INTEGER,"
               "Classname TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS Attendance ("
               "AttendanceId INTEGER PRIMARY KEY AUTOINCREMENT,"
               "StudentId INTEGER,"
               "Coursedate TEXT,"
               "Coursenum INTEGER,"
               "Coursename TEXT,"
               "Coursetype TEXT,"
               "Credit REAL,"
               "Courselauchtime TEXT,"
               "FOREIGN KEY(StudentId) REFERENCES Members(Id) ON DELETE CASCADE)");

    // 4. 调用保存数据到数据库的函数
    if (!saveDataToDatabase(newDb)) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to save data to the new database!"));
        return;
    }
}

void adaptMessageBoxForTheme(bool isDarkMode)
{
    QString styleSheet;
    if (isDarkMode) {
        styleSheet = "QMessageBox {"
                     "   background-color: black;"
                     "   color: white;"
                     "}"
                     "QMessageBox QLabel {"
                     "   color: white;"
                     "}"
                     "QMessageBox QPushButton {"
                     "   background-color: #555;"
                     "   color: white;"
                     "}"
                     "QMessageBox QPushButton:hover {"
                     "   background-color: #666;"
                     "}"
                     "QMessageBox QPushButton:pressed {"
                     "   background-color: #444;"
                     "}";
    } else {
        styleSheet = "QMessageBox {"
                     "   background-color: white;"
                     "   color: black;"
                     "}"
                     "QMessageBox QLabel {"
                     "   color: black;"
                     "}"
                     "QMessageBox QPushButton {"
                     "   background-color: #ccc;"
                     "   color: black;"
                     "}"
                     "QMessageBox QPushButton:hover {"
                     "   background-color: #ddd;"
                     "}"
                     "QMessageBox QPushButton:pressed {"
                     "   background-color: #bbb;"
                     "}";
    }

    qApp->setStyleSheet(styleSheet);
}

// 切换主题模式。
void MainWindow::switchTheme(bool isDarkMode)
{
    // 创建一个新的QPalette对象
    QPalette palette;

    // 根据isDarkMode的值设置不同的颜色方案
    if (isDarkMode) {
        // 深色主题颜色设置
        ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: #333; color: white; }");
        ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section { background-color: #333; color: white; }");
        ui->menubar->setStyleSheet("QMenuBar { background-color: black; color: white; }");
        ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: #333; color: white; }");
        ui->lineEdit_id->setStyleSheet("QLineEdit { background-color: #333; color: white; }");
        ui->lineEdit_name->setStyleSheet("QLineEdit { background-color: #333; color: white; }");
        ui->pushButton_add->setStyleSheet("QPushButton { background-color: #333; color: white; }");
        ui->pushButton_del->setStyleSheet("QPushButton { background-color: #333; color: white; }");
        ui->pushButton_edit->setStyleSheet("QPushButton { background-color: #333; color: white; }");
        ui->pushButton_query->setStyleSheet("QPushButton { background-color: #333; color: white; }");
        palette.setColor(QPalette::Window, QColor(53, 53, 53)); // 背景颜色
        palette.setColor(QPalette::WindowText, Qt::white);     // 文字颜色
        palette.setColor(QPalette::Base, QColor(53, 53, 53));   // 主体颜色
        palette.setColor(QPalette::AlternateBase, QColor(53, 53, 53)); // 替代基础颜色
        palette.setColor(QPalette::ToolTipBase, Qt::white);    // 工具提示背景颜色
        palette.setColor(QPalette::ToolTipText, Qt::white);    // 工具提示文字颜色
        palette.setColor(QPalette::Text, Qt::white);           // 文字颜色
        palette.setColor(QPalette::Button, Qt::darkGray); // 按钮颜色
        palette.setColor(QPalette::ButtonText, Qt::white);     // 按钮文字颜色
        palette.setColor(QPalette::BrightText, Qt::red);       // 高亮文本颜色
        palette.setColor(QPalette::Link, QColor(42, 130, 218)); // 链接颜色
        palette.setColor(QPalette::Highlight, QColor(42, 130, 218)); // 高亮颜色
        palette.setColor(QPalette::HighlightedText, Qt::black);// 高亮文字颜色
    } else {
        // 浅色主题颜色设置
        ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: #DDD; color: black; }");
        ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section { background-color: #DDD; color: black; }");
        ui->menubar->setStyleSheet("QMenuBar { background-color: #EEE; color: black; }");
        ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: #DDD; color: black; }");
        ui->lineEdit_id->setStyleSheet("QLineEdit { background-color: white; color: black; border: 1px solid #CCC; }");
        ui->lineEdit_name->setStyleSheet("QLineEdit { background-color: white; color: black; border: 1px solid #CCC; }");
        ui->pushButton_add->setStyleSheet("QPushButton { background-color: #EEE; color: black; border: 1px solid #AAA; }");
        ui->pushButton_del->setStyleSheet("QPushButton { background-color: #EEE; color: black; border: 1px solid #AAA; }");
        ui->pushButton_edit->setStyleSheet("QPushButton { background-color: #EEE; color: black; border: 1px solid #AAA; }");
        ui->pushButton_query->setStyleSheet("QPushButton { background-color: #EEE; color: black; border: 1px solid #AAA; }");

        // Palette settings for the widget's background and text colors
        palette.setColor(QPalette::Window, Qt::white);
        palette.setColor(QPalette::WindowText, Qt::black);
        palette.setColor(QPalette::Base, Qt::white);
        palette.setColor(QPalette::AlternateBase, Qt::lightGray);
        palette.setColor(QPalette::ToolTipBase, Qt::white);
        palette.setColor(QPalette::ToolTipText, Qt::black);
        palette.setColor(QPalette::Text, Qt::black);
        palette.setColor(QPalette::Button, Qt::lightGray);
        palette.setColor(QPalette::ButtonText, Qt::black);
        palette.setColor(QPalette::BrightText, Qt::red);
        palette.setColor(QPalette::Link, QColor(0, 0, 255));
        palette.setColor(QPalette::Highlight, QColor(0, 120, 215));
        palette.setColor(QPalette::HighlightedText, Qt::white);

    }

    // 应用新的QPalette到QApplication中
    QApplication::setPalette(palette);

    // 更新所有窗口部件的样式
    this->style()->unpolish(this);
    this->style()->polish(this);
    this->update();

    adaptMessageBoxForTheme(isDarkMode);
}

// 判断是否启用深色主题。
bool MainWindow::isDarkModeEnabled()
{
    QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);
    int appsUseLightTheme = settings.value("AppsUseLightTheme", 1).toInt();
    return appsUseLightTheme == 0;
}

void MainWindow::on_action_2_triggered()
{
    switchTheme(true);
}

void MainWindow::on_action_3_triggered()
{
    switchTheme(false);
}

void MainWindow::on_action_4_triggered()
{
    bool isDarkMode = isDarkModeEnabled();
    switchTheme(isDarkMode);
}

void MainWindow::on_action_R_triggered()
{
    MainWindow::on_pushButton_del_clicked();
}

void MainWindow::on_action_I_triggered()
{
    MainWindow::on_pushButton_add_clicked();
}

void MainWindow::on_action_E_triggered()
{
    MainWindow::on_pushButton_edit_clicked();
}

void MainWindow::on_action_Q_triggered()
{
    MainWindow::on_pushButton_query_clicked();
}
