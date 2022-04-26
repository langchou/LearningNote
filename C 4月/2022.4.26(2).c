/*
	枚举:防止定义污染
*/



#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void menu()
{
	printf("***********************\n");
	printf("***** 1.ADD 2.SUB *****\n");
	printf("***** 3.MUL 4.DIV *****\n");
	printf("*****   0.EXIT    *****\n");
	printf("***********************\n");
}

//声明枚举类型
enum Options   //枚举增加代码可读性
{
	EXIT, // EXIT=0
	ADD,  // ADD=1
	SUB,
	MUL,
	DIV
};

void add()
{
	printf("+\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add();
			break;
		case SUB:
			break;
		case MUL:
			break;
		case DIV:
			break;
		case EXIT:
			break;
		default:
			break;
		}
	} while (input);

}