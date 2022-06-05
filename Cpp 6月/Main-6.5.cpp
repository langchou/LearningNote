#include <iostream>
#include <string>
using namespace std;

#include "Person.hpp"

template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2>p)
{
	cout << "���� ������" << p.name << " ���䣺" << p.age << endl;
}


template<class T1, class T2>
class Person
{
	//ȫ�ֺ�������ʵ�� ��Ԫ
	friend void printPerson(Person<T1, T2>p)
	{
		cout << "������" << p.name << " ���䣺" << p.age << endl;
	}

	//ȫ�ֺ�������ʵ��
	//��һ����ģ������б�
	friend void printPerson2<>(Person<T1, T2>p);


public:
	Person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}

private:
	T1 name;
	T2 age;
};




void test1()
{
	Person<string, int>p("Tom", 11);
	printPerson(p);
}

void test2()
{
	Person<string, int>p("jack", 22);
	printPerson2(p);
}

int main()
{
	test1();
	test2();
}