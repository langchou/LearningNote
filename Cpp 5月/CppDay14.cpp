//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal构造调用" << endl;
//	}
//
//	//虚析构
//	//virtual ~Animal()
//	//{
//	//	cout << "Animal虚析构调用" << endl;
//	//}
//
//	//纯虚析构
//	virtual ~Animal() = 0;
//
//	
//	virtual void speak() = 0;
//
//};
//Animal::~Animal()
//{
//	cout << "Animal纯虚析构调用" << endl;
//}
//
//
//
//class Cat :public Animal
//{
//public:
//
//	Cat(string name)
//	{
//		cout << "cat构造调用" << endl;
//		m_name = new string(name);
//	}
//
//	void speak()
//	{
//		cout<< *m_name << "小猫在说话" << endl;
//	}
//
//	~Cat()
//	{
//		if (m_name != NULL)
//		{
//			cout << "Cat析构调用" << endl;
//			delete m_name;
//			m_name = NULL;
//		}
//	}
//
//	string *m_name;
//};
//
//
//
//void test()
//{
//	Animal* animal = new Cat("Tom");
//	animal->speak();
//	//父类指针析构的时候不会调用子类析构函数 子类如果开辟了堆区 会导致内存泄漏
//	delete animal;
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;

//抽象CPU类
class CPU
{
public:
	virtual void calculate() = 0;
};

//抽象显卡类
class VideoCard
{
public:
	virtual void display() = 0;
};

//抽象内存类
class Memory
{
public:
	virtual void storage() = 0;
};


class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

private:

	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;

};

class IntelCpu :public CPU
{
public:
	virtual void calculate()
	{
		cout << "InterCpu开始工作" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "IntelVideoCard开始工作" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "IntelMemory开始工作" << endl;
	}
};

class LenovoCpu :public CPU
{
public:
	virtual void calculate()
	{
		cout << "LenovoCpu开始工作" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "LenovoVideoCard开始工作" << endl;
	}
};

class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "LenovoMemory开始工作" << endl;
	}
};


void test()
{
	cout << "第一台电脑" << endl;
	Computer* p1 = new Computer(new IntelCpu, new IntelVideoCard, new IntelMemory);
	p1->work();

	cout << "第二台电脑" << endl;
	Computer* p2 = new Computer(new LenovoCpu, new IntelVideoCard, new IntelMemory);
	p2->work();

	cout << "第三台电脑" << endl;
	Computer* p3 = new Computer(new LenovoCpu, new LenovoVideoCard, new IntelMemory);
	p3->work();

}

int main()
{
	test();

	system("pause");
	return 0;
}