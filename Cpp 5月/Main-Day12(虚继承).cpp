#include <iostream>
using namespace std;

//��̳�

class Animal
{
public:
	int a;
};

//��̳� ������μ̳����� 
//Animal��Ϊ����� 
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