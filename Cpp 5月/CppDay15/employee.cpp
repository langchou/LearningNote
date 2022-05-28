#include "employee.h"


Emplyee::Emplyee(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Emplyee::ShowInfo()
{
	cout << "职工编号:" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:完成经理的任务" << endl;
}

string Emplyee::getDeptName()
{
	return string("员工");
}