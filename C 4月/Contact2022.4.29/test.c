#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void meun()
{
	printf("***************************************\n");
	printf("*****        1.add     2.del      *****\n");
	printf("*****        3.search  4.modify   *****\n");
	printf("*****        5.sort    6.print    *****\n");
	printf("*****             0.exit          *****\n");
	printf("***************************************\n");
}


enum Options
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

int main()
{
	int input = 0;
	//创建通讯录
	Contact con;
	//初始化通讯录
	//给data申请一块连续的空间在堆区上
	//capacity初始化为当前的最大容量
	InitContact(&con);
	do
	{
		meun();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case EXIT:
			//销毁通讯录
			DestoryContact(&con);
			printf("退出\n");
			break;

		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}