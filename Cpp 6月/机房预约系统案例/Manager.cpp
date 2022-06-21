#include "Manager.h"

Manager::Manager()
{
	
}

Manager::Manager(string name, string pwd)
{
	this->name = name;
	this->pwd = pwd;

	//初始化容器
	this->initVector();	
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
	string errorTip;
	ofstream ofs;

	int select = -1;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号： ";
		errorTip = "学号重复,";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号： ";
		errorTip = "职工编号重复,";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	//检测重复
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
	cout << "请输入用户名： ";
	cin >> name;
	cout << "请输入密码： ";
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	//添加新账号后，可以立马重复添加，初始化解决bug
	this->initVector();
	system("pause");
	system("cls");
}

void printStudent(Student s)
{
	cout << "学号：" << s.Id << " 用户名：" << s.name << " 密码：" << s.pwd << endl;
}

void printTeacher(Teacher t)
{
	cout << "职工号：" << t.EmpId << " 用户名：" << t.name << " 密码：" << t.pwd << endl;
}

void Manager::showPerson() 
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;
	int select = -1;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStudent.begin(), vStudent.end(), printStudent);
	}
	else if (select == 2)
	{
		cout << "所有老师信息如下：" << endl;
		for_each(vTeacher.begin(), vTeacher.end(), printTeacher);
	}
}

void printCom(computerRoom c)
{
	cout << "机房编号：" << c.comId << " 机房最大容量：" << c.comMaxSize << endl;
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
	cout << "当前机房数量为：" << vCom.size() << endl;
	cout << "机房信息如下：" << endl;
	for_each(vCom.begin(), vCom.end(), printCom);
	ifs.close();
}

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清除成功" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	//载入学生文本信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
	}
	//容器初始化
	vStudent.clear();
	vTeacher.clear();
	Student s;
	while (ifs >> s.Id && ifs >> s.name && ifs >> s.pwd)
	{
		vStudent.push_back(s);
	}
	cout << "当前有 " << vStudent.size() << " 个学生账号" << endl;
	ifs.close();//学生初始化结束

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
	}
	Teacher t;
	while (ifs >> t.EmpId && ifs >> t.name && ifs >> t.pwd)
	{
		vTeacher.push_back(t);
	}
	cout << "当前有 " << vTeacher.size() << " 个老师账号" << endl;
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