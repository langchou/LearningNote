#include <iostream>
#include <vector>
#include <algorithm> //STL�ṩ�ı�׼�㷨
#include <string>


using namespace std;


void myPrint(int val)
{
	cout << val << endl;
}

class Person
{
public:
	Person(string name ,int age)
	{
		this->age = age;
		this->name = name;
	}
public:
	int age;
	string	name;
};

void test2()
{
	vector<Person>v;
	Person p1("����", 10);
	Person p2("����", 12);
	Person p3("����", 14);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for (vector<Person>::iterator it=v.begin(); it < v.end(); it++)
	{
		cout << "���֣�" << it->name << " ���䣺" << it->age << endl;
	}
}

void test3()
{
	vector<Person *>v;
	Person p1("����", 10);
	Person p2("����", 12);
	Person p3("����", 14);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	for (vector<Person *>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << "���֣�" << (*it)->name << " ���䣺" << (*it)->age << endl;
	}
}


void test1()
{
	//����vector����	
	vector<int> v;

	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	
	//��һ�ֱ�����ʽ
	vector<int>::iterator itbegin = v.begin();
	vector<int>::iterator itend = v.end();
	while (itbegin != itend)
	{
		cout << *itbegin << endl;
		itbegin++;
	}
	

	//�ڶ��ֱ�����ʽ
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << endl;
	}

	//�����ֱ�����ʽ STL�ṩ�ı����㷨
	for_each(v.begin(), v.end(), myPrint);
}


void test4()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
		v5.push_back(i + 5);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = it->begin(); vit != it->end(); vit++)
		{
			cout << (*vit) << " ";
		}
		cout << endl;
	}
}

void test5()
{
	string str1;
	str1.append("����");
	string str2 = "������Ϸ";
	str1.append(str2);
	string str3 = "LOLDNF";
	str1.append(str3, 3, 3);
	cout << str1 << endl;
}

void test6()
{
	string str1 = "abcdefg";
	string str2 = "abcdefgde";
	int pos = str1.find("de");
	int pos2 = str2.rfind("de");

	str1.replace(1, 3, "11111");
	cout << str1 << endl;
	cout << pos << endl;
	cout << pos2 << endl;
}

void test7()
{

	string str1 = "abcde";
	string str2 = "abcdf";

	int temp = str1.compare(str2);
	cout << temp << endl;
}

void test8()
{
	string str1 = "hello";
	string str2 = "hello";
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << " ";
		str1[i] = 'a';
		cout << str1.at(i) << " ";
	}
	cout << endl;

	str2.at(2) = 'L';
	str2.insert(1, "222");
	cout << str2 << endl;

	str2.erase(1, 3);
	cout << str2 << endl;

	string str3 = str2.substr(1, 3);
	cout << str3 << endl;

	string str4 = "zhangsan@sina.com";
	int pos = str4.find("@");
	string usName = str4.substr(0, pos);
	cout << usName << endl;

	vector<int>v4;
	v4.assign(10, 100);
}

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test9()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	if (v1.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "v1������" << v1.capacity() << endl;
		cout << "v1�Ĵ�С" << v1.size() << endl;
	}

	v1.resize(10);
	printVector(v1);
	v1.resize(5);
	printVector(v1);


}


void test10()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	v1.insert(v1.begin(), 2, 10);
	printVector(v1);

	v1.erase(v1.begin(),v1.begin()+2);
	printVector(v1);

}

void test11()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}

	printVector(v1);
	printVector(v2);

	v1.swap(v2);

	cout << "����" << endl;

	printVector(v1);
	printVector(v2);
}

void test12()
{
	vector<int>v;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v������" << v.capacity() << endl;
	cout << "v�Ĵ�С" << v.size() << endl;

	v.resize(5);

	vector<int>(v).swap(v);
	cout << "v������" << v.capacity() << endl;
	cout << "v�Ĵ�С" << v.size() << endl;
}

int main()
{
	//test();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	//test11();
	test12();
	system("pause");
	return 0;
}