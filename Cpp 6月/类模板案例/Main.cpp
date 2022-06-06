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
		cout << "����" << arr[i].name << endl << "����" << arr[i].age << endl;
	}
}


void test01()
{
	MyArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//����β�巨�������������
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ" << endl;
	printIntArray(arr1);

	cout << "arr1������:" << arr1.get_capacity() << endl;
	cout << "arr1�Ĵ�С:" << arr1.get_size() << endl;

//	MyArray<int>arr2(arr1);
	MyArray<int>arr2(5);
	MyArray<int>arr3(5);
	cout << "arr2�Ĵ�ӡ���Ϊ" << endl;

	printIntArray(arr2);
	printIntArray(arr3);

	arr3 = arr2 = arr1;
	arr2.Pop_Back();
	cout << "arr2������:" << arr2.get_capacity() << endl;
	cout << "arr2�Ĵ�С:" << arr2.get_size() << endl;

	arr3.Pop_Back();
	

	cout << "arr3������:" << arr3.get_capacity() << endl;
	cout << "arr3�Ĵ�С:" << arr3.get_size() << endl;

}

void test02()
{
	MyArray<Person>arr2(10);
	Person p1("�����", 999);
	Person p2("��˽�", 888);
	Person p3("ɳ��", 777);
	Person p4("������", 666);

	//���ݲ���
	arr2.Push_Back(p1);
	arr2.Push_Back(p2);
	arr2.Push_Back(p3);
	arr2.Push_Back(p4);
	//��ӡ����
	printPersonArray(arr2);
	//��ӡ����
	cout << "����:" << arr2.get_capacity() << endl;
	//��ӡ��С
	cout << "��С:" << arr2.get_size() << endl;

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