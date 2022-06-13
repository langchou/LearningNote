#include <iostream>
#include <cstring>
#include <stack> //后进先出
#include <queue> //先进先出
#include <algorithm>
#include <list>

using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};

void test1()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}

void test2()
{
	queue<Person>s;
	Person p1("张三", 10);
	Person p2("李四", 20);
	Person p3("王五", 30);
	Person p4("赵六", 40);

	s.push(p1);
	s.push(p2);
	s.push(p3);
	s.push(p4);
	cout << "大小：" << s.size() << endl;

	while (!s.empty())
	{
		//队头
		cout << "队头---姓名：" << s.front().name << "年龄：" << s.front().age << endl;
		//队尾
		cout << "队尾---姓名：" << s.back().name << "年龄：" << s.back().age << endl;
		s.pop();
	}
	cout << "大小：" << s.size() << endl;

}

void printList(const list<int>&L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test3()
{
	list<int>L1;
	for (int i = 0; i < 10; i++)
	{
		L1.push_back(i);
	}
	
	printList(L1);

	list<int>L2;
	L2 = L1;//operator= 赋值
	printList(L2);

	list<int>L3(L2);//拷贝构造
	printList(L3);

	list<int>L4;
	L4.assign(L3.begin(), L3.end());
	printList(L4);

	list<int>L5;
	L5.assign(10,100);
	printList(L5);
}

void test4()
{
	list<int>List1;
	List1.push_back(10);
	List1.push_back(20);
	List1.push_back(30);
	List1.push_back(40);
	List1.push_back(50);
	printList(List1);

	List1.push_front(100);
	printList(List1);

	List1.insert(List1.begin(), 40);
	printList(List1);

	list<int>::iterator it = List1.begin();
	List1.insert(++it, 30);
	printList(List1);

	List1.push_back(1000);
	List1.push_back(1000);
	List1.push_back(1000);
	List1.push_back(1000);
	printList(List1);

	List1.remove(1000);
	printList(List1);
}

void test5()
{
	list<int>List1;
	List1.push_back(30);
	List1.push_back(40);
	List1.push_back(10);
	List1.push_back(20);
	List1.push_back(50);
	cout << "反转前：" << endl;
	printList(List1);


	List1.reverse();
	cout << "反转后：" << endl;
	printList(List1);
}

bool mycompear(int a, int b)
{
	return a > b;
}

void test6()
{
	list<int>List1;
	List1.push_back(30);
	List1.push_back(40);
	List1.push_back(10);
	List1.push_back(20);
	List1.push_back(50);
	cout << "排序前：" << endl;
	printList(List1);

	cout << "排序后：（升序）" << endl;
	List1.sort();
	printList(List1);

	cout << "排序后：（降序）" << endl;
	List1.sort(mycompear);
	printList(List1);

}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();

	system("pause");
	return 0;
}


//前端题
//class B
//{
//char n[10];  a
//static int c; //c==0
//public:
//	B(char* p)
//	{
//		strcpy(n, p);
//		++c; 1
//	}
//
//	~B()
//	{
//		--c;
//		cout << c << " ";
//	}
//	void show()
//	{
//		cout << n << " " << c << " ";
//	}
//};
//int B::c = 0;
//
//int main()
//{                                                    
//	B b[3] = { 'a','b','c' };
//	int i;
//	for (i = 0; i < 3; i++)
//		b[i].show();
//	return 0;
//}


