#include <iostream>
#include <string>
using namespace std;

//���캯�����ù���  ���\ǳ����

//class Person
//{
//
//
//public:
//	Person()
//	{
//		cout << "�޲ι��캯��" << endl;
//	}
//
//	Person(int a)
//	{
//		age = a;
//		cout << "�вι��캯��" << endl;
//	}
//	Person(const Person& p)
//	{
//		age = p.age;
//		cout << "�������캯��" << endl;
//	}
//
//	//�ڴ��ͷ�ǰ����
//	~Person()
//	{
//		cout << "�������캯��" << endl;
//	}
//
//	int age;
//};

//void test()
//{
//	Person p;
//}
//
//void test1()
//{
//	//���ŷ�
//	//Person p1; //Ĭ�Ϲ��캯������
//	//Person p2(10); //�вι���
//	//Person p3(p2); //��������
//
//
//	//��ʾ��
//	Person p1;
//	Person p2 = Person(10); //�вι���
//	Person p3 = Person(p3); //��������
//
//	Person(10); //�������� ǰ�н�����ϵͳ������������������
//
//	//��ʽת����
//	Person p4 = 10; //�൱��Person p4 = Person(10)
//
//} 

//ֵ���ݵķ�ʽ������ 
//void dowork(Person p)
//{
//	
//}

//void test2()
//{
//	Person p; //�޲ι���
//	doword(p);
//
//}

//ֵ��ʽ���ؾֲ�����
//Person dowork2()
//{
//	Person p1;
//	cout << (int*)&p1 << endl;
//	return p1;
//}
//
//void test3()
//{
//	Person p = dowork2();
//	cout << (int*)&p << endl;
//
//}

//���ù���

//int main()
//{
//	//	test();
//	//	test1();
//	test3();
//	system("pause");
//	return 0;
//}
// 
//���ù���
//class Person
//{
//
//public:
//
//	Person()
//	{
//
//		cout << "Ĭ�Ϲ��캯��" << endl;
//	}
//
//	Person(int age)
//	{
//		cout << "�вι��캯��" << endl;
//		m_age = age;
//	}
//
//	Person(const Person& p)
//	{
//		cout << "�������캯��" << endl;
//		m_age = p.m_age;
//	}
//
//	~Person()
//	{
//		cout << "��������" << endl;
//	}
//
//
//	int m_age;
//};
//
//
//
//void test01()
//{
//	Person p;
//	p.m_age = 18;
//	Person p2(p);
//	cout << "p2���䣺" << p2.m_age << endl;
//
//}
//
//
//void test02()
//{
//	Person p(28);
//	Person p2(p);
////	p.m_age = 18;
//	cout << "p2���䣺" << p2.m_age << endl;
//
//}
//
//
//int main()
//{
////	test01();
//	test02();
//	system("pause");
//	return 0;
//}

//�����ǳ����

//class Person
//{
//public:
//	Person()
//	{
//		cout << "Ĭ�Ϲ��캯��" << endl;
//	}
//
//	Person(int age,int height)
//	{
//		cout << "�вι��캯��" << endl;
//		m_age = age;
//		m_height = new int(height);
//	}
//
//	Person(const Person& p)
//	{
//		cout << "�������캯��" << endl;
//		m_age = p.m_age;
//	//	m_height = p.m_height; //������Ĭ�Ͽ������캯��
//		m_height = new int(*p.m_height);
//
//	}
//
//	~Person()
//	{
//		//�ͷŶ����ڴ�
//		if (m_height != NULL)
//		{
//			delete m_height;
//			m_height = NULL;
//		}
//		cout << "��������" << endl;
//	}
//
//
//	int m_age;
//	int *m_height;
//};
//
//
//void test01()
//{
//	Person p1(18,160);
//	cout << "p1����Ϊ" << p1.m_age << "p1�����Ϊ: " << *p1.m_height << endl;
//
//	Person p2(p1);
//	cout << "p2����Ϊ" << p2.m_age << "p2�����Ϊ: " << *p2.m_height << endl;
//
//
//}
//
//
//int main()
//{
//	test01();
//	
//	system("pause");
//	return 0;
//}


//��ʼ���б�

//class Person
//{
//public:
//	//��ͳ��ʼ������
//	//Person(int a, int b, int c)
//	//{
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//}
//
//	//��ʼ���б�
//	Person(int a, int b, int c):m_A(a), m_B(b), m_C(c)
//	{
//
//	}
//
//
//	int m_A;
//	int m_B;
//	int m_C;
//};
//
//
//void test01()
//{
//	Person p(10, 20, 30);
////	Person p;
//	cout << "m_A = " << p.m_A << endl;
//	cout << "m_B = " << p.m_B << endl;
//	cout << "m_C = " << p.m_C << endl;
//}
//
//int main()
//{
//
//	test01();
//
//	system("pause");
//	return 0;
//}


//class Phone
//{
//
//public:
//
//	Phone(string pname)
//	{
//		p_name = pname;
//		cout << "Phone��������" << endl;
//	}
//
//	~Phone()
//	{
//		cout << "Phone����" << endl;
//	}
//
//	string p_name;
//};
//
//
//class Person
//{
//
//public:
//
//	Person(string name,string pname):m_name(name),m_phone(pname)
//	{
//		cout << "Person��������" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person����" << endl;
//	}
//
//	string m_name;
//	Phone m_phone;
//};
//
//
//void test()
//{
//	Person p("����", "iphone13");
//
//	cout << p.m_name << "����" << p.m_phone.p_name << endl;
//}

//int main()
//{
//
//	test();
//	system("pause");
//	return 0;
//}


//��̬��Ա����

class Person
{
public:
	
	//���ж�����ͬһ������
	//����׶η����ڴ�
	//��������,�����ʼ��

	static int m_A;

private:
	static int m_B;

};

int Person::m_A = 10;
int Person::m_B = 200;


void test()
{
	Person p1;
	cout << p1.m_A << endl;
//	cout << p1.m_B << endl; //�޷�����private�еĳ�Ա

	Person p2;
	p2.m_A = 100;
	cout << p1.m_A << endl;
}


int main()
{
	test();
	
	system("pause");
	return 0;
}