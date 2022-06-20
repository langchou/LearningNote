#pragma once
#include "Identity.h"

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
};