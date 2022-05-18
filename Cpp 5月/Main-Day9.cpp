#include <iostream>

using namespace std;


//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//	friend Person operator+(Person& p1, Person& p2);
//
//public:
//
//	Person(){}
//
//	Person(int m_A, int m_B)
//	{
//		this->m_A = m_A;
//		this->m_B = m_B;
//	}
//private:
//	用成员函数重载 +运算符
//	Person operator+(Person &p)
//	{
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}
//
//	int m_A;
//	int m_B;
//};
//
//
//
//
//Person operator+(Person& p1, Person& p2)
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
//
//ostream& operator<<(ostream& cout, Person& p)
//{
//	cout << p.m_A << p.m_B;
//	return cout;
//}
//



class MyInterger
{
	friend ostream& operator<<(ostream& cout, MyInterger Myint);
	

public:
	MyInterger()
	{
		m_Num = 0;
	}

	//前置++
	MyInterger& operator++()
	{
		m_Num++;
		return *this;
	}

	//后置++
	MyInterger operator++(int)
	{
		MyInterger temp = *this;
		m_Num++;
		return temp;
	}





private:
	int m_Num;

};



ostream& operator<<(ostream& cout, MyInterger Myint)
{
	cout << Myint.m_Num;
	return cout;
}



void test02()
{
	MyInterger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}




//void test01()
//{
//	Person p1(10,10);
//	Person p2(10,10);
//
//	//成员函数重载本质调用
//	//Person p3 = p1.operator+(p2);
//
//	//全局函数重载本质调用 
//	Person p3 = operator+(p1, p2);
//	cout << p3 << endl;
//}





int main()
{
//	test01();
	test02();
	system("pause");
	return 0;
}