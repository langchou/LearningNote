#pragma once
#include<iostream>
#include "Identity.h"
#include"Student.h"
#include"Teacher.h"
#include "globalFile.h"
#include "computerRoom.h"
#include "Student.h"
#include "Teacher.h"
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
/*
- 显示管理员操作的菜单界面

- 添加账号

- 查看账号

- 查看机房信息

- 清空预约记录
*/

class Manager :public Identity
{
	public:
	Manager();
	Manager(string name, string pwd);
	//展示菜单
	virtual void operMenu();
	//添加账号  
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();
	//初始化容器
	void initVector();
	//添加学生时检测重复 id为编号 type为类型(学生/老师)
	bool checkRepeat(int id,int type);


	vector<Student>vStudent;
	vector<Teacher>vTeacher;
};