#include <iostream>

using namespace std;

//class Person
//{
//public:
//
//	//Person(int a, int b) :m_A(a), m_B(b)
//	//{
//
//	//}
//
//	static int m_A;
//	//int m_B;
//
//};
//
//int Person::m_A = 100;
////int Person::m_B = 200;
//
//void test1()
//{
//
//	Person p1;
//	cout << p1.m_A << endl;
//	//Person p2;
//	//cout << p2.m_A << endl;
//
//}
//
//int main()
//{
//
//	test1();
//
//	system("pause");
//	return 0;
//}


class Person
{


public:
	//��̬��Ա����
	static void func()
	{
		m_A = 100; // ��̬��Ա�������Է��ʾ�̬��Ա����
		cout << "func����" << endl;
		cout << "m_A = " << m_A << endl;

	}

	//��̬��Ա���� ���ڴ��� �����ʼ��
	static int m_A;


	//��̬��Ա����Ҳ�з���Ȩ��
private: 
	static void func2()
	{
		cout << "func2����" << endl;
	}
};

int Person::m_A = 10;

void test01()
{
	//ͨ���������
	Person p;
	p.func();
//	p.func2();

	//ͨ����������
	Person::func();
	Person::m_A;
}


//��Ա�����ͳ�Ա�����ֿ��洢


class Person2
{
	//�Ǿ�̬������Ķ�����
	int p_a;
	//��̬��Ա������������Ķ�����
	static int p_b;

	void func(){} //�Ǿ�̬��Ա�����;�̬��Ա��������������Ķ�����

	static void func2(){}
};

int Person2::p_b = 10;


void test02()
{
	Person2 p;


	cout << "size of p =" << sizeof(p) << endl;
}

int main()
{

//	test01();
	test02(); 
	system("pause");
	return 0;
}