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

	//链式编程
	p2.PersonAddAge(p1.age).PersonAddAge(p2.age).PersonAddAge(p1.age);
	cout << p2.age << endl;
}


//class Building
//{
//
//public :
//
//	friend void goodgay(Building *building);  //友元
//	Building()
//	{
//		sittingroom = "客厅";
//		bedroom = "卧室";
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
	sittingroom = "客厅";
	badroom = "卧室";

}



class GoodGay
{

public:
	GoodGay();


	void visit();   //让visit函数可以访问Building中的私有成员 
	void visit2();  //让visit2函数不可以访问Building中的私有成员 
	Buiding* buiding;
	 
};


GoodGay :: GoodGay()
{
	buiding = new Buiding;
}

void GoodGay::visit()
{
	cout << "visit在访问" << buiding->sittingroom << endl;
	cout << "visit2在访问" << buiding->badroom << endl;
}

void GoodGay::visit2()
{
//	cout << "visit2在访问" << buiding->badroom << endl;
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