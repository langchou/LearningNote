#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//#define 宏常量
#define Day 7 
//int main()
//{
//	cout << "一周一共有" << Day << "天" << endl;
//	
//	//常量
//	const int Month = 12;
//	cout << "一年一共有" << Month << "个月" << endl;
//
//		
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//换行 等同于endl
//	cout << "hello world\n";
//	//反斜杠
//	cout << "\\" << endl;
//	//水平制表符号
//	cout << "aaaa\t3213" << endl;
//	cout << "aaaaba\t3213" << endl;
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//C风格字符串
//	char str[] = "Hello World";
//	cout << str << endl;
//	//C++风格字符串
//	string str2 = "Hello World";
//	cout << str2 << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	cout << "请输入:";
//	cin >> a;
//	cout << "a=" << a << endl;
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	//系统生成随机数
//	srand(time(NULL));
//	int num = rand() % 100 + 1;
//	cout << num << endl;
//
//	//玩家猜测
//	int val = 0;
//	while (1)
//	{
//		cin >> val;
//		if (val > num)
//		{
//			cout << "猜测过大" << endl;
//		}
//		else if (val < num)
//		{
//			cout << "猜测过小" << endl;
//		}
//		else
//		{
//			cout << "猜对了" << endl;
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int i = 100;
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int sum=0;
//	do
//	{
//		a = i % 10;
//		b = i / 10 % 10;
//		c = i / 100 % 10;
//		sum = (pow(a, 3) + pow(b, 3) + pow(c, 3));
//		if (sum == i)
//		{
//			cout << sum << endl;
//		}
//		i++;
//	} while (i<1000 && i>100);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	for (i = 1; i < 10; i++)
//	{
//		if (i % 7 == 0)
//		{
//			cout << "敲桌子" << endl;
//		}
//		else
//		{
//			cout << i << endl;
//		}
//	}
//	for (i=10; i < 100; i++)
//	{
//		if (i % 7 == 0)
//		{
//			cout << "敲桌子" << endl;
//		}
//		else if (i / 10 % 7 == 0)
//		{
//			cout << "敲桌子" << endl;
//		}
//		else
//		{
//			cout << i << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//
//int main()
//{
//	int i = 1;
//	int j = 1;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			cout <<" " << i << " x " << j << " = " << i * j;
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}

//continue语句 不跳出循环
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 100; i++)
//	{
//		if (i % 2 == 0)
//		{
//			continue;
//		}
//		cout << i << endl;
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[5] = { 300,350,200,400,250 };
//	int max =0;
//	for (int i = 0;i < 5; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}	
//	}
//	cout << "最重为" << max << endl;
//	system("pause");
//	return 0;
//}

int main()
{
	int arr[5] = { 4,5,2,3,1 };
	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;
	for (; start != end; start++, end--)
	{
		int temp = 0;
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
	}
	system("pause");
	return 0;
}