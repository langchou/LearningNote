#include <iostream>
using namespace std;
#include <string>
#include <list>
/*
	将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
	排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
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
		cout << "姓名：" << it->name << " 年龄：" << it->age << " 身高：" << it->height << endl;;
	}
}

bool myCompare(Person &L1, Person &L2)
{
	
	if (L1.age == L2.age)
	{
		//年龄相同 身高降序
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
	Person p1("张三", 25, 160);
	Person p2("李四", 28, 170);
	Person p3("王五", 30, 165);
	Person p4("赵六", 35, 174);
	Person p5("钱七", 25, 166);
	Person p6("孙八", 25, 125);
	Person p7("周九", 41, 178);
	Person p8("魏十", 32, 190);
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