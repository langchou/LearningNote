#include <iostream>

using namespace std;

//��ϵ���������,�º���

//class Person
//{
//
//
//
//public:
//
//	Person(int age)
//	{
//		//�����ڶ���
//		m_Age = new int(age);
//	}
//
//	//��������ɶ����ڴ��ظ��ͷ� �����
//	~Person()
//	{
//
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//
//	//���ظ�ֵ����� =
//	Person& operator=(Person &p)
//	{
//
//		//���õ�ʱ�� p2�Ѿ�����20 ��������һ�������ڴ� Ҫ���жϲ��ͷŶ����ڴ����������
//		if (m_Age != NULL)
//		{
//			delete m_Age;   
//			m_Age = NULL;
//		}
//		//���
//		m_Age = new int(*p.m_Age);
//
//		//��ʽ���
//		return *this;
//	}
//
//
//
//	int* m_Age;
//	
//};

//void test01()
//{
//	Person  p1(22);
//	Person  p2(20);
//	Person  p3(30);
//	Person p4(40);
//	p4 =p3 = p2 = p1;
//
//	cout << "p1������Ϊ" << *p1.m_Age << endl;
//
//	cout << "p2������Ϊ" << *p2.m_Age << endl;
//
//	cout <<"p3������Ϊ" <<*p3.m_Age << endl;
//	cout <<"p4������Ϊ" <<*p4.m_Age << endl;
//}



class Person
{

public:
	Person(){}

	Person(string name, int age)
	{
		mName = name;
		mAge = age;
	}

	bool operator==(Person &p)
	{
		if (mName == p.mName && mAge == p.mAge)
		{
			return true;
		}
		return false;
	}

	bool operator!=(Person& p)
	{
		if (mName == p.mName && mAge == p.mAge)
		{
			return false;
		}
		return true;
	}


	string mName;
	int mAge;

};


class MyPrint
{

public:
	//�º���
	void operator()(string test)
	{
		cout << test << endl;
	}

};


class MyAdd
{

public:
	int operator()(int num1,int num2)
	{
		return num1 + num2;
	}
};

void test02()
{
	MyPrint myprint; 
	myprint("hello world");//���ƺ������ã���Ϊ�º���
	MyAdd myadd;
	int ret = myadd(100, 202);
	cout << ret << endl;

	//������������
	cout << MyAdd()(100, 203) << endl;
}

	
{
	Person p1("����", 18);

	Person p2("123", 18);

	if (p1 == p2)
	{
		cout << "p1p2���" << endl;
	}
	else
	{
		cout << "p1p2�����" << endl;
	}


	if (p1 != p2)
	{
		cout << "p1p2�����" << endl;
	}
	else
	{
		cout << "p1p2���" << endl;
	}
}



int main()
{
//	test01();
	//int a = 10;
	//int b = 20;
	//int c = 30;
	//c = b = a;
	//cout << c << b << a << endl;


//	test01();
	test02();
	system("pause");
	return 0;
}