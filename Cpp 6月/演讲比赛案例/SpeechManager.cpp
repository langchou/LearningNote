#include "SpeechManager.h"

//构造
SpeechManager::SpeechManager()
{
	//初始化容器
	this->initSpeaker();
	//创建选手
	this->creatSpeaker();
	//获取往届记录
	this->loadRecord();
}
//展示菜单
void SpeechManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
//初始化
void SpeechManager::initSpeaker()
{
	//容器置空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//比赛轮数初始化
	this->index = 1;
	//记录容器清空
	this->m_Record.clear();
}
//创建选手
void SpeechManager::creatSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
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
//抽签
void SpeechManager::speechDraw()
{
	cout << "---------------------------" << endl;
	cout << "第" << this->index << "轮抽签如下:" << endl;
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
//比赛
void SpeechManager::speechContest()
{
	cout << "---------------------------" << endl;
	cout << "第" << this->index << "轮比赛开始" << endl;
	cout << "---------------------------" << endl;

	int num = 0; //记录人员数，6个为1组
	multimap<double, int, greater<int>> groupScore; //临时容器，保存key分数 value 选手编号 降序排列 更方便提取前三名

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
		deque<double>s;//记录评委打分的容器
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 601 + 400) / 10.f;
			//cout << score << " ";
			s.push_back(score);
		}
		sort(s.begin(), s.end()); 
		s.pop_back();
		s.pop_front();
		double sum = accumulate(s.begin(), s.end(), 0); //记录总分
		double avg = sum / (double)s.size(); //记录平均分
		//cout << sum << endl;
		//cout << avg << endl;
		this->m_Speaker[*it].score[this->index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组的比赛名次如下：" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << this->m_Speaker[it->second].name << " 成绩：" << this->m_Speaker[it->second].score[this->index-1] << endl;
			}

			int count = 0;

			//取前三
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
	cout << "第" << this->index << "轮比赛结束" << endl;
	system("pause");
	system("cls");
}
//展示成绩
void SpeechManager::showScore()
{
	cout << "第" << index << "轮晋级选手如下：" << endl;
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
		cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].name << " 成绩：" << this->m_Speaker[*it].score[index - 1] << endl;
	}
	cout << "---------------------------" << endl;
	system("pause");
	system("cls");
}
//保存成绩
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
	cout << "记录已保存" << endl;
	system("pause");
	system("cls");
}
//读取往届成绩
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	//文件打不开
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	//文件为空
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
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
			pos = data.find(",", start); //从0开始查找 ','
			if (pos == -1)
			{
				break; //找不到break返回
			}
			string tmp = data.substr(start, pos - start); //找到了,进行分割 参数1 起始位置，参数2 截取长度
			//cout << tmp << endl;
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}	
//查看往届记录
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或者文件不存在！" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届 " <<
			"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
			"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
			"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}
//清空记录
void SpeechManager::clearRecord()
{
	cout << "确认清楚往届记录?" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int choice = -1;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		this->initSpeaker();

		this->creatSpeaker();

		this->loadRecord();
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

//比赛控制
void SpeechManager::startGame()
{
	//第一轮
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示第一轮比赛成绩
	this->showScore();
	//第二轮比赛
	this->index++;
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示第二轮比赛成绩
	this->showScore();
	//保存成绩
	this->saveRecord();
	//初始化容器
	this->initSpeaker();
	//创建新选手
	this->creatSpeaker();
	//读取往届成绩
	this->loadRecord();
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{

}