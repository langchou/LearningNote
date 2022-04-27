#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
	联合/共用体
*/

union Un
{
	int i;
	char c;
};


int main()
{
	union Un un;
	printf("%p\n", &un);    //共用同一块内存空间，一个联合体大小至少是最大的成员变量的大小
	printf("%p\n", &un.i);
	printf("%p\n", &un.c);
	printf("%d\n", sizeof(un));  //4
	printf("%d\n", sizeof(un.c)); // 1
	printf("%d\n", sizeof(un.i)); // 4

	return 0;
}