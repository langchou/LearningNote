#include "Manager.h"

Manager::Manager()
{
	
}

Manager::Manager(string name, string pwd)
{
	this->name = name;
	this->pwd = pwd;

	//��ʼ������
	this->initVector();	
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
	string errorTip;
	ofstream ofs;

	int select = -1;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ� ";
		errorTip = "ѧ���ظ�,";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ� ";
		errorTip = "ְ������ظ�,";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	//����ظ�
	while (true)
	{
		cout << tip;
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip;
		}
		else
		{
			break;
		}
	}
	cout << "�������û����� ";
	cin >> name;
	cout << "���������룺 ";
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	//������˺ź󣬿��������ظ���ӣ���ʼ�����bug
	this->initVector();
	system("pause");
	system("cls");
}

void printStudent(Student s)
{
	cout << "ѧ�ţ�" << s.Id << " �û�����" << s.name << " ���룺" << s.pwd << endl;
}

void printTeacher(Teacher t)
{
	cout << "ְ���ţ�" << t.EmpId << " �û�����" << t.name << " ���룺" << t.pwd << endl;
}

void Manager::showPerson() 
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int select = -1;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStudent.begin(), vStudent.end(), printStudent);
	}
	else if (select == 2)
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTeacher.begin(), vTeacher.end(), printTeacher);
	}
}

void printCom(computerRoom c)
{
	cout << "������ţ�" << c.comId << " �������������" << c.comMaxSize << endl;
}

void Manager::showComputer()
{
	vector<computerRoom>vCom;
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom c;
	while (ifs >> c.comId && ifs >> c.comMaxSize)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
	cout << "������Ϣ���£�" << endl;
	for_each(vCom.begin(), vCom.end(), printCom);
	ifs.close();
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	//����ѧ���ı���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
	}
	//������ʼ��
	vStudent.clear();
	vTeacher.clear();
	Student s;
	while (ifs >> s.Id && ifs >> s.name && ifs >> s.pwd)
	{
		vStudent.push_back(s);
	}
	cout << "��ǰ�� " << vStudent.size() << " ��ѧ���˺�" << endl;
	ifs.close();//ѧ����ʼ������

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
	}
	Teacher t;
	while (ifs >> t.EmpId && ifs >> t.name && ifs >> t.pwd)
	{
		vTeacher.push_back(t);
	}
	cout << "��ǰ�� " << vTeacher.size() << " ����ʦ�˺�" << endl;
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStudent.begin(); it != vStudent.end(); it++)
		{
			if (id == it->Id) return true;
		}
	}
	else if(type == 2)
	{
		for (vector<Teacher>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++)
		{
			if (id == it->EmpId) return true;
		}
	}
	return false;
}