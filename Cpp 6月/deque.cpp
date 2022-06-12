#include <iostream>
#include <string>
#include <deque>

using namespace std;

//deque 构造函数

void printDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}


void test01()
{
	deque<int>d	;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printDeque(d);

	deque<int>d2(d);
	printDeque(d2);


	deque<int>d3(10,100);
	printDeque(d3);

	deque<int>d4(d3.begin(), d3.end());
	printDeque(d4);

	if (d4.empty())
	{
		cout << "d4为空" << endl;
	}
	else
	{
		cout << "d4不为空" << endl;
	}

}

void test02()
{
	deque<int>v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	//头插
	v1.push_front(20);
	v1.push_front(30);
	v1.push_front(55);
	//尾删
	v1.pop_back();
	//头删
	v1.pop_front();
	printDeque(v1);

}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}