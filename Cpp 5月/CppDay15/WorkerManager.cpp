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
	//	cout << "文件为空!" << endl;
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

//显示职工
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->ShowInfo();
		}
	}

}

//职工是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件夹为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int id = 0;
		cout << "输入要删除的职工编号:" << endl;
		cin >> id;

		int temp = this->IsExist(id);

		if (temp != -1)//职工存在
		{
			for (int i = temp; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}

//修改职工信息
void WorkerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件夹为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int id = 0;
		cout << "输入要修改的职工编号:" << endl;
		cin >> id;

		int temp = this->IsExist(id);

		if (temp != -1)//职工存在
		{
			delete this->m_EmpArray[temp];
			cout << "查询到编号为 " << id << " 的职工" << "请输入新编号" << endl;
			int newId = 0;
			cin >> newId;
			cout << "请输入修改的职工姓名" << endl;
			string newName = "";
			cin >> newName;
			cout << "请选择新职工的岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cout << "请输入:" << endl;
			int newdId = 0;
			cin >> newdId;
			
			this->m_EmpArray[this->m_EmpNum+1]->m_Id = newId;
			this->m_EmpArray[this->m_EmpNum+1]->m_Name = newName;
			this->m_EmpArray[this->m_EmpNum+1]->m_DeptId = newdId;
			
			cout << "修改成功" << endl;

			//数据同步更新到文件中
			this->save();

		}
		else
		{
			cout << "未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件夹为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int choice = 0;
		cout << "1.按编号查找  2.按姓名查找" << endl;
		cin >> choice;
		if (choice == 1)
		{
			int id = 0;
			cout << "请输入职工编号:";
			cin >> id;
			
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Id == id) {
					this->m_EmpArray[i]->ShowInfo();
				}
			}
		}
		else if(choice == 2)
		{
			string name = "";
			cout << "请输入职工姓名:";
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if(this->m_EmpArray[i]->m_Name == name) 
				{
					this->m_EmpArray[i]->ShowInfo();
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}

	}
	system("pause");
	system("cls");
}

//排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		}

		cout << "排序成功" << endl;
		this->save();
		this->Show_Emp();
	}
}

//保存至文件
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

//统计文件中的人数
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

//初始化文件中的员工
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

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确定清空?" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "删除成功" << endl;
	}

	system("pause");
	system("cls");

}


WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
