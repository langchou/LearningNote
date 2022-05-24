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
//		cout << "Animal�������" << endl;
//	}
//
//	//������
//	//virtual ~Animal()
//	//{
//	//	cout << "Animal����������" << endl;
//	//}
//
//	//��������
//	virtual ~Animal() = 0;
//
//	
//	virtual void speak() = 0;
//
//};
//Animal::~Animal()
//{
//	cout << "Animal������������" << endl;
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
//		cout << "cat�������" << endl;
//		m_name = new string(name);
//	}
//
//	void speak()
//	{
//		cout<< *m_name << "Сè��˵��" << endl;
//	}
//
//	~Cat()
//	{
//		if (m_name != NULL)
//		{
//			cout << "Cat��������" << endl;
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
//	//����ָ��������ʱ�򲻻���������������� ������������˶��� �ᵼ���ڴ�й©
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

//����CPU��
class CPU
{
public:
	virtual void calculate() = 0;
};

//�����Կ���
class VideoCard
{
public:
	virtual void display() = 0;
};

//�����ڴ���
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
		cout << "InterCpu��ʼ����" << endl;
	}
};

class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "IntelVideoCard��ʼ����" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "IntelMemory��ʼ����" << endl;
	}
};

class LenovoCpu :public CPU
{
public:
	virtual void calculate()
	{
		cout << "LenovoCpu��ʼ����" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "LenovoVideoCard��ʼ����" << endl;
	}
};

class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "LenovoMemory��ʼ����" << endl;
	}
};


void test()
{
	cout << "��һ̨����" << endl;
	Computer* p1 = new Computer(new IntelCpu, new IntelVideoCard, new IntelMemory);
	p1->work();

	cout << "�ڶ�̨����" << endl;
	Computer* p2 = new Computer(new LenovoCpu, new IntelVideoCard, new IntelMemory);
	p2->work();

	cout << "����̨����" << endl;
	Computer* p3 = new Computer(new LenovoCpu, new LenovoVideoCard, new IntelMemory);
	p3->work();

}

int main()
{
	test();

	system("pause");
	return 0;
}