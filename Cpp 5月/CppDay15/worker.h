#pragma once 
#include <iostream>

using namespace std;

//抽象类
class Worker
{
public:
	//展示个人信息
	virtual void ShowInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_Id;//员工编号
	string m_Name;//员工姓名
	int m_DeptId;//职工所在部门名称编号
};