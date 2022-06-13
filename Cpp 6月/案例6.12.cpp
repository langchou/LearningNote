#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>


using namespace std;

//有五名选手，分别为ABCDE，10位评委分别对每一名选手打分，去除最高分和最低分，取平均分

class Person
{
public:
	Person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	string name;
	int score;
};

void createPerson(vector<Person>& v)
{
	for (int i = 0; i < 5; i++)
	{
		string nameseed = "ABCDE";
		string name = "选手";
		name +=  nameseed[i];

		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		
		//cout << "姓名：" << it->name << " 打分：" << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;
		sort(d.begin(), d.end());//排序
		d.pop_back(); //去最低分
		d.pop_front(); //去最高分

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		//平均分赋值
		it->score = avg;
	}
}
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "名字：" << it->name << " 成绩：" << it->score << endl;
	}

}

int main()
{
	srand((unsigned int)time(NULL));

	//创建五名选手
	vector<Person>v;
	createPerson(v);

	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "名字：" << it->name << " 成绩：" << it->score << endl;
	//}

	//评委打分
	setScore(v);
	showScore(v);

	system("pause");
	return 0;
}