# **School-Attendance-Tracker**

## :bulb: Brief Introduction

SAT是一个高效易用的学生出勤管理系统,旨在简化考勤记录与分析过程.使用Qt 5.14.1开发,通过SQLite保存在本地。

## :white_check_mark: Already Done

1. `mainwindow.ui` `addstudentinfo.ui` `editstudentinfo.ui` `analyzestudentinfo.ui`设计
2. `studentinfo` `cstudentinfo` `cattendance`类设计
3. `csqlite`构造函数实现创建`SQLite`表单
4. `cstudentinfo`私有变量的获取和设定函数

## :memo:To Do

- [x] 实现`csqlite`中的几个操作函数
- [x] 设计`Add` `Edit` `Analyze`界面并在使用该功能时弹窗
- [x] 实现`editstudentinfo.ui`
- [x] 实现统计功能
- [x] 实现本地`sqlite`数据库访问与`sql`语句查询
- [x] 默认界面提示
- [x] UI优化
- [x] 跟随系统切换主题

## :warning: Vital Error

- [x] ~~默认`SQLite`表单在`Debug`过程中出现缺少参数~~
- [x] ~~`add`界面添加后无回显~~
- [x] ~~数据库存储bug~~
- [x] ~~双表适配~~
- [x] ~~弹窗颜色不统一~~
