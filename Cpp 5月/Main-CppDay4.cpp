#include <iostream>
using namespace std;


int* func()
{
	int* p = new int(10);
	return p;
}


void test1()
{
	//	int* p = func();
}

void test2()
{

	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;

}
//引用传参中 更改形参也可以改变实参
void swap01(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void test03(int& ref)
{
	ref = 100;
}
//int main()
//{	
//
////	int* p = func();
////	test2();
//	//引用传参
//	int a = 10;
//	int b = 20;
//	swap01(a, b);
////	int& b = a;
//	cout << a << endl;
//	cout << b << endl;
//
//	system("pause");
//	return 0;
//}

int main()
{
	int a = 50;
	int c = 20;
	int& ref = a;
	cout << a << endl;
	cout << ref << endl;

	test03(a);
	cout << a << endl;
	cout << ref << endl;

	ref = c;
	cout << a << endl;
	cout << ref << endl;
	system("pause");
	return 0;
}