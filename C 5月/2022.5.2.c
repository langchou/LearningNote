#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//柔性数组
//struct S
//{
//	int n;//4
//	int arr[0];//大小是未知
//};
//
//int main()
//{
//	//期望arr的大小是10个整形
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	ps->n = 10;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
// free(ps);
// ps = NULL;
//}
struct S
{
	int n;//4
	int* arr;//大小是未知
};

//频繁的malloc会增加内存碎片，效率不如柔性数组
int main()
{
	//期望arr的大小是10个整形
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	if (ps == NULL)
		return 1;
	ps->n = 10;
	ps->arr = (int*)malloc(10*sizeof(int));
	int* ptr = realloc(ps->arr, 20 * sizeof(int));
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}