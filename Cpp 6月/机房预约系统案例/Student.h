#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include "Identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"

using namespace std;
/*
  学生类功能
  显示学生操作的菜单界面
  申请预约
  查看自身预约
  查看所有预约
  取消预约
*/


class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(int id, string name, string pwd);
	//展示菜单
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//展示自己预约
	void showMyOrder();
	//展示所有预约
	void showAllOrder(); 
	//取消预约
	void cancelOrder();

	int Id;
	vector<computerRoom>vCom;
};