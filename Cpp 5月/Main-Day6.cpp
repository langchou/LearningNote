#include <iostream>
using namespace std;

//���캯�� ��������

class Person
{


public:
	Person()
	{
		cout << "���캯���ĵ���"<<"�޲�" << endl;
	}

	Person(int a)
	{
		age = a;
		cout << "���캯���ĵ���" << "�в�" << endl;
	}
	Person(const Person& p)
	{
		age = p.age;
	}
	~Person()
	{
		cout << "���������ĵ���" << endl;
	}

	int age;
};

void test()
{
	Person p;
}

void test1()
{
	//���ŷ�
	//Person p1; //Ĭ�Ϲ��캯������
	//Person p2(10); //�вι���
	//Person p3(p2); //��������


	//��ʾ��
	Person p1;
	Person p2 = Person(10); //�вι���
	Person p3 = Person(p3); //��������

	Person(10); //�������� ǰ�н�����ϵͳ������������������

	//��ʽת����
	Person p4 = 10; //�൱��Person p4 = Person(10)

} 

void dowork(Person p)
{
	
}


void test2()
{
	Person p;
	doword(p);

}

int main()
{
//	test();
//	test1();

	system("pause");
	return 0;
}