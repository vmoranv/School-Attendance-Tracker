# **School-Attendance-Tracker**

## :bulb: Brief Introduction

SAT是一个高效易用的学生出勤管理系统,旨在简化考勤记录与分析过程.使用Qt 5.14.1开发,通过SQLite保存在本地。

## :white_check_mark: Already Done

1. `mainwindow.ui` `addstudentinfo.ui` `editstudentinfo.ui` `analyzestudentinfo.ui`设计
2. `studentinfo` `cstudentinfo`类设计
3. `csqlite`构造函数实现创建`SQLite`表单
4. `cstudentinfo`私有变量的获取和设定函数

## :memo:To Do

- [x] 实现`csqlite`中的几个操作函数
- [x] 设计`Add` `Edit` `Analyze`界面并在使用该功能时弹窗
- [x] 实现`editstudentinfo.ui`
- [ ] 实现统计功能
- [ ] 实现本地`sqlite`数据库访问与`sql`语句查询
- [ ] 默认界面提示
- [x] UI优化
- [ ] `editstudentinfo.ui`直接复用`addstudentinfo.ui`
- [ ] 快捷键实现
- [ ] 外观根据系统更改
- [ ] 打开新建保存数据库实现

## :warning: Fatal Error

- [x] ~~默认`SQLite`表单在`Debug`过程中出现缺少参数~~
- [ ] `addstudentinfo.ui`无法传数据到`mainwindow.ui`并`update`到`tableview`上
