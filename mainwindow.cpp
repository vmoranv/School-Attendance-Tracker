#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dataSource = new studentInfo();


    QStandardItemModel* standardModel = new QStandardItemModel(this);
    QList<studentInfo> stuInfosList;
    if (selectstuInfos(stuInfosList))
    {
        populateStandardModel(standardModel, stuInfosList);
        ui->listView->setModel(standardModel);
    }
    else
    {
        QMessageBox::warning(0, "错误", "创建QList失败");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dataSource;
}

void MainWindow::populateStandardModel(QStandardItemModel* model, const QList<studentInfo>& stuInfosList)
{    
    for (const auto& stuInfo : stuInfosList) {
        QList<QStandardItem*> rowItems;

        auto addItemWithAlignment = [&](const QVariant& data, bool editable = true) {
            auto* item = new QStandardItem(data.toString());
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            item->setEditable(editable);
            rowItems << item;
        };

        addItemWithAlignment(stuInfo.getId());
        addItemWithAlignment(stuInfo.getName());
        addItemWithAlignment(stuInfo.getSex());
        addItemWithAlignment(stuInfo.getAge());
        addItemWithAlignment(stuInfo.getClassname());
        addItemWithAlignment(stuInfo.getCoursedate());
        addItemWithAlignment(stuInfo.getCoursenum());
        addItemWithAlignment(stuInfo.getCoursename());
        addItemWithAlignment(stuInfo.getCoursetype());
        addItemWithAlignment(QString::number(stuInfo.getCredit(), 'f', 2));
        addItemWithAlignment(stuInfo.getCourselauchtime());

        model->appendRow(rowItems);
    }
}

void MainWindow::onStudentAdded(const studentInfo& newstudent)
{
    studentInfo newStudent = newstudent;
    if (addstuInfos(newStudent)) {
        QMessageBox::information(this, "Success", "Student added successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to add the student.");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier) {
        switch (event->key()) {
            case Qt::Key_G:
                on_action_Globalshow_triggered();
                break;
            case Qt::Key_O:
                on_action_Open_triggered();
                break;
            case Qt::Key_Q:
                on_action_Query_triggered();
                break;
            case Qt::Key_S:
                on_action_S_triggered();
                break;
            case Qt::Key_T:
                on_action_TotalAnalize_triggered();
                break;
            case Qt::Key_I:
                on_action_Insert_triggered();
                break;
            case Qt::Key_D:
                on_action_Delete_triggered();
                break;
            case Qt::Key_N:
                on_action_N_triggered();
                break;
            default:
                break;
        }
    }
    else if (event->modifiers() == Qt::ControlModifier && event->modifiers() == Qt::ShiftModifier) {
                switch (event->key()) {
                case Qt::Key_S:
                    on_action_Save_triggered();
                default:
                    break;
                }
    }
}


bool MainWindow::selectstuInfos(QList<studentInfo> &stuInfosList)
{
    if(!students.open())
    {
        return false;
    }
    QSqlQuery sqlquery;
    QString sqlq=("SELECT * FROM students");
    if(!sqlquery.exec(sqlq))
    {
        qDebug()<<"Failed to selcet students;";
        return false;
    }
    while (sqlquery.next()) {
        int Id = sqlquery.value("Id").toInt();
        QString Name = sqlquery.value("Name").toString();
        QString sex = sqlquery.value("sex").toString();
        int age = sqlquery.value("age").toInt();
        QString classname = sqlquery.value("classname").toString();
        QString coursedate = sqlquery.value("coursedate").toString();
        int coursenum = sqlquery.value("coursenum").toInt();
        QString coursename = sqlquery.value("coursename").toString();
        QString coursetype = sqlquery.value("coursetype").toString();
        double credit = sqlquery.value("credit").toDouble();
        QString courselauchtime = sqlquery.value("courselauchtime").toString();

        studentInfo *newStudent = new studentInfo();
        newStudent->setData(
            Id,
            Name,
            sex,
            age,
            classname,
            coursedate,
            coursenum,
            coursename,
            coursetype,
            credit,
            courselauchtime
        );
        stuInfosList.append(*newStudent);
    }
    students.close();
    return true;
}

