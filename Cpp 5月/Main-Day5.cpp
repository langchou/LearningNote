#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//���� ��װ

//����Ȩ��
//����Ȩ�� public       ��Ա ���ڿ��Է��� ������Է���
//����Ȩ�� protected    ��Ա ���ڿ��Է��� ���ⲻ�ܷ��� ������Է��ʸ���ı�������
//˽��Ȩ�� private      ��Ա ���ڿ��Է��� ���ⲻ�ܷ��� ���಻�ܷ��ʸ����˽������

//Ĭ�ϲ��������������ʼ 
//���������в��� ʵ�ֲ����в���
//int func(int a,int b = 10,int c = 20)
//{
//	return a + b + c;
//}
//
//void func2(int a, int)
//{
//	cout << "ռλ����" << endl;
//}
//
//int main()
//{
//	//ȱʡ����
//	cout << func(30, 20) << endl;
//	func2(10, 20);
//	
//	
//	system("pause");
//	return 0;
//}

//��������
//void func(int a, double b)
//{
//	cout << "int,double" << endl;
//}
//
//void func(double a, int b)
//{
//	cout << "double,int" << endl;
//}
//
//void func(int a)
//{
//	cout << "int" << endl;
//}
//
//void func1(int a)
//{
//	cout << "int a" << endl;
//}
//
//void func1(int a,int b = 10)
//{
//	cout << "int a , int b" << endl;
//}

//class Circle
//{
//	//����Ȩ��
//	//����Ȩ��
//public:
//	//����
//	//�뾶
//	int m_r;
//	
//	//��Ϊ
//	//��ȡԲ���ܳ�
//	double calculateZC()
//	{
//		return 2 * PI * m_r;
//	}
//};

//class Student
//{
//
//public: // ����Ȩ��
//
//	//���е����Ժ���Ϊ ͳһ��Ϊ��Ա
//
//
//	//����  --��Ա����/��Ա����
// 	string Sname; //����
//	int Sid; //ѧ�� 
//
//	//��Ϊ  --��Ա����/��Ա����
//	//չʾ����ѧ��
//
//	void setName(string name)
//	{
//		Sname = name;
//	}
//
//	void setId(int id)
//	{
//		Sid = id;
//	}
//
//	void showStudent()
//	{
//		cout << "����:" << Sname << " " << "ѧ��:" << Sid << endl;
//
//	}
//
//};

//class Person
//{
//	//����Ȩ��
//public:
//	string m_name;
//
//protected:
//	string m_car;
//
//private:
//	int m_password;
//
//public:
//
//	//���ڿ��Է���
//	void func()
//	{
//		m_name = "����";
//		m_car = "������";
//		m_password = 123456;
//	
//	}
//};

//class Person
//{
//public:
//
//	//��������
//	void setName(string name)
//	{
//		pName = name;
//	}
//	//��ȡ����
//	string getName()
//	{
//		return pName;
//	}
//
//
//	//��������
//	void setAge(int age)
//	{
//		//�ж���Ч��
//		if (age < 0 || age >150)
//		{
//			pAge = 0;
//			cout << "��������" << endl;
//			return;
//		}
//		pAge = age;
//	}
//
//	//��ȡ����
//	int getAge()
//	{
//		return pAge;
//	}
//
//private:
//	string pName;  
//	int pAge;      
//	int pId;       
//};

//int main()
//{
//
//	Person p1;
//	p1.setName("����");
//	cout << "����Ϊ: " << p1.getName() << endl;
//	p1.setAge(151);
//	cout << "����Ϊ: " << p1.getAge() << endl;
//
//}

//int main()
//{
//	//ͨ��Բ�� ���������Բ������
//	//ʵ����
//	//Circle c1;
//	//��Բ���� �����Ը�ֵ
//	//c1.m_r = 10;
//
//	//cout << "Բ���ܳ�Ϊ" << c1.calculateZC() << endl;
//	//func(3.0,10);
//	//func(10);
//	//func(10,3.0);
//	//func1(10);  // �������س��ֶ�����
//
//	//ʵ����
//	Person p1;
//
////	p1.m_name = "����";
////	p1.m_car = "����"; //����Ȩ���ڣ�������ʲ���
////	p1.m_password = "1234";  //˽��Ȩ�����ݣ�������ʲ���
//
////	Student s1;
//	//s1.Sname = "����";
//	s1.setName("����");
//	//s1.id = 1;
//	s1.setId(1);
//	s1.showStudent();
//	system("pause");
//	return 0;
//}



class Point
{
public:
	void setx(int x)
	{
		m_x = x;
	}

	int getx()
	{
		return m_x;
	}

	void sety(int y)
	{
		m_y = y;
	}

	int gety()
	{
		return m_y;
	}
private:

	int m_x;//������

	int m_y;//������

};

class Circle
{
public:
	//���ð뾶
	void setr(int r)
	{
		m_r = r;
	}
	//��ȡ�뾶
	int getr()
	{
		return m_r;
	}
	//����Բ��
	void setcenter(Point center)
	{
		m_center = center;
	}
	//��ȡԲ��
	Point getcenter()
	{
		return m_center;
	}

private:

	int m_r;//�뾶

	Point m_center;//Բ��
};


//�жϷ���
void isInCircle( Circle c, Point p)
{
	//����֮������ƽ��
	double distance = pow(c.getcenter().getx() - p.getx(), 2) + pow(c.getcenter().gety() - p.gety(), 2);
		
	//�뾶��ƽ��
	double r_distance = pow(c.getr(), 2);
	
	if (distance > r_distance)
	{
		cout << "��Բ��" << endl;
	}
	else if(distance == r_distance)
	{
		cout << "��Բ��" << endl;
	}
	else
	{
		cout << "��Բ��" << endl;
	}


}



int main()
{
	Point center; //����Բ��
	//����Բ������ 
	center.setx(10); 
	center.sety(0);

	//����Բ
	Circle c;

	c.setr(10);//�����뾶
	c.setcenter(center);

	//������
	Point p;
	p.setx(10);
	p.sety(10);

	//�ж�Բ�����λ�ù�ϵ
	isInCircle(c, p);
	system("pause");
	return 0;
}