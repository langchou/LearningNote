#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int(*pf1)(int, int) = Add;   //函数指针
//	int(*pf2)(int, int) = Sub;
//	int(*pfArr[2])(int, int) = {Add,Sub}; //函数指针数组
//
//	return 0;
//}

void menu()
{
	printf("1.add 2.sub 3.mul 4.div 0.exit\n");
}

int Add(int i, int j)
{
	return i + j;
}
int Sub(int i, int j)
{
	return i - j;
}
int Mul(int i, int j)
{
	return i * j;
}
int Div(int i, int j)
{
	return i / j;
}

int Calc(int(*pr)(int ,int))   //回调函数,参数为函数指针
{
	int x = 0;
	int y = 0;
	printf("输入数字:\n");
	scanf("%d %d", &x, &y);
	return pr(x, y);
}
//int main()
//{
//	int ret = 0;
//	int input = 0;
//	menu();
//	printf("输入操作数\n");
//	scanf("%d", &input);
//	switch (input)
//	{
//	case 1:
//		ret = Calc(Add);
//		printf("%d", ret);
//		break;
//	case 2:
//		ret = Calc(Sub);
//		printf("%d", ret);
//		break;
//	case 3:
//		ret = Calc(Mul);
//		printf("%d", ret);
//		break;
//	case 4:
//		ret = Calc(Div);
//		printf("%d", ret);
//		break;
//	case 0:
//		printf("退出\n");
//		break;
//	default:
//		printf("输入有误\n");
//		break;
//	}	
//}


//int main()
//{
//	int input = 0;
//	do
//	{
//		
//		menu();
//		//转移表↓
//		int(*pfArr[5])(int, int) = { NULL,Add,Sub,Mul,Div };
//		int i = 0;
//		int j = 0;
//		int ret = 0;
//		printf("请输入操作:\n");
//		scanf("%d", &input);
//
//		if (input >= 1 && input <= 4)
//		{
//			printf("输入操作数\n");
//			scanf("%d %d", &i, &j);
//			ret = (pfArr[input])(i, j);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出程序\n");
//			break;
//		}
//		else
//		{
//			printf("输入错误\n");
//		}
//	}  while (input);
//	
//	return 0;
//}


int bobsort(int arr[], int sz)
{
	int i = 0;
	//趟数
	for (i = 0; i < sz-1; i++)
	{
		//一趟
		int j = 0;
		for (j = 0; j < sz -1- i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//int main()
//{
//	int arr[10] = { 9,8,5,6,7,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bobsort(arr, sz); 
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}


//void qsort (void* base,								存放待排序数据第一个对象的地址
//			  size_t num,								元素的个数
//			  size_t size,								元素大小，单位字节
//            int (*cmp)(const void*, const void*)		比较待排序数据中的两个元素的函数
//			  );
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void printf_arr(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9,8,5,6,7,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	printf_arr(arr, sz);
//}

struct Stu
{
	char name[20];
	int age;	
};
//年龄排序
int cmp_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
//名字排序
int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name , ((struct Stu*)e2)->name);
}

void test1()
{
	struct Stu s[3] = { {"zhangsan",50},{"lisi",40},{"wangwu",30}};
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]),cmp_age);
}
void test2()
{
	struct Stu s[3] = { {"zhangsan",50},{"lisi",40},{"wangwu",30}};
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]),cmp_name);
}



//int main()
//{
////	test1();
//	test2();
//	return 0;
//}


//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的
//请编写程序在这样的矩阵中查找某个数字是否存在
//时间复杂度小于O(N)
//   c  
//r  1 2 3
//   4 5 6
//   7 8 9

int find_num(int arr[3][3],int *px,int *py,int key)
{
	int x = 0; 
	int y = *py - 1;
	while (x<*px && y>=0)
	{
		if (key > arr[x][y])
		{
			x++;
		}
		else if (key < arr[x][y])
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int key = 7;
	int x = 3; //行
	int y = 3; //列
		
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int ret = find_num(arr,&x,&y,key);
	if (ret == 1)
	{
		printf("找到了,坐标为:%d,%d\n",x,y);
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}