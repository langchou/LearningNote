#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
	����/������
*/

union Un
{
	int i;
	char c;
};


int main()
{
	union Un un;
	printf("%p\n", &un);    //����ͬһ���ڴ�ռ䣬һ���������С���������ĳ�Ա�����Ĵ�С
	printf("%p\n", &un.i);
	printf("%p\n", &un.c);
	printf("%d\n", sizeof(un));  //4
	printf("%d\n", sizeof(un.c)); // 1
	printf("%d\n", sizeof(un.i)); // 4

	return 0;
}