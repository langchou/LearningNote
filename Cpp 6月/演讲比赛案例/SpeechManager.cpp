#include "SpeechManager.h"

//����
SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initSpeaker();
	//����ѡ��
	this->creatSpeaker();
	//��ȡ�����¼
	this->loadRecord();
}
//չʾ�˵�
void SpeechManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//��ʼ��
void SpeechManager::initSpeaker()
{
	//�����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//����������ʼ��
	this->index = 1;
	//��¼�������
	this->m_Record.clear();
}
//����ѡ��
void SpeechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		
		Speaker sp;
		sp.name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
//��ǩ
void SpeechManager::speechDraw()
{
	cout << "---------------------------" << endl;
	cout << "��" << this->index << "�ֳ�ǩ����:" << endl;
	if (this->index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
	system("pause");
	system("cls");
}
//����
void SpeechManager::speechContest()
{
	cout << "---------------------------" << endl;
	cout << "��" << this->index << "�ֱ�����ʼ" << endl;
	cout << "---------------------------" << endl;

	int num = 0; //��¼��Ա����6��Ϊ1��
	multimap<double, int, greater<int>> groupScore; //��ʱ����������key���� value ѡ�ֱ�� �������� ��������ȡǰ����

	vector<int>v_src;
	if (this->index == 1)
	{
		v_src = this->v1;
	}
	else
	{
		v_src = this->v2;
	}
	
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		num++;
		deque<double>s;//��¼��ί��ֵ�����
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 601 + 400) / 10.f;
			//cout << score << " ";
			s.push_back(score);
		}
		sort(s.begin(), s.end()); 
		s.pop_back();
		s.pop_front();
		double sum = accumulate(s.begin(), s.end(), 0); //��¼�ܷ�
		double avg = sum / (double)s.size(); //��¼ƽ����
		//cout << sum << endl;
		//cout << avg << endl;
		this->m_Speaker[*it].score[this->index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));

		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��ı����������£�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << this->m_Speaker[it->second].name << " �ɼ���" << this->m_Speaker[it->second].score[this->index-1] << endl;
			}

			int count = 0;

			//ȡǰ��
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count <3; it++,count++)
			{
				if (this->index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v3.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "---------------------------" << endl;
	cout << "��" << this->index << "�ֱ�������" << endl;
	system("pause");
	system("cls");
}
//չʾ�ɼ�
void SpeechManager::showScore()
{
	cout << "��" << index << "�ֽ���ѡ�����£�" << endl;
	cout << "---------------------------" << endl;
	vector<int> v;
	if (this->index == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->v3;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "��ţ�" << *it << " ������" << this->m_Speaker[*it].name << " �ɼ���" << this->m_Speaker[*it].score[index - 1] << endl;
	}
	cout << "---------------------------" << endl;
	system("pause");
	system("cls");
}
//����ɼ�
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�ѱ���" << endl;
	system("pause");
	system("cls");
}
//��ȡ����ɼ�
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	//�ļ��򲻿�
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	//�ļ�Ϊ��
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;

	ifs.putback(ch);

	string data;
	int index = 0;

	while (ifs>>data)
	{
	//	cout << data << endl;
	
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start); //��0��ʼ���� ','
			if (pos == -1)
			{
				break; //�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			//cout << tmp << endl;
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}	
//�鿴�����¼
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ����ļ������ڣ�" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "�� " <<
			"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
			"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
			"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}
//��ռ�¼
void SpeechManager::clearRecord()
{
	cout << "ȷ����������¼?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int choice = -1;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeaker();

		this->creatSpeaker();

		this->loadRecord();
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//��������
void SpeechManager::startGame()
{
	//��һ��
	//��ǩ
	this->speechDraw();
	//����
	this->speechContest();
	//��ʾ��һ�ֱ����ɼ�
	this->showScore();
	//�ڶ��ֱ���
	this->index++;
	//��ǩ
	this->speechDraw();
	//����
	this->speechContest();
	//��ʾ�ڶ��ֱ����ɼ�
	this->showScore();
	//����ɼ�
	this->saveRecord();
	//��ʼ������
	this->initSpeaker();
	//������ѡ��
	this->creatSpeaker();
	//��ȡ����ɼ�
	this->loadRecord();
}

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{

}