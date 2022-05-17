#include <iostream>

using namespace std;

//class Person
//{
//public:
//
//	//Person(int a, int b) :m_A(a), m_B(b)
//	//{
//
//	//}
//
//	static int m_A;
//	//int m_B;
//
//};
//
//int Person::m_A = 100;
////int Person::m_B = 200;
//
//void test1()
//{
//
//	Person p1;
//	cout << p1.m_A << endl;
//	//Person p2;
//	//cout << p2.m_A << endl;
//
//}
//
//int main()
//{
//
//	test1();
//
//	system("pause");
//	return 0;
//}


class Person
{


public:
	//静态成员函数
	static void func()
	{
		m_A = 100; // 静态成员函数可以访问静态成员变量
		cout << "func调用" << endl;
		cout << "m_A = " << m_A << endl;

	}

	//静态成员变量 类内创建 类外初始化
	static int m_A;


	//静态成员函数也有访问权限
private: 
	static void func2()
	{
		cout << "func2调用" << endl;
	}
};

int Person::m_A = 10;

void test01()
{
	//通过对象访问
	Person p;
	p.func();
//	p.func2();

	//通过类名访问
	Person::func();
	Person::m_A;
}


//成员变量和成员函数分开存储


class Person2
{
	//非静态属于类的对象上
	int p_a;
	//静态成员变量不属于类的对象上
	static int p_b;

	void func(){} //非静态成员函数和静态成员函数都不属于类的对象上

	static void func2(){}
};

int Person2::p_b = 10;


void test02()
{
	Person2 p;


	cout << "size of p =" << sizeof(p) << endl;
}

int main()
{

//	test01();
	test02(); 
	system("pause");
	return 0;
}