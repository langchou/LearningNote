#include <iostream>
using namespace std;
#include <string> 



class Person
{
public :



	Person(int age)
	{
		this->age = age;
	}


	Person& PersonAddAge(const int &age)
	{
		this->age += age;
		return *this;
	}


	int age;
};

void test01()
{

	Person p(18);

	cout << p.age << endl;
}

void test02()
{
	Person p1(18);
	Person p2(20);

	//��ʽ���
	p2.PersonAddAge(p1.age).PersonAddAge(p2.age).PersonAddAge(p1.age);
	cout << p2.age << endl;
}


//class Building
//{
//
//public :
//
//	friend void goodgay(Building *building);  //��Ԫ
//	Building()
//	{
//		sittingroom = "����";
//		bedroom = "����";
//	}
//
//
//	string sittingroom;
//private:
//	string bedroom;
//};
//
//void goodgay(Building *building)
//{
//	cout << "1" << building->sittingroom << endl;
//	cout << "1" << building->bedroom << endl;
//}
//
//void test03()
//{	
//	Building building;
//	goodgay(& building);
//}



class Buiding
{
//	friend class GoodGay;
//	friend void GoodGay::visit();


public:
	Buiding();
	string sittingroom;

private:
	string badroom;

};

Buiding::Buiding()
{
	sittingroom = "����";
	badroom = "����";

}



class GoodGay
{

public:
	GoodGay();


	void visit();   //��visit�������Է���Building�е�˽�г�Ա 
	void visit2();  //��visit2���������Է���Building�е�˽�г�Ա 
	Buiding* buiding;
	 
};


GoodGay :: GoodGay()
{
	buiding = new Buiding;
}

void GoodGay::visit()
{
	cout << "visit�ڷ���" << buiding->sittingroom << endl;
	cout << "visit2�ڷ���" << buiding->badroom << endl;
}

void GoodGay::visit2()
{
//	cout << "visit2�ڷ���" << buiding->badroom << endl;
}

void test04()
{
	GoodGay gg;
	gg.visit();
//	gg.visit2();
}


int main()
{

//	test01();
//	test02();
//	test03();
	test04();
	system("pause");
	return 0;
}