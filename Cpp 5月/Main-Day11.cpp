#include <iostream>

using namespace std;

//class Base
//{
//public:
//	void head()
//	{
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//		cout << "1111111111111" << endl;
//	}
//};
////�̳�
//class java :public Base
//{
//public:
//	void content()
//	{
//		cout << "java" << endl;
//	}
//};
//class python :public Base
//{
//public:
//	void content()
//	{
//		cout << "python" << endl;
//	}
//};

//void test()
//{
//	java p1;
//	p1.head();
//	p1.content();
//	python p2;
//	p2.head();
//	p2.content();
//
//}

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	void func()
	{
		m_A = 10; //����Ĺ���Ȩ�޵������л��ǹ���Ȩ��
		m_B = 10; //����ı���Ȩ�޵������л��Ǳ���Ȩ��
	//	m_C = 10; //�����˽��Ȩ�� �����޷�����
	}
};


class Son2 :protected Base
{
public:
	void func()
	{
		m_A = 10; //�����еĹ���Ȩ�� �������б�Ϊ����Ȩ��
		m_B = 10; //�����еı���Ȩ�� �������б�Ϊ����Ȩ��
		m_C = 10; //�����е�˽�г�Ա �����޷�����
	}
};


class Son3 :private Base
{
public:
	void func()
	{
		m_A = 10; //�����еĹ���Ȩ�� �������б�Ϊ˽��Ȩ��
		m_B = 10; //�����еı���Ȩ�� �������б�Ϊ˽��Ȩ��
		m_C = 10; //�����е�˽�г�Ա �����޷�����
	}
};
void test01()
{
	Son s1;
	Son2 s2;
	Son3 s3;
//	s2.m_A = 1000; //Son2�� m_A��Ϊ����Ȩ�ޣ������޷�����
//	s3.m_A = 1000; //Son3�� m_A��Ϊ˽��Ȩ�ޣ������޷�����
	s1.m_A = 10; //����Ȩ���������ⶼ���Է���
}

int main()
{
//	test();
	Son p1;
	p1.func();
	system("pause");
	return 0;
}