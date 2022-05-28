#pragma once //防止头文件重复包含
#include <iostream>

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
	//析构函数
	~WorkerManager();

};