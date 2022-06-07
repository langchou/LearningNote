#include <iostream>
#include <vector>
#include <algorithm> //STL�ṩ�ı�׼�㷨
#include <string>


using namespace std;


void myPrint(int val)
{
	cout << val << endl;
}

class Person
{
public:
	Person(string name ,int age)
	{
		this->age = age;
		this->name = name;
	}
public:
	int age;
	string	name;
};

void test2()
{
	vector<Person>v;
	Person p1("����", 10);
	Person p2("����", 12);
	Person p3("����", 14);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for (vector<Person>::iterator it=v.begin(); it < v.end(); it++)
	{
		cout << "���֣�" << it->name << " ���䣺" << it->age << endl;
	}
}

void test3()
{
	vector<Person *>v;
	Person p1("����", 10);
	Person p2("����", 12);
	Person p3("����", 14);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	for (vector<Person *>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << "���֣�" << (*it)->name << " ���䣺" << (*it)->age << endl;
	}
}
 

void test1()
{
	//����vector����	
	vector<int> v;

	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	
	//��һ�ֱ�����ʽ
	vector<int>::iterator itbegin = v.begin();
	vector<int>::iterator itend = v.end();
	while (itbegin != itend)
	{
		cout << *itbegin << endl;
		itbegin++;
	}
	

	//�ڶ��ֱ�����ʽ
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << endl;
	}

	//�����ֱ�����ʽ STL�ṩ�ı����㷨
	for_each(v.begin(), v.end(), myPrint);
}

int main()
{
	//test();
	test3();
	system("pause");
	return 0;
}