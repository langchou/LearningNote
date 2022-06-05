#pragma once
#include <iostream>
using namespace std;

#include<string>

template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	//{
	//	this->age = age;
	//	this->name = name;
	//}
	void showPerson();


	T1 name;
	T2 age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->age = age;
	this->name = name;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "ÄêÁä£º" << this->age << " Ãû×Ö£º" << this->name << endl;
}