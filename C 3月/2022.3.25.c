#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "add.h"  
#include "sub.h"
//ͷ�ļ�����



//�����ĵ���
int isprime(int n) //�����ж�
{
	for (int j = 2; j <= sqrt(n); j++)
	{
		if (n % j == 0) {
			return 0;
		}
	}
	return 1;
}

int isleap(int m) //�����ж�
{
	//if (m % 4 == 0 && m % 100 != 0 || m % 400 == 0) {
	//	return 1;
	//}
	//return 0;

	return(m % 4 == 0 && m % 100 != 0 || m % 400 == 0);
}

int binary_search(int a[], int b, int c)  //Ѱ�������±� a[]Ϊ����,bΪ���ҵ�Keyֵ,cΪ���鳤��
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


//���뾲̬��
#pragma comment (lib,"add.lib")
	
//int main()
//{
//	//�ж��Ƿ�������
//	//int i=0;
//	//scanf("%d", &i);
//	//1 == isprime(i) ? printf("%d������",i) : printf("%d��������",i);
//	//return 0;		
//
//	//�ж��Ƿ�������
//	//int i = 0;
//	//scanf("%d", &i);
//	//1 == isleap(i) ? printf("%d������", i) : printf("%d��������", i);
//
//	//Ѱ�������±�
//	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int key = 7;
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//int ret = binary_search(arr, key, sz);
//	//if (-1 == ret)
//	//{
//	//	printf("�Ҳ����±�");
//	//}
//	//else
//	//{
//	//	printf("�и���,�±�Ϊ:%d\n", ret);
//	//}
//	//return 0;
//
//	//int len = strlen("abc");
//	//printf("%d", len);
//	//printf("%d", strlen("abc"));  //��ʽ����
//
//	//	printf("%d", printf("%d",printf("%d", 43)));
//	// ��ӡ��4321���������ص��Ǵ�ӡ����Ļ�ϵ��ַ��ĸ���
//	//int i = 10;
//	//int j = 20;
//	//int Add(int, int); //��������
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
//	main(); //�ݹ� ջ���
//
//	return 0;
//}


//�ݹ�����
//void print(int n)
//{
//	if (n>9)
//	{
//		print(n / 10);   //1234 123 12 1
//
//	}
//	printf("%d,", n % 10); // 1, 12 ,123 ,1234����ȡģ
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
//	while (*str != '\0') // *strȡ��һ����ַ���ַ�
//	{
//		count++; //����
//		str++;  //��ַ+1
//	}
//	return count;
//}


//int my_strlen(char* str)	//�ݹ�ģ��strlen
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

int fac(int i)  //��ѧ�׳� �ݹ�
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