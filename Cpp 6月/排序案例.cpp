#include <iostream>
using namespace std;
#include <string>
#include <list>
/*
	��Person�Զ����������ͽ�������Person�����������������䡢���
	������򣺰�����������������������ͬ������߽��н���
*/

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}

	string name;
	int age;
	int height;
};

void printList(const list<Person>& List)
{
	for (list<Person>::const_iterator it = List.begin(); it != List.end(); it++)
	{
		cout << "������" << it->name << " ���䣺" << it->age << " ��ߣ�" << it->height << endl;;
	}
}

bool myCompare(Person &L1, Person &L2)
{
	
	if (L1.age == L2.age)
	{
		//������ͬ ��߽���
		return L1.height > L2.height;
	}
	else
	{
		return L1.height < L2.height;
	}
}

int main()
{
	list<Person>List;
	Person p1("����", 25, 160);
	Person p2("����", 28, 170);
	Person p3("����", 30, 165);
	Person p4("����", 35, 174);
	Person p5("Ǯ��", 25, 166);
	Person p6("���", 25, 125);
	Person p7("�ܾ�", 41, 178);
	Person p8("κʮ", 32, 190);
	List.push_back(p1);
	List.push_back(p2);
	List.push_back(p3);
	List.push_back(p4);
	List.push_back(p5);
	List.push_back(p6);
	List.push_back(p7);
	List.push_back(p8);
	List.sort(myCompare);
	printList(List);
	system("pause");
	return 0;
}