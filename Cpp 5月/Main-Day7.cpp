#include <iostream>
#include <string>
using namespace std;

//构造函数调用规则  深拷贝\浅拷贝

//class Person
//{
//
//
//public:
//	Person()
//	{
//		cout << "无参构造函数" << endl;
//	}
//
//	Person(int a)
//	{
//		age = a;
//		cout << "有参构造函数" << endl;
//	}
//	Person(const Person& p)
//	{
//		age = p.age;
//		cout << "拷贝构造函数" << endl;
//	}
//
//	//内存释放前调用
//	~Person()
//	{
//		cout << "析构构造函数" << endl;
//	}
//
//	int age;
//};

//void test()
//{
//	Person p;
//}
//
//void test1()
//{
//	//括号法
//	//Person p1; //默认构造函数调用
//	//Person p2(10); //有参构造
//	//Person p3(p2); //拷贝构造
//
//
//	//显示法
//	Person p1;
//	Person p2 = Person(10); //有参构造
//	Person p3 = Person(p3); //拷贝构造
//
//	Person(10); //匿名对象 前行结束，系统会立即回收匿名对象
//
//	//隐式转换法
//	Person p4 = 10; //相当于Person p4 = Person(10)
//
//} 

//值传递的方式给函数 
//void dowork(Person p)
//{
//	
//}

//void test2()
//{
//	Person p; //无参构造
//	doword(p);
//
//}

//值方式返回局部对象
//Person dowork2()
//{
//	Person p1;
//	cout << (int*)&p1 << endl;
//	return p1;
//}
//
//void test3()
//{
//	Person p = dowork2();
//	cout << (int*)&p << endl;
//
//}

//调用规则

//int main()
//{
//	//	test();
//	//	test1();
//	test3();
//	system("pause");
//	return 0;
//}
// 
//调用规则
//class Person
//{
//
//public:
//
//	Person()
//	{
//
//		cout << "默认构造函数" << endl;
//	}
//
//	Person(int age)
//	{
//		cout << "有参构造函数" << endl;
//		m_age = age;
//	}
//
//	Person(const Person& p)
//	{
//		cout << "拷贝构造函数" << endl;
//		m_age = p.m_age;
//	}
//
//	~Person()
//	{
//		cout << "析构函数" << endl;
//	}
//
//
//	int m_age;
//};
//
//
//
//void test01()
//{
//	Person p;
//	p.m_age = 18;
//	Person p2(p);
//	cout << "p2年龄：" << p2.m_age << endl;
//
//}
//
//
//void test02()
//{
//	Person p(28);
//	Person p2(p);
////	p.m_age = 18;
//	cout << "p2年龄：" << p2.m_age << endl;
//
//}
//
//
//int main()
//{
////	test01();
//	test02();
//	system("pause");
//	return 0;
//}

//深拷贝，浅拷贝

//class Person
//{
//public:
//	Person()
//	{
//		cout << "默认构造函数" << endl;
//	}
//
//	Person(int age,int height)
//	{
//		cout << "有参构造函数" << endl;
//		m_age = age;
//		m_height = new int(height);
//	}
//
//	Person(const Person& p)
//	{
//		cout << "拷贝构造函数" << endl;
//		m_age = p.m_age;
//	//	m_height = p.m_height; //编译器默认拷贝构造函数
//		m_height = new int(*p.m_height);
//
//	}
//
//	~Person()
//	{
//		//释放堆区内存
//		if (m_height != NULL)
//		{
//			delete m_height;
//			m_height = NULL;
//		}
//		cout << "析构函数" << endl;
//	}
//
//
//	int m_age;
//	int *m_height;
//};
//
//
//void test01()
//{
//	Person p1(18,160);
//	cout << "p1年龄为" << p1.m_age << "p1的身高为: " << *p1.m_height << endl;
//
//	Person p2(p1);
//	cout << "p2年龄为" << p2.m_age << "p2的身高为: " << *p2.m_height << endl;
//
//
//}
//
//
//int main()
//{
//	test01();
//	
//	system("pause");
//	return 0;
//}


//初始化列表

//class Person
//{
//public:
//	//传统初始化操作
//	//Person(int a, int b, int c)
//	//{
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//}
//
//	//初始化列表
//	Person(int a, int b, int c):m_A(a), m_B(b), m_C(c)
//	{
//
//	}
//
//
//	int m_A;
//	int m_B;
//	int m_C;
//};
//
//
//void test01()
//{
//	Person p(10, 20, 30);
////	Person p;
//	cout << "m_A = " << p.m_A << endl;
//	cout << "m_B = " << p.m_B << endl;
//	cout << "m_C = " << p.m_C << endl;
//}
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}


//class Phone
//{
//
//public:
//
//	Phone(string pname)
//	{
//		p_name = pname;
//		cout << "Phone基本构造" << endl;
//	}
//
//	~Phone()
//	{
//		cout << "Phone析构" << endl;
//	}
//
//	string p_name;
//};
//
//
//class Person
//{
//
//public:
//
//	Person(string name,string pname):m_name(name),m_phone(pname)
//	{
//		cout << "Person基本构造" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person析构" << endl;
//	}
//
//	string m_name;
//	Phone m_phone;
//};
//
//
//void test()
//{
//	Person p("张三", "iphone13");
//
//	cout << p.m_name << "拿着" << p.m_phone.p_name << endl;
//}

//int main()
//{
//
//	test();
//	system("pause");
//	return 0;
//}


//静态成员变量

class Person
{
public:
	
	//所有对象共享同一份数据
	//编译阶段分配内存
	//类内声明,类外初始化

	static int m_A;

private:
	static int m_B;

};

int Person::m_A = 10;
int Person::m_B = 200;


void test()
{
	Person p1;
	cout << p1.m_A << endl;
//	cout << p1.m_B << endl; //无法访问private中的成员

	Person p2;
	p2.m_A = 100;
	cout << p1.m_A << endl;
}


int main()
{
	test();
	
	system("pause");
	return 0;
}