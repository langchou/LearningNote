#include "MyArrray.hpp"


void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		cout << arr[i] << endl;
	}
}




class Person
{

public:

	Person() {};
	Person(string name,int age)
	{
		this->name = name;
		this->age = age;
	} 

public:
	string name;
	int age;
};


void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		cout << "姓名" << arr[i].name << endl << "年龄" << arr[i].age << endl;
	}
}


void test01()
{
	MyArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组插入数据
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为" << endl;
	printIntArray(arr1);

	cout << "arr1的容量:" << arr1.get_capacity() << endl;
	cout << "arr1的大小:" << arr1.get_size() << endl;

//	MyArray<int>arr2(arr1);
	MyArray<int>arr2(5);
	MyArray<int>arr3(5);
	cout << "arr2的打印输出为" << endl;

	printIntArray(arr2);
	printIntArray(arr3);

	arr3 = arr2 = arr1;
	arr2.Pop_Back();
	cout << "arr2的容量:" << arr2.get_capacity() << endl;
	cout << "arr2的大小:" << arr2.get_size() << endl;

	arr3.Pop_Back();
	

	cout << "arr3的容量:" << arr3.get_capacity() << endl;
	cout << "arr3的大小:" << arr3.get_size() << endl;

}

void test02()
{
	MyArray<Person>arr2(10);
	Person p1("孙悟空", 999);
	Person p2("猪八戒", 888);
	Person p3("沙悟净", 777);
	Person p4("唐玄奘", 666);

	//数据插入
	arr2.Push_Back(p1);
	arr2.Push_Back(p2);
	arr2.Push_Back(p3);
	arr2.Push_Back(p4);
	//打印数组
	printPersonArray(arr2);
	//打印容量
	cout << "容量:" << arr2.get_capacity() << endl;
	//打印大小
	cout << "大小:" << arr2.get_size() << endl;

}

int main(){
	//MyArray <int>arr1(5);
	//MyArray <int>arr2(arr1);
	//MyArray <int>arr3(100);
	//arr3 = arr1;
//	test01();
	test02();

	system("pause");
	return 0;
}