#include "WorkerManager.h"


WorkerManager::WorkerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		//初始化指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空!" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		//初始化指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	
	//文件存在 记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为:" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据，存到数组中
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号:" << this->m_EmpArray[i]->m_Id
	//		<< "姓名:" << this->m_EmpArray[i]->m_Name
	//		<< "部门编号:" << this->m_EmpArray[i]->m_DeptId
	//		<< endl;
	//}
}

//菜单
void WorkerManager::ShowMenu()
{
	cout << "********************************" << endl;
	cout << "******欢迎使用职工管理系统******" << endl;
	cout << "******   0.退出管理系统   ******" << endl;
	cout << "******   1.增加职工信息   ******" << endl;
	cout << "******   2.显示职工信息   ******" << endl;
	cout << "******   3.删除职工信息   ******" << endl;
	cout << "******   4.修改职工信息   ******" << endl;
	cout << "******   5.查找职工信息   ******" << endl;
	cout << "******   6.按照编号排序   ******" << endl;
	cout << "******   7.清空所有文档   ******" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

//退出
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量:" << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//执行具体添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i<this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工姓名
			string name;//职工编号
			int dSelect;//部门选择

			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位"<< endl;
			cout << "1.普通职工"<< endl;
			cout << "2.经理"<< endl;
			cout << "3.老板"<< endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Emplyee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//将创建的职工指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有的空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//更新职工后 不为空标志
		this->m_FileIsEmpty = false;
		//提示
		cout << "成功添加" << addNum <<"名新职工" << endl;

		//保存数据到文件中
		this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}

	//按任意键后 清屏回到上级目录
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出的方式打开文件 -写文件

	//将每个人的数据写入文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

//统计人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//普通员工
		{
			worker = new Emplyee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//老板
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}



WorkerManager::~WorkerManager()
{

}
