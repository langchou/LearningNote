#include <iostream>
#include <string>
using namespace std;


//void SwapInt(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void SwapDouble(double& c, double& d)
//{
//	double temp = c;
//	c = d;
//	d = temp;
//}
//
//template<typename T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//void test1()
//{
//	int a = 10;
//	int b = 20;
//	//SwapInt(a, b);
//	//�Զ������Ƶ�
//	Swap(a, b);
//	cout << a << endl;
//	cout << b << endl;
//	//��ʾָ������
//	double c = 1.1;
//	double d = 2.2;
//	Swap<double>(c, d);
//	//SwapDouble(c, d);
//	cout << c << endl;
//	cout << d << endl;
//}
//
//
//template <class T>
//void mySort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;//�϶����ֵ�±�
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			int temp = arr[i];
//			arr[i] = arr[max];
//			arr[max] = temp; 
//		}
//	}
//}
//
//template <class T>
//void printArray(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
//
//class Person
//{
//public :
//	Person(string name, int age)
//	{
//		this->m_age = age;
//		this->m_name = name;
//	}
//
//	string m_name;
//	int m_age;
//};
//
//template <class T>
//bool myCompare(T& a, T& b)
//{
//	if (a == b)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//template<>bool myCompare(Person& a, Person& b)
//{
//	if (a.m_age == b.m_age && a.m_name == b.m_name)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//
//
//void test()
//{
//	char arr[] = "qpaorngkb";
//	int len = sizeof(arr) / sizeof(arr[0]);
//	mySort<char>(arr, len);
//	printArray(arr, len);
//
//	int arr2[] = { 1,5,6,78,9,123,4,11, };
//	int len2 = sizeof(arr2) / sizeof(arr2[0]);
//	mySort<int>(arr2, len2);
//	printArray(arr2, len2);
//}
//
//void test2()
//{
//	Person p1("TOM", 11);
//	Person p2("TOM", 12);
//
//	bool ret = myCompare(p1, p2);
//	if (ret)
//	{
//		cout << "p1==p2" << endl;
//	}
//	else
//	{
//		cout << "p1!=p2" << endl;
//	}
//}
//
//
//template<class NameType, class AgeType>
//class Person2
//{
//public:
//	Person2(NameType name,AgeType age)
//	{
//		this->age = age;
//		this->name = name;
//	}
//
//	void showPerson()
//	{
//		cout << name << age << endl;
//	}
//
//	NameType name;
//	AgeType age;
//};
//
//void test3()
//{
//	Person2 <string, int>p1("�����", 999);
//	p1.showPerson();
//}
//
//class Demo1
//{
//public:
//	void showDemo1()
//	{
//		cout << "����showDemo1" << endl;
//	}
//};
//class Demo2
//{
//public:
//	void showDemo2()
//	{
//		cout << "����showDemo2" << endl;
//	}
//};
//
//
//template<class T>
//class myDemo
//{
//public:
//	void func1()
//	{
//		obj.showDemo1();
//	}
//	void func2()
//	{
//		obj.showDemo2();
//	}
//
//	T obj;
//
//};
//
//void test4()
//{
//	myDemo<Demo1>d1;
//	d1.func1();
//	myDemo<Demo2>d2;
//	d2.func2();
//}
//
//class Person3
//{
//public :
//	Person3(string name, int age)
//	{
//		this->age = age;
//		this->name = name;
//	}
//
//	void showPerson()
//	{
//		cout << name << age << endl;
//	}
//
//	string name;
//	int age;
//};
////1.ָ����������
//void printPerson1(Person2<string, int>&p)
//{
//	p.showPerson();
//}
//
////2.����ģ�廯
//template<class T1,class T2>
//void printPerson2(Person2<T1, T2>& p)
//{
//	p.showPerson();
//}
////3.������ģ�廯
//template<class T>
//void printPerson3(T& p)
//{
//	p.showPerson();
//}
//
//
//void test5()
//{
//	Person2<string, int>p1("�����", 1111);
//	Person2<string, int>p2("��˽�", 2222);
//	Person2<string, int>p3("ɳ��", 3333);
//	printPerson1(p1);
//	printPerson2(p2);
//	printPerson3(p3);
//}
////int main()
////{
////	//test();
////	//test2();
////	//test3();
////	//test4();
////	test5();
////	system("pause");
////	return 0;
////}
//
//
//template<class T>
//class Base
//{
//	T m;
//};
//
//class Son :public Base<int>
//{
//
//};
//
//template<class T1,class T2>
//class Son2 :public Base<T2>
//{
//public:
//	T1 obj;
//};
//
//void test6()
//{
//	Son2<int, char>S2;  //int������Son2�е�obj,char������Base�е�m
//}

template<class T1, class T2>
class Person
{
public:
	Person(T1 name,T2 age);

	void showPerson();

	T1 name;
	T2 age;
};

template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	this->age = age;
	this->name = name;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "���䣺" << this->age << " ���֣�" << this->name << endl;
}

void test7()
{
	Person<string, int>p("����",20);
	p.showPerson();
}

int main()
{
	test7();
}