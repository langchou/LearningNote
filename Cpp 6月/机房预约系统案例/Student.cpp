#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->Id = id;
	this->name = name;
	this->pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom c;
	while (ifs >> c.comId && ifs >> c.comMaxSize)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

void Student::operMenu()
{
	cout << "��ӭѧ������" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "�����������������룺";
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >>	interval;
		if (interval >= 1 && interval <=2)
		{
			break;
		}
		cout << "�����������������룺";
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].comMaxSize << endl;
	cout << "2�Ż���������" << vCom[1].comMaxSize << endl;
	cout << "3�Ż���������" << vCom[2].comMaxSize << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "�����������������룺";
	}
	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->Id << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
}

void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->Id)
		{
			cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	int index = 1;
	vector<int>v;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["roomId"];
			}
			string status = "״̬��";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			cout << status << endl;
		}
	}
	cout << "������ȡ���ļ�¼,0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else 
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ�ɹ�" << endl;
				break;
			}	
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}