bool MainWindow::addstuInfos(studentInfo &stuInfos)
{
    QSqlQuery query;
    QString insertQuery = "INSERT INTO students (Id, Name, Sex, Age, ClassName, CourseDate, CourseNum, CourseName, CourseType, Credit, CourseLaunchTime) "
                          "VALUES (:Id, :Name, :Sex, :Age, :ClassName, :CourseDate, :CourseNum, :CourseName, :CourseType, :Credit, :CourseLaunchTime)";

    query.prepare(insertQuery);
    query.bindValue(":Id", stuInfos.getId());
    query.bindValue(":Name", stuInfos.getName());
    query.bindValue(":Sex", stuInfos.getSex());
    query.bindValue(":Age", stuInfos.getAge());
    query.bindValue(":ClassName", stuInfos.getClassname());
    query.bindValue(":CourseDate", stuInfos.getCoursedate());
    query.bindValue(":CourseNum", stuInfos.getCoursenum());
    query.bindValue(":CourseName", stuInfos.getCoursename());
    query.bindValue(":CourseType", stuInfos.getCoursetype());
    query.bindValue(":Credit", stuInfos.getCredit());
    query.bindValue(":CourseLaunchTime", stuInfos.getCourselauchtime());

    if (!query.exec()) {
        qDebug() << "Failed to insert student record: " << query.lastError().text();
        return false;
    }

    return true;
}

bool MainWindow::delstuInfos(int Id)
{
    QSqlQuery query;
    QString deleteQuery = "DELETE FROM students WHERE Id = :Id";

    query.prepare(deleteQuery);
    query.bindValue(":Id", Id);

    if (!query.exec()) {
        qDebug() << "Failed to delete student record: " << query.lastError().text();
        return false;
    }

    return true;
}

bool MainWindow::editstuInfos(studentInfo &stuInfos)
{
    QSqlQuery query;
    QString updateQuery = "UPDATE students SET Name = :Name, Sex = :Sex, Age = :Age, ClassName = :ClassName, CourseDate = :CourseDate, "
                          "CourseNum = :CourseNum, CourseName = :CourseName, CourseType = :CourseType, Credit = :Credit, "
                          "CourseLaunchTime = :CourseLaunchTime WHERE Id = :Id";

    query.prepare(updateQuery);
    query.bindValue(":Id", stuInfos.getId());
    query.bindValue(":Name", stuInfos.getName());
    query.bindValue(":Sex", stuInfos.getSex());
    query.bindValue(":Age", stuInfos.getAge());
    query.bindValue(":ClassName", stuInfos.getClassname());
    query.bindValue(":CourseDate", stuInfos.getCoursedate());
    query.bindValue(":CourseNum", stuInfos.getCoursenum());
    query.bindValue(":CourseName", stuInfos.getCoursename());
    query.bindValue(":CourseType", stuInfos.getCoursetype());
    query.bindValue(":Credit", stuInfos.getCredit());
    query.bindValue(":CourseLaunchTime", stuInfos.getCourselauchtime());

    if (!query.exec()) {
        qDebug() << "Failed to update student record: " << query.lastError().text();
        return false;
    }

    return true;
}


void MainWindow::on_pushButton_query_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString name = ui->lineEdit_name->text();
    ui->listView->reset();

    if (!id.isEmpty() && !name.isEmpty()) {
        qDebug() << "Both ID and name provided, but typically you'd choose one or handle this differently.";
    } else if (!id.isEmpty()) {
        queryAndDisplayWithCondition("Id = " + id);
    } else if (!name.isEmpty()) {
        queryAndDisplayWithCondition("Name = '" + name + "'");
    } else {
        QMessageBox::information(this, "提示", "Please enter an ID or a name to search.");
    }
}

void MainWindow::displayStudentRecord(const QSqlQuery &sqlquery)
{
    QString info = QString("ID: %1, Name: %2, Sex: %3, Age: %4, Class: %5, Course Date: %6, Course Number: %7, Course Name: %8, Course Type: %9, Credit: %10, Course Launch Time: %11\n")
                   .arg(sqlquery.value("Id").toString())
                   .arg(sqlquery.value("Name").toString())
                   .arg(sqlquery.value("sex").toString())
                   .arg(sqlquery.value("age").toString())
                   .arg(sqlquery.value("classname").toString())
                   .arg(sqlquery.value("coursedate").toString())
                   .arg(sqlquery.value("coursenum").toString())
                   .arg(sqlquery.value("coursename").toString())
                   .arg(sqlquery.value("coursetype").toString())
                   .arg(sqlquery.value("credit").toString())
                   .arg(sqlquery.value("courselauchtime").toString());
    ui->listView->show();
}

