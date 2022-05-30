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
		cout << "�ļ�Ϊ��!" << endl;
	}
	//��ʼ������
	this->m_EmpNum = 0;
	//��ʼ��ָ��
	this->m_EmpArray = NULL;
	//��ʼ���ļ��Ƿ�Ϊ��
	this->m_FileIsEmpty = true;
	ifs.close();
	return;
	
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

//�����ļ�
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




//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ������" << endl;
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
		m_EmpNum = newSize;
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


WorkerManager::~WorkerManager()
{

}
