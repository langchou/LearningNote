#include <iostream>
using namespace std;

//���캯�� ��������

class Person
{


public:
	Person()
	{
		cout << "�޲ι��캯��" << endl;
	}

	Person(int a)
	{
		age = a;
		cout << "�вι��캯��"<< endl;
	}
	Person(const Person& p)
	{
		age = p.age;
		cout << "�������캯��" << endl;
	}

	//�ڴ��ͷ�ǰ����
	~Person() 
	{
		cout << "�������캯��" << endl;
	}

	int age;
}; 

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
Person dowork2()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test3()
{
	Person p = dowork2();
	cout << (int*)&p << endl;

}


int main()
{
//	test();
//	test1();
	test3();
	system("pause");
	return 0;
}