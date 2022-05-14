#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//重载 封装

//访问权限
//公有权限 public       成员 类内可以访问 类外可以访问
//保护权限 protected    成员 类内可以访问 类外不能访问 子类可以访问父类的保护内容
//私有权限 private      成员 雷内可以访问 类外不能访问 子类不能访问父类的私有内容

//默认参数必须从右往左开始 
//函数声明有参数 实现不能有参数
//int func(int a,int b = 10,int c = 20)
//{
//	return a + b + c;
//}
//
//void func2(int a, int)
//{
//	cout << "占位参数" << endl;
//}
//
//int main()
//{
//	//缺省参数
//	cout << func(30, 20) << endl;
//	func2(10, 20);
//	
//	
//	system("pause");
//	return 0;
//}

//函数重载
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
//	//访问权限
//	//公共权限
//public:
//	//属性
//	//半径
//	int m_r;
//	
//	//行为
//	//获取圆的周长
//	double calculateZC()
//	{
//		return 2 * PI * m_r;
//	}
//};

//class Student
//{
//
//public: // 公共权限
//
//	//类中的属性和行为 统一称为成员
//
//
//	//属性  --成员属性/成员变量
// 	string Sname; //姓名
//	int Sid; //学号 
//
//	//行为  --成员函数/成员方法
//	//展示姓名学号
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
//		cout << "姓名:" << Sname << " " << "学号:" << Sid << endl;
//
//	}
//
//};

//class Person
//{
//	//共有权限
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
//	//类内可以访问
//	void func()
//	{
//		m_name = "张三";
//		m_car = "拖拉机";
//		m_password = 123456;
//	
//	}
//};

//class Person
//{
//public:
//
//	//设置姓名
//	void setName(string name)
//	{
//		pName = name;
//	}
//	//获取姓名
//	string getName()
//	{
//		return pName;
//	}
//
//
//	//设置年龄
//	void setAge(int age)
//	{
//		//判断有效性
//		if (age < 0 || age >150)
//		{
//			pAge = 0;
//			cout << "年龄有误" << endl;
//			return;
//		}
//		pAge = age;
//	}
//
//	//获取年龄
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
//	p1.setName("张三");
//	cout << "姓名为: " << p1.getName() << endl;
//	p1.setAge(151);
//	cout << "年龄为: " << p1.getAge() << endl;
//
//}

//int main()
//{
//	//通过圆类 创建具体的圆（对象）
//	//实例化
//	//Circle c1;
//	//给圆对象 的属性赋值
//	//c1.m_r = 10;
//
//	//cout << "圆的周长为" << c1.calculateZC() << endl;
//	//func(3.0,10);
//	//func(10);
//	//func(10,3.0);
//	//func1(10);  // 函数重载出现二义性
//
//	//实例化
//	Person p1;
//
////	p1.m_name = "李四";
////	p1.m_car = "奔驰"; //保护权限在，类外访问不到
////	p1.m_password = "1234";  //私有权限内容，类外访问不到
//
////	Student s1;
//	//s1.Sname = "张三";
//	s1.setName("张三");
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

	int m_x;//横坐标

	int m_y;//纵坐标

};

class Circle
{
public:
	//设置半径
	void setr(int r)
	{
		m_r = r;
	}
	//获取半径
	int getr()
	{
		return m_r;
	}
	//设置圆心
	void setcenter(Point center)
	{
		m_center = center;
	}
	//获取圆心
	Point getcenter()
	{
		return m_center;
	}

private:

	int m_r;//半径

	Point m_center;//圆心
};


//判断方法
void isInCircle( Circle c, Point p)
{
	//两点之间距离的平方
	double distance = pow(c.getcenter().getx() - p.getx(), 2) + pow(c.getcenter().gety() - p.gety(), 2);
		
	//半径的平方
	double r_distance = pow(c.getr(), 2);
	
	if (distance > r_distance)
	{
		cout << "在圆外" << endl;
	}
	else if(distance == r_distance)
	{
		cout << "在圆上" << endl;
	}
	else
	{
		cout << "在圆内" << endl;
	}


}



int main()
{
	Point center; //创建圆心
	//设置圆心坐标 
	center.setx(10); 
	center.sety(0);

	//创建圆
	Circle c;

	c.setr(10);//创建半径
	c.setcenter(center);

	//创建点
	Point p;
	p.setx(10);
	p.sety(10);

	//判断圆、点的位置关系
	isInCircle(c, p);
	system("pause");
	return 0;
}