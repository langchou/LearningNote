#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "globalFile.h"
#include "identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
#include <fstream>
#include <string>
using namespace std;

void managerMenu(Identity*& manager)
{
	while (true)
	{
		//展示子菜单
		manager->operMenu();
		//强转为子类，可以调用子类接口
		Manager* man = (Manager*)manager;

		int select = -1;
		cin >> select;
		switch (select)
		{
		case 1:
			man->addPerson();//添加账号
			break;
		case 2:
			man->showPerson();//查看账号
			break;
		case 3:
			man->showComputer();//查看机房信息
			break;
		case 4:
			man->cleanFile();//查看预约信息
			break;
		case 0:
			cout << "注销成功" << endl;
			return;
			system("pause");
			system("cls");
		default:
			break;
		}
	}	
}

void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;

		int select = -1;
		cin >> select;
		switch (select)
		{
		case 1: //申请预约
			stu->applyOrder();
			break;
		case 2: //展示自己预约
			stu->showMyOrder();
			break;
		case 3: //展示所有预约
			stu->showAllOrder();
			break;
		case 4: //取消预约
			stu->cancelOrder();
			break;
		case 0:
			cout << "注销成功" << endl;
			return;
			system("pause");
			system("cls");
		default:
			break;
		}
	}
}

void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = -1;
		cin >> select;
		switch (select)
		{
		case 1:
			tea->showAllOrder();
			break;
		case 2:
			tea->valiOrder();
			break;
		case 0:
			cout << "注销成功" << endl;
			return;
			system("pause");
			system("cls");
			break;
		default:
			break;
		}

	}
}

void LoginIn(string filename, int type)
{
	Identity* Person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	int id=0;
	string name;
	string pwd;

	if (type == 1)
	{
		//学生登录
		cout << "输入你的学号：";
		cin >> id;
	}
	else if (type == 2)
	{
		//老师登录
		cout << "输入你的工号：";
		cin >>id;
	}
	cout << "输入用户名：" ;
	cin >> name;
	cout << "输入密码：" ;
	cin >> pwd;

	//验证 
	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生登录验证成功" << endl;
				system("pause");
				system("cls");
				Person = new Student(id, name, pwd);
				//调用学生子菜单
				studentMenu(Person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//老师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师登录验证成功" << endl;
				system("pause");
				system("cls");
				Person = new Teacher(id, name, pwd);
				teacherMenu(Person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		int fId;
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				Person = new Manager(name, pwd);
				 //调用管理员子菜单
				managerMenu(Person);
				return;
			}
		}
	}

	cout << "登录验证失败!" << endl;

	system("pause");
	system("cls");
	return;
}

int main()
{
    int choice = 0;

    while (true)
    {
		cout << "======================  欢迎来到机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> choice;
		switch (choice)
		{
		case 1: //学生代表	
			LoginIn(STUDENT_FILE, choice);
			break;
		case 2: //老师
			LoginIn(TEACHER_FILE, choice);
			break;
		case 3: //管理员
			LoginIn(ADMIN_FILE, choice);
			break;
		case 0: //退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
    }
    system("pause");
    return EXIT_SUCCESS;
}