#include <iostream>
using namespace std;

//
//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//
//
//class Cat :public Animal
//{
//
//public:
//	void speak()
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//
//public:
//	void speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//};
//
//void doSpeak(Animal& animal)
//{
//	animal.speak();
//}
//
//void test02()
//{
//	 
//}
//
//void test01()
//{
//	Cat cat;
//	doSpeak(cat);
//}

//
//class AbstractCalculator
//{
//public:
//	//���麯�� ����Ϊ������
//	virtual int getResult() = 0;
//
//
//	int m_num1;
//	int m_num2;
//
//};
//
//class Addcalculator : public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_num1 + m_num2;
//	}
//};
//
//
//class Subcalculator : public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_num1 - m_num2;
//	}
//};
//
//class Mulcalculator : public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_num1 * m_num2;
//	}
//};
//
//
//void test()
//{
//	AbstractCalculator* temp = new Addcalculator;
//	
//	temp->m_num1 = 100;
//	temp->m_num2 = 100;
//
//	cout << temp->m_num1 << "+" << temp->m_num2 << "=" << temp->getResult() << endl;
//
//	delete temp;
//
//	temp = new Subcalculator;
//
//	temp->m_num1 = 100;
//	temp->m_num2 = 100;
//
//	cout << temp->m_num1 << "-" << temp->m_num2 << "=" << temp->getResult() << endl;
//
//	delete temp;
//
//	temp = new Mulcalculator;
//
//	temp->m_num1 = 100;
//	temp->m_num2 = 100;
//
//	cout << temp->m_num1 << "*" << temp->m_num2 << "=" << temp->getResult() << endl;
//
//	delete temp;
//
//}


class AbstractDrinking
{
public:

	virtual void Boil() = 0;

	virtual void Brew() = 0;

	virtual void PourInCup() = 0;

	virtual void PutSTH() = 0;

	void makedrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSTH();
	}
};

class Coffee :public AbstractDrinking
{

public:
	void Boil()
	{
		cout << "��ˮ" << endl;
	}

	void Brew()
	{
		cout << "���ݿ���" << endl;
	}

	void PourInCup()
	{
		cout << "�������ȱ�" << endl;
	}

	void PutSTH()
	{
		cout << "����ţ����" << endl;
	}
};

class Tea :public AbstractDrinking
{

public:
	void Boil()
	{
		cout << "��ˮ" << endl;
	}

	void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}

	void PourInCup()
	{
		cout << "�����豭��" << endl;	
	}

	void PutSTH()
	{
		cout << "�������" << endl;
	}
};

void dowork(AbstractDrinking* abs)
{
	abs->makedrink();
	delete abs;
}

void test()
{
	dowork(new Tea);
	cout << "..." << endl;
	dowork(new Coffee);
}


int main()
{
	test();


	system("pause");
	return 0;
}