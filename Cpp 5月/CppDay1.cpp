#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//#define �곣��
#define Day 7 
//int main()
//{
//	cout << "һ��һ����" << Day << "��" << endl;
//	
//	//����
//	const int Month = 12;
//	cout << "һ��һ����" << Month << "����" << endl;
//
//		
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//���� ��ͬ��endl
//	cout << "hello world\n";
//	//��б��
//	cout << "\\" << endl;
//	//ˮƽ�Ʊ����
//	cout << "aaaa\t3213" << endl;
//	cout << "aaaaba\t3213" << endl;
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	//C����ַ���
//	char str[] = "Hello World";
//	cout << str << endl;
//	//C++����ַ���
//	string str2 = "Hello World";
//	cout << str2 << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	cout << "������:";
//	cin >> a;
//	cout << "a=" << a << endl;
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	//ϵͳ���������
//	srand(time(NULL));
//	int num = rand() % 100 + 1;
//	cout << num << endl;
//
//	//��Ҳ²�
//	int val = 0;
//	while (1)
//	{
//		cin >> val;
//		if (val > num)
//		{
//			cout << "�²����" << endl;
//		}
//		else if (val < num)
//		{
//			cout << "�²��С" << endl;
//		}
//		else
//		{
//			cout << "�¶���" << endl;
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
//			cout << "������" << endl;
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
//			cout << "������" << endl;
//		}
//		else if (i / 10 % 7 == 0)
//		{
//			cout << "������" << endl;
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

//continue��� ������ѭ��
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
//	cout << "����Ϊ" << max << endl;
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