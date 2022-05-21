#include <iostream>
using namespace std;

//虚继承

class Animal
{
public:
	int a;
};

//虚继承 解决菱形继承问题 
//Animal称为虚基类 
class Sheep:virtual public Animal
{

};

class Tuo :virtual public Animal
{

};

class TuoSheep :public Sheep, public Tuo
{

};



void test01()
{
	TuoSheep a;
	a.a = 100;
	cout << a.a << endl;
}


int main()
{
	test01();
	
	system("pause");
	return 0;
}