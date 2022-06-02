#include "WorkerManager.h"


WorkerManager::WorkerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ��ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//�ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
	//	cout << "�ļ�Ϊ��!" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ��ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	
	//�ļ����� ��¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ:" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ�����:" << this->m_EmpArray[i]->m_Id
	//		<< "����:" << this->m_EmpArray[i]->m_Name
	//		<< "���ű��:" << this->m_EmpArray[i]->m_DeptId
	//		<< endl;
	//}
}

//�˵�
void WorkerManager::ShowMenu()
{
	cout << "********************************" << endl;
	cout << "******��ӭʹ��ְ������ϵͳ******" << endl;
	cout << "******   0.�˳�����ϵͳ   ******" << endl;
	cout << "******   1.����ְ����Ϣ   ******" << endl;
	cout << "******   2.��ʾְ����Ϣ   ******" << endl;
	cout << "******   3.ɾ��ְ����Ϣ   ******" << endl;
	cout << "******   4.�޸�ְ����Ϣ   ******" << endl;
	cout << "******   5.����ְ����Ϣ   ******" << endl;
	cout << "******   6.���ձ������   ******" << endl;
	cout << "******   7.��������ĵ�   ******" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

//�˳�
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ������:" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;

	if (addNum > 0)
	{
		//ִ�о������
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i<this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ������
			string name;//ְ�����
			int dSelect;//����ѡ��

			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ"<< endl;
			cout << "1.��ְͨ��"<< endl;
			cout << "2.����"<< endl;
			cout << "3.�ϰ�"<< endl;
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

			//��������ְ��ָ�뱣�浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//����ְ���� ��Ϊ�ձ�־
		this->m_FileIsEmpty = false;
		//��ʾ
		cout << "�ɹ����" << addNum <<"����ְ��" << endl;

		//�������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}

	//��������� �����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
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

//ְ���Ƿ����
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

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int id = 0;
		cout << "����Ҫɾ����ְ�����:" << endl;
		cin >> id;

		int temp = this->IsExist(id);

		if (temp != -1)//ְ������
		{
			for (int i = temp; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "δ�ҵ���ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

//�޸�ְ����Ϣ
void WorkerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int id = 0;
		cout << "����Ҫ�޸ĵ�ְ�����:" << endl;
		cin >> id;

		int temp = this->IsExist(id);

		if (temp != -1)//ְ������
		{
			delete this->m_EmpArray[temp];
			cout << "��ѯ�����Ϊ " << id << " ��ְ��" << "�������±��" << endl;
			int newId = 0;
			cin >> newId;
			cout << "�������޸ĵ�ְ������" << endl;
			string newName = "";
			cin >> newName;
			cout << "��ѡ����ְ���ĸ�λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cout << "������:" << endl;
			int newdId = 0;
			cin >> newdId;
			
			this->m_EmpArray[this->m_EmpNum+1]->m_Id = newId;
			this->m_EmpArray[this->m_EmpNum+1]->m_Name = newName;
			this->m_EmpArray[this->m_EmpNum+1]->m_DeptId = newdId;
			
			cout << "�޸ĳɹ�" << endl;

			//����ͬ�����µ��ļ���
			this->save();

		}
		else
		{
			cout << "δ�ҵ���ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ���Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int choice = 0;
		cout << "1.����Ų���  2.����������" << endl;
		cin >> choice;
		if (choice == 1)
		{
			int id = 0;
			cout << "������ְ�����:";
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
			cout << "������ְ������:";
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
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}

	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //����
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

		cout << "����ɹ�" << endl;
		this->save();
		this->Show_Emp();
	}
}

//�������ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //������ķ�ʽ���ļ� -д�ļ�

	//��ÿ���˵�����д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//ͳ���ļ��е�����
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
		//��¼����
		num++;
	}
	ifs.close();

	return num;
}

//��ʼ���ļ��е�Ա��
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

		if (dId == 1)//��ͨԱ��
		{
			worker = new Emplyee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ�����?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
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

		cout << "ɾ���ɹ�" << endl;
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
