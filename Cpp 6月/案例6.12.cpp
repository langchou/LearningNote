#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>


using namespace std;

//������ѡ�֣��ֱ�ΪABCDE��10λ��ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣�ȡƽ����

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
		string name = "ѡ��";
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
		
		//cout << "������" << it->name << " ��֣�" << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;
		sort(d.begin(), d.end());//����
		d.pop_back(); //ȥ��ͷ�
		d.pop_front(); //ȥ��߷�

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		//ƽ���ָ�ֵ
		it->score = avg;
	}
}
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "���֣�" << it->name << " �ɼ���" << it->score << endl;
	}

}

int main()
{
	srand((unsigned int)time(NULL));

	//��������ѡ��
	vector<Person>v;
	createPerson(v);

	//����
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "���֣�" << it->name << " �ɼ���" << it->score << endl;
	//}

	//��ί���
	setScore(v);
	showScore(v);

	system("pause");
	return 0;
}