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
	cout << "��ӭ����Ա��" << this->name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ� ";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ� ";
	}
	int id;
	string name;
	string pwd;
	cout << tip;
	cin >> id;
	cout << "�������û����� ";
	cin >> name;
	cout << "���������룺 ";
	cin >> pwd;

	ofs.open(fileName, ios::out | ios::app);
	ofs << endl;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
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