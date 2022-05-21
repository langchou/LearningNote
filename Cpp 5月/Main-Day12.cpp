#include <iostream>
using namespace std;


class Father
{
public:

	Father()
	{
		cout << "����Ĭ�Ϲ���" << endl;
		m_A = 100;
	}

	void func()
	{
		cout << "Father - func" << endl;
	}

	void func(int a)
	{
		cout << "Father - func(int)" << endl;
	}

	static void func3()
	{
		cout << "Father - static func" << endl;
	}

	static void func3(int a)
	{
		cout << "Father - static func" << endl;
	}


	~Father()
	{
		cout << "��������" << endl;
	}


	int m_A;
	static int m_B;
};

int Father::m_B = 100;

class Son :public Father
{
public:

	Son()
	{
		cout << "����Ĭ�Ϲ���" << endl;
		m_A = 200;
	}

	void func()
	{
		cout << "Son - func" << endl;
	}

	static void func3()
	{
		cout << "Son - static func" << endl;
	}

	//void func(int a)
	//{
	//	cout << "Son - func(int)" << endl;
	//}

	~Son()
	{
		cout << "��������" << endl;
	}

	int m_A;
	static int m_B;

};

int Son::m_B = 200;

void test()
{
	Father s2;
	Son s;
	s.func();
	s.Father::func(1); //�̳е��ø���ͬ����Ա���� 
	s.Father::func();
	cout << s.m_A << endl;
	cout << "Son m_B: " << s.m_B << endl;
	cout << "Father m_B: " << s.Father::m_B << endl;
	cout << "ͨ������ֱ�ӷ���" << endl;
	cout << Son::m_B << endl;
	cout << "ͨ������+������ ���ʸ���" << endl;
	cout << Son::Father::m_B << endl;

	cout << s.Father::m_A << endl;  //������������

	s.Father::func3();
	s.func3();

	Son::func3();
	Son::Father::func3();

	Son::Father::func3(1);


}


int main()
{

	test();
	system("pause");
	return 0;
}