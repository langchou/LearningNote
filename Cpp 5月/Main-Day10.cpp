#include <iostream>

using namespace std;

//关系运算符重载,仿函数

//class Person
//{
//
//
//
//public:
//
//	Person(int age)
//	{
//		//创建在堆区
//		m_Age = new int(age);
//	}
//
//	//析构易造成堆区内存重复释放 改深拷贝
//	~Person()
//	{
//
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//
//	//重载赋值运算符 =
//	Person& operator=(Person &p)
//	{
//
//		//调用的时候 p2已经被赋20 即创建了一个堆区内存 要先判断并释放堆区内存后才能再深拷贝
//		if (m_Age != NULL)
//		{
//			delete m_Age;   
//			m_Age = NULL;
//		}
//		//深拷贝
//		m_Age = new int(*p.m_Age);
//
//		//链式编程
//		return *this;
//	}
//
//
//
//	int* m_Age;
//	
//};

//void test01()
//{
//	Person  p1(22);
//	Person  p2(20);
//	Person  p3(30);
//	Person p4(40);
//	p4 =p3 = p2 = p1;
//
//	cout << "p1的年龄为" << *p1.m_Age << endl;
//
//	cout << "p2的年龄为" << *p2.m_Age << endl;
//
//	cout <<"p3的年龄为" <<*p3.m_Age << endl;
//	cout <<"p4的年龄为" <<*p4.m_Age << endl;
//}



class Person
{

public:
	Person(){}

	Person(string name, int age)
	{
		mName = name;
		mAge = age;
	}

	bool operator==(Person &p)
	{
		if (mName == p.mName && mAge == p.mAge)
		{
			return true;
		}
		return false;
	}

	bool operator!=(Person& p)
	{
		if (mName == p.mName && mAge == p.mAge)
		{
			return false;
		}
		return true;
	}


	string mName;
	int mAge;

};


class MyPrint
{

public:
	//仿函数
	void operator()(string test)
	{
		cout << test << endl;
	}

};


class MyAdd
{

public:
	int operator()(int num1,int num2)
	{
		return num1 + num2;
	}
};

void test02()
{
	MyPrint myprint; 
	myprint("hello world");//类似函数调用，称为仿函数
	MyAdd myadd;
	int ret = myadd(100, 202);
	cout << ret << endl;

	//匿名函数对象
	cout << MyAdd()(100, 203) << endl;
}

	
{
	Person p1("张三", 18);

	Person p2("123", 18);

	if (p1 == p2)
	{
		cout << "p1p2相等" << endl;
	}
	else
	{
		cout << "p1p2不相等" << endl;
	}


	if (p1 != p2)
	{
		cout << "p1p2不相等" << endl;
	}
	else
	{
		cout << "p1p2相等" << endl;
	}
}



int main()
{
//	test01();
	//int a = 10;
	//int b = 20;
	//int c = 30;
	//c = b = a;
	//cout << c << b << a << endl;


//	test01();
	test02();
	system("pause");
	return 0;
}