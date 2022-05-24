#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//写文件

void test01()
{
	//创建流对象
	fstream ofs;

	//指定打开方式
	ofs.open("test.txt", ios::out);

	//写内容
	ofs << "姓名:张三" << endl;
	ofs << "性别:男" << endl;
	ofs << "年龄:18" << endl;

	//关闭文件
	ofs.close();
}


//读文件

void test02()
{
	//创建流对象
	fstream ifs;
	//打开方式
	ifs.open("test.txt", ios::in);
	//判断是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读数据
	//1.
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}
	//2.
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//3.
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	//4.
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	//关闭文件
	ifs.close();
}
int main()
{
	test02();
	system("pause");
	return 0;
}
