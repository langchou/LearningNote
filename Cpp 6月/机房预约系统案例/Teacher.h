#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"

/*
  老师类功能
  显示教师操作的菜单界面
  查看所有预约
  审核预约
*/


class Teacher :public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int id, string name, string pwd);
	//展示菜单
	virtual void operMenu();
	//展示所有预约
	void showAllOrder();
	//审核预约
	void valiOrder();

	int EmpId;
};