#pragma once //防止头文件重复包含
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	//展示菜单
	void ShowMenu();
	//退出程序
	void ExitSystem();
	//添加职工
	void Add_Emp();
	//文件保存
	void save();
	//职工数组数组
	Worker** m_EmpArray;
	//析构函数
	~WorkerManager();



	//记录文件中的人数个数
	int m_EmpNum;
	//判断文件是否为空
	bool m_FileIsEmpty;

};