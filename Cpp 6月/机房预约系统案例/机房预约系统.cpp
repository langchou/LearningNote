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
		//չʾ�Ӳ˵�
		manager->operMenu();
		//ǿתΪ���࣬���Ե�������ӿ�
		Manager* man = (Manager*)manager;

		int select = -1;
		cin >> select;
		switch (select)
		{
		case 1:
			man->addPerson();//����˺�
			break;
		case 2:
			man->showPerson();//�鿴�˺�
			break;
		case 3:
			man->showComputer();//�鿴������Ϣ
			break;
		case 4:
			man->cleanFile();//�鿴ԤԼ��Ϣ
			break;
		case 0:
			cout << "ע���ɹ�" << endl;
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
		case 1: //����ԤԼ
			stu->applyOrder();
			break;
		case 2: //չʾ�Լ�ԤԼ
			stu->showMyOrder();
			break;
		case 3: //չʾ����ԤԼ
			stu->showAllOrder();
			break;
		case 4: //ȡ��ԤԼ
			stu->cancelOrder();
			break;
		case 0:
			cout << "ע���ɹ�" << endl;
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
			cout << "ע���ɹ�" << endl;
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
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	int id=0;
	string name;
	string pwd;

	if (type == 1)
	{
		//ѧ����¼
		cout << "�������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2)
	{
		//��ʦ��¼
		cout << "������Ĺ��ţ�";
		cin >>id;
	}
	cout << "�����û�����" ;
	cin >> name;
	cout << "�������룺" ;
	cin >> pwd;

	//��֤ 
	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				Person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
				studentMenu(Person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��¼��֤�ɹ�" << endl;
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
		//����Ա�����֤
		int fId;
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				Person = new Manager(name, pwd);
				 //���ù���Ա�Ӳ˵�
				managerMenu(Person);
				return;
			}
		}
	}

	cout << "��¼��֤ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}

int main()
{
    int choice = 0;

    while (true)
    {
		cout << "======================  ��ӭ��������ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> choice;
		switch (choice)
		{
		case 1: //ѧ������	
			LoginIn(STUDENT_FILE, choice);
			break;
		case 2: //��ʦ
			LoginIn(TEACHER_FILE, choice);
			break;
		case 3: //����Ա
			LoginIn(ADMIN_FILE, choice);
			break;
		case 0: //�˳�
			cout << "��ӭ�´�ʹ��" << endl;
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