void MainWindow::queryAndDisplayWithCondition(const QString &condition)
{
    if (!students.open()) {
        QMessageBox::warning(this, "错误", "无法打开数据库");
        return;
    }

    QSqlQuery sqlquery;
    QString sqlq = "SELECT * FROM students WHERE " + condition;

    if (sqlquery.exec(sqlq)) {
        while (sqlquery.next()) {
            displayStudentRecord(sqlquery);
        }
    } else {
         QMessageBox::warning(this, "错误", "查询失败：" + sqlquery.lastError().text());
    }
    students.close();
}

void MainWindow::queryAndDisplay()
{
    if (!students.open()) {
        QMessageBox::warning(this, "错误", "无法打开数据库");
        return;
    }

    QSqlQuery sqlquery("SELECT * FROM students");
    if (sqlquery.exec()) {
        while (sqlquery.next()) {
            displayStudentRecord(sqlquery);
        }
    } else {
         QMessageBox::warning(this, "错误", "查询失败：" + sqlquery.lastError().text());
    }
    students.close();
}

void MainWindow::on_action_Globalshow_triggered()
{
    queryAndDisplay();
}

void MainWindow::on_pushButton_add_clicked()
{
    addStudentInfo *addDialog = new addStudentInfo(this);
    connect(addDialog, &addStudentInfo::studentAdded, this, [&](const studentInfo &newStudent){
        insertStudentToDatabase(newStudent);
        addDialog->deleteLater();
    });
    addDialog->exec();
}

void MainWindow::insertStudentToDatabase(const studentInfo &stuInfos)
{
    QSqlQuery query;
    QString insertQuery = "INSERT INTO students (Id, Name, Sex, Age, ClassName, CourseDate, CourseNum, CourseName, CourseType, Credit, CourseLaunchTime) "
                          "VALUES (:Id, :Name, :Sex, :Age, :ClassName, :CourseDate, :CourseNum, :CourseName, :CourseType, :Credit, :CourseLaunchTime)";

    query.prepare(insertQuery);
    query.bindValue(":Id", stuInfos.getId());
    query.bindValue(":Name", stuInfos.getName());
    query.bindValue(":Sex", stuInfos.getSex());
    query.bindValue(":Age", stuInfos.getAge());
    query.bindValue(":ClassName", stuInfos.getClassname());
    query.bindValue(":CourseDate", stuInfos.getCoursedate());
    query.bindValue(":CourseNum", stuInfos.getCoursenum());
    query.bindValue(":CourseName", stuInfos.getCoursename());
    query.bindValue(":CourseType", stuInfos.getCoursetype());
    query.bindValue(":Credit", stuInfos.getCredit());
    query.bindValue(":CourseLaunchTime", stuInfos.getCourselauchtime());

    if (!query.exec()) {
        qDebug() << "Failed to insert student record: " << query.lastError().text();
    } else {
        qDebug() << "Student record inserted successfully.";
    }
}

void MainWindow::on_action_N_triggered()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("new_table.db");

    if (!db.open()) {
        QMessageBox::warning(this, "Error", "Unable to open database.");
        return;
    }

    QSqlQuery query;
    QString createTableQuery=QString("CREATE TABLE if not exists students (id INT PRIMARY KEY,name VARCHAR(255),sex INT,age INT,classname VARCHAR(255),coursedate DATE,coursenum INT,coursename VARCHAR(255),coursetype VARCHAR(255),credit DECIMAL(5, 2),courselauchtime DATETIME);");


    if (!query.exec(createTableQuery)) {
        QMessageBox::warning(this, "Error", "Failed to create table: " + query.lastError().text());
        db.close();
        return;
    }

    QMessageBox::information(this, "Success", "Table created successfully.");
    db.close();
}


