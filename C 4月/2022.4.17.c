#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int(*pf1)(int, int) = Add;   //����ָ��
//	int(*pf2)(int, int) = Sub;
//	int(*pfArr[2])(int, int) = {Add,Sub}; //����ָ������
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

int Calc(int(*pr)(int ,int))   //�ص�����,����Ϊ����ָ��
{
	int x = 0;
	int y = 0;
	printf("��������:\n");
	scanf("%d %d", &x, &y);
	return pr(x, y);
}
//int main()
//{
//	int ret = 0;
//	int input = 0;
//	menu();
//	printf("���������\n");
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
//		printf("�˳�\n");
//		break;
//	default:
//		printf("��������\n");
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
//		//ת�Ʊ��
//		int(*pfArr[5])(int, int) = { NULL,Add,Sub,Mul,Div };
//		int i = 0;
//		int j = 0;
//		int ret = 0;
//		printf("���������:\n");
//		scanf("%d", &input);
//
//		if (input >= 1 && input <= 4)
//		{
//			printf("���������\n");
//			scanf("%d %d", &i, &j);
//			ret = (pfArr[input])(i, j);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�����\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}  while (input);
//	
//	return 0;
//}


int bobsort(int arr[], int sz)
{
	int i = 0;
	//����
	for (i = 0; i < sz-1; i++)
	{
		//һ��
		int j = 0;
		for (j = 0; j < sz -1- i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//����
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


//void qsort (void* base,								��Ŵ��������ݵ�һ������ĵ�ַ
//			  size_t num,								Ԫ�صĸ���
//			  size_t size,								Ԫ�ش�С����λ�ֽ�
//            int (*cmp)(const void*, const void*)		�Ƚϴ����������е�����Ԫ�صĺ���
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
//��������
int cmp_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
//��������
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


//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
//���д�����������ľ����в���ĳ�������Ƿ����
//ʱ�临�Ӷ�С��O(N)
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
	int x = 3; //��
	int y = 3; //��
		
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int ret = find_num(arr,&x,&y,key);
	if (ret == 1)
	{
		printf("�ҵ���,����Ϊ:%d,%d\n",x,y);
	}
	else
	{
		printf("û�ҵ�\n");
	}
	return 0;
}