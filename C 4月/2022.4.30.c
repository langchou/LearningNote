#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


int main()
{
	//假设开辟10个整形的空间 - 10 * sizeof(int)
	int arr[10];//栈区
	//动态内存开辟的
	//int* p = malloc(10 * sizeof(int));
	int* p = calloc(10 ,sizeof(int));  //相比malloc，会自动初始化
	//使用这些空间的时候
	if (p == NULL)
	{
		printf("error\n");
		return 0;
	}
	//使用
	int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	*(p + i) = i;
	//}
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 5;
	}
	//需要p指向更大的空间，需要20个int的空间

	int *ptr = realloc(p, 20 * sizeof(int));//用临时指针*ptr接收扩容后的地址，以免扩容失败返回空指针
	if (*ptr != NULL) 
	{
		*p = *ptr;
	}

	free(p);
	p = NULL;
	return 0;
}