void MainWindow::on_action_S_triggered()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Error", "Database is not open.");
        return;
    }

    QSqlQuery query;
    QString sqlQuery = "SELECT * FROM students";

    if (!query.exec(sqlQuery)) {
        QMessageBox::warning(this, "Error", "Failed to query database: " + query.lastError().text());
        return;
    }

    QFile file("students.sql");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Unable to open file for writing.");
        return;
    }

    QTextStream out(&file);
    while (query.next()) {
        QString row = query.value("Id").toString() + ", "
                       + query.value("Name").toString() + ", "
                       + query.value("Sex").toString() + ", "
                       + query.value("Age").toString() + ", "
                       + query.value("ClassName").toString() + ", "
                       + query.value("CourseDate").toString() + ", "
                       + query.value("CourseNum").toString() + ", "
                       + query.value("CourseName").toString() + ", "
                       + query.value("CourseType").toString() + ", "
                       + query.value("Credit").toString() + ", "
                       + query.value("CourseLaunchTime").toString() + "\n";
        out << row;
    }

    QMessageBox::information(this, "Success", "Table saved successfully.");
    file.close();
}

void MainWindow::on_action_Save_triggered()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, "Error", "Database is not open.");
        return;
    }

    QSqlQuery query;
    QString sqlQuery = "SELECT * FROM students";

    if (!query.exec(sqlQuery)) {
        QMessageBox::warning(this, "Error", "Failed to query database: " + query.lastError().text());
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Save Table As", "", "SQL Files (*.sql)");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Unable to open file for writing: " + fileName);
        return;
    }

    QTextStream out(&file);
    while (query.next()) {
        QString row = query.value("Id").toString() + ", "
                       + query.value("Name").toString() + ", "
                       + query.value("Sex").toString() + ", "
                       + query.value("Age").toString() + ", "
                       + query.value("ClassName").toString() + ", "
                       + query.value("CourseDate").toString() + ", "
                       + query.value("CourseNum").toString() + ", "
                       + query.value("CourseName").toString() + ", "
                       + query.value("CourseType").toString() + ", "
                       + query.value("Credit").toString() + ", "
                       + query.value("CourseLaunchTime").toString() + "\n";
        out << row;
    }

    QMessageBox::information(this, "Success", "Table saved successfully.");
    file.close();
}


void MainWindow::on_action_Query_triggered()
{
    MainWindow::on_pushButton_query_clicked();
}


void MainWindow::on_action_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "SQL Files (*.sql);;All Files (*)");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Unable to open file: " + fileName);
        return;
    }

    QTextStream in(&file);
    QString line;
    QStringList fields;
    QStandardItemModel* model = new QStandardItemModel(this);

    while (!in.atEnd()) {
        line = in.readLine();
        fields = line.split(',');
        if (fields.size() > 0) {
            QList<QStandardItem*> rowItems;
            for (int i = 0; i < fields.size(); ++i) {
                QStandardItem* item = new QStandardItem(fields[i]);
                rowItems << item;
            }
            model->appendRow(rowItems);
        }
    }

    ui->listView->setModel(model);
    file.close();
}


void MainWindow::on_action_TotalAnalize_triggered()
{

}

void MainWindow::on_action_Insert_triggered()
{
    MainWindow::on_pushButton_add_clicked();
}

void MainWindow::on_action_Delete_triggered()
{
    MainWindow::on_pushButton_del_clicked();
}

void MainWindow::on_pushButton_del_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString name = ui->lineEdit_name->text();

    if (!id.isEmpty()) {
        delstuInfos(id.toInt());
    } else if (!name.isEmpty()) {
        studentInfo stuInfo;
        stuInfo.setName(name);
        delstuInfos(id.toUInt());
    } else {
        QMessageBox::warning(this, "Error", "Please enter an ID or a name to delete.");
        return;
    }

    queryAndDisplay();
}

void MainWindow::onStudentEdited(const studentInfo& editedstudent) {
    studentInfo editedStudent = editedstudent;
    if (editstuInfos(editedStudent)) {
        QMessageBox::information(this, "Success", "Student information updated successfully.");
        queryAndDisplay();
    } else {
        QMessageBox::warning(this, "Error", "Failed to update the student information.");
    }
}

void MainWindow::on_pushButton_edit_clicked() {
    QModelIndex index = ui->listView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Error", "Please select a student to edit.");
        return;
    }

    QList<studentInfo> stuInfosList;
    if (selectstuInfos(stuInfosList)) {
        studentInfo stuInfo = stuInfosList[index.row()];
        editStudentInfoDialog = new editstudentinfo;

        connect(editStudentInfoDialog, &editstudentinfo::studentEdited, this, &MainWindow::onStudentEdited);
        editStudentInfoDialog->exec();
        editStudentInfoDialog->deleteLater();
    } else {
        QMessageBox::warning(0, "错误", "创建QList失败");
    }
}

