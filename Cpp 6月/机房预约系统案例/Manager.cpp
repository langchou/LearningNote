#include "Manager.h"
#include "globalFile.h"
#include <fstream>


Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->name = name;
	this->pwd = pwd;
}

void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号： ";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号： ";
	}
	int id;
	string name;
	string pwd;
	cout << tip;
	cin >> id;
	cout << "请输入用户名： ";
	cin >> name;
	cout << "请输入密码： ";
	cin >> pwd;

	ofs.open(fileName, ios::out | ios::app);
	ofs << endl;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}

void Manager::showPerson() 
{

}

void Manager::showComputer()
{

}

void Manager::cleanFile()
{

}