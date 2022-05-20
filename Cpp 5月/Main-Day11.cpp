#include <iostream>

using namespace std;

//class Base
//{
//public:
//	void head()
//	{
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//	}
//};
////继承
//class java :public Base
//{
//public:
//	void content()
//	{
//		cout << "java" << endl;
//	}
//};
//class python :public Base
//{
//public:
//	void content()
//	{
//		cout << "python" << endl;
//	}
//};

//void test()
//{
//	java p1;
//	p1.head();
//	p1.content();
//	python p2;
//	p2.head();
//	p2.content();
//
//}

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	void func()
	{
		m_A = 10; //父类的公共权限到子类中还是公共权限
		m_B = 10; //父类的保护权限到子类中还是保护权限
	//	m_C = 10; //父类的私有权限 子类无法访问
	}
};


class Son2 :protected Base
{
public:
	void func()
	{
		m_A = 10; //父类中的公共权限 到子类中变为保护权限
		m_B = 10; //父类中的保护权限 到子类中变为保护权限
		m_C = 10; //父类中的私有成员 子类无法访问
	}
};


class Son3 :private Base
{
public:
	void func()
	{
		m_A = 10; //父类中的公共权限 到子类中变为私有权限
		m_B = 10; //父类中的保护权限 到子类中变为私有权限
		m_C = 10; //父类中的私有成员 子类无法访问
	}
};
void test01()
{
	Son s1;
	Son2 s2;
	Son3 s3;
//	s2.m_A = 1000; //Son2中 m_A变为保护权限，类外无法访问
//	s3.m_A = 1000; //Son3中 m_A变为私有权限，类外无法访问
	s1.m_A = 10; //公共权限类内类外都可以访问
}

int main()
{
//	test();
	Son p1;
	p1.func();
	system("pause");
	return 0;
}