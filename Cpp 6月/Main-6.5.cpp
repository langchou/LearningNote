#include <iostream>
#include <string>
using namespace std;

#include "Person.hpp"

template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2>p)
{
	cout << "类外 姓名：" << p.name << " 年龄：" << p.age << endl;
}


template<class T1, class T2>
class Person
{
	//全局函数类内实现 友元
	friend void printPerson(Person<T1, T2>p)
	{
		cout << "姓名：" << p.name << " 年龄：" << p.age << endl;
	}

	//全局函数类外实现
	//加一个空模板参数列表
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