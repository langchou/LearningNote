#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "add.h"  
#include "sub.h"
//头文件引用



//函数的调用
int isprime(int n) //素数判断
{
	for (int j = 2; j <= sqrt(n); j++)
	{
		if (n % j == 0) {
			return 0;
		}
	}
	return 1;
}

int isleap(int m) //闰年判断
{
	//if (m % 4 == 0 && m % 100 != 0 || m % 400 == 0) {
	//	return 1;
	//}
	//return 0;

	return(m % 4 == 0 && m % 100 != 0 || m % 400 == 0);
}

int binary_search(int a[], int b, int c)  //寻找数组下标 a[]为数组,b为查找的Key值,c为数组长度
{
	int left = 0;
	int right = c - 1;


	while (left <= right)
	{

		int mid = (left + right) / 2;
		if (a[mid] > b)
		{
			right = mid - 1;
		}
		else if (a[mid] < b)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}


//导入静态库
#pragma comment (lib,"add.lib")
	
//int main()
//{
//	//判断是否是素数
//	//int i=0;
//	//scanf("%d", &i);
//	//1 == isprime(i) ? printf("%d是素数",i) : printf("%d不是素数",i);
//	//return 0;		
//
//	//判断是否是闰年
//	//int i = 0;
//	//scanf("%d", &i);
//	//1 == isleap(i) ? printf("%d是闰年", i) : printf("%d不是闰年", i);
//
//	//寻找数组下标
//	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int key = 7;
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//int ret = binary_search(arr, key, sz);
//	//if (-1 == ret)
//	//{
//	//	printf("找不到下标");
//	//}
//	//else
//	//{
//	//	printf("有该数,下标为:%d\n", ret);
//	//}
//	//return 0;
//
//	//int len = strlen("abc");
//	//printf("%d", len);
//	//printf("%d", strlen("abc"));  //链式访问
//
//	//	printf("%d", printf("%d",printf("%d", 43)));
//	// 打印得4321，函数返回的是打印在屏幕上的字符的个数
//	//int i = 10;
//	//int j = 20;
//	//int Add(int, int); //函数声明
//	//int sum = Add(i, j);
//	//printf("%d", sum);
//
//	int i = 10;
//	int j = 20;
//	//int sum = Sub(i, j);
//	int sum = Add(i, j);
//	printf("%d", sum);
//	return 0;
//}

//int Add(int x, int y) {
//	return x + y;
//}

//int main()
//{
//
//	printf("hehe\n");
//	main(); //递归 栈溢出
//
//	return 0;
//}


//递归运用
//void print(int n)
//{
//	if (n>9)
//	{
//		print(n / 10);   //1234 123 12 1
//
//	}
//	printf("%d,", n % 10); // 1, 12 ,123 ,1234依次取模
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num); //1234
//	print(num);
//	return 0;
//}

//int my_strlen(char* str)
//{
//	int count=0;
//	while (*str != '\0') // *str取下一个地址的字符
//	{
//		count++; //计数
//		str++;  //地址+1
//	}
//	return count;
//}


//int my_strlen(char* str)	//递归模拟strlen
//{
//
//	if (*str != '\0')
//		return 1 + my_strlen(str +1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "bit";
//	printf("%d\n", my_strlen(arr));
//
//	return 0;
//
// }

int fac(int i)  //数学阶乘 递归
{
	if (i == 1)
		return 1;
	else
		return i * fac(i - 1);
}

int main()
{
	int i = 0;
	scanf("%d", &i);
	int ret = fac(i);
	printf("%d", ret);
}