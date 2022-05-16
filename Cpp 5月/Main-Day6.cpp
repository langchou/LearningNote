#include <iostream>
using namespace std;

//构造函数 析构函数

class Person
{


public:
	Person()
	{
		cout << "无参构造函数" << endl;
	}

	Person(int a)
	{
		age = a;
		cout << "有参构造函数"<< endl;
	}
	Person(const Person& p)
	{
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}

	//内存释放前调用
	~Person() 
	{
		cout << "析构构造函数" << endl;
	}

	int age;
}; 

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
Person dowork2()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test3()
{
	Person p = dowork2();
	cout << (int*)&p << endl;

}


int main()
{
//	test();
//	test1();
	test3();
	system("pause");
	return 0;
}