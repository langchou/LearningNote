#pragma once 
#include <iostream>
using namespace std;

#include "worker.h"

class Emplyee : public Worker
{
public:
	//构造函数
	Emplyee(int id, string name, int dId);
	//展示个人信息
	virtual void ShowInfo();
	//获取岗位名称
	virtual string getDeptName() ;
};