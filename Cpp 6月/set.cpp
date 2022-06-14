#include <iostream>
#include <set>

using namespace std;

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test()
{
	set<int>s;
	s.insert(50);
	s.insert(20);
	s.insert(30);
	s.insert(4);
	cout << "交换前：" << endl;
	set<int>s2;

	s2.insert(400);
	s2.insert(500);
	s2.insert(600);
	s2.insert(700);
	printSet(s);
	printSet(s2);

	cout << "交换后：" << endl;

	s.swap(s2);
	printSet(s);
	printSet(s2);
}

int main()
{
	test();
	system("pause");
	return 0;
}