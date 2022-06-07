#include <iostream>
#include <vector>
#include <algorithm> //STL提供的标准算法
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
	Person p1("张三", 10);
	Person p2("李四", 12);
	Person p3("王五", 14);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for (vector<Person>::iterator it=v.begin(); it < v.end(); it++)
	{
		cout << "名字：" << it->name << " 年龄：" << it->age << endl;
	}
}

void test3()
{
	vector<Person *>v;
	Person p1("张三", 10);
	Person p2("李四", 12);
	Person p3("王五", 14);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	for (vector<Person *>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << "名字：" << (*it)->name << " 年龄：" << (*it)->age << endl;
	}
}
 

void test1()
{
	//创建vector容器	
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	
	//第一种遍历方式
	vector<int>::iterator itbegin = v.begin();
	vector<int>::iterator itend = v.end();
	while (itbegin != itend)
	{
		cout << *itbegin << endl;
		itbegin++;
	}
	

	//第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << endl;
	}

	//第三种遍历方式 STL提供的遍历算法
	for_each(v.begin(), v.end(), myPrint);
}

int main()
{
	//test();
	test3();
	system("pause");
	return 0;
}