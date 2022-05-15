#include <iostream>
using namespace std;

//构造函数 析构函数

class Person
{


public:
	Person()
	{
		cout << "构造函数的调用"<<"无参" << endl;
	}

	Person(int a)
	{
		age = a;
		cout << "构造函数的调用" << "有参" << endl;
	}
	Person(const Person& p)
	{
		age = p.age;
	}
	~Person()
	{
		cout << "析构函数的调用" << endl;
	}

	int age;
};

void test()
{
	Person p;
}

void test1()
{
	//括号法
	//Person p1; //默认构造函数调用
	//Person p2(10); //有参构造
	//Person p3(p2); //拷贝构造


	//显示法
	Person p1;
	Person p2 = Person(10); //有参构造
	Person p3 = Person(p3); //拷贝构造

	Person(10); //匿名对象 前行结束，系统会立即回收匿名对象

	//隐式转换法
	Person p4 = 10; //相当于Person p4 = Person(10)

} 

void dowork(Person p)
{
	
}


void test2()
{
	Person p;
	doword(p);

}

int main()
{
//	test();
//	test1();

	system("pause");
	return 0;
}