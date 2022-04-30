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
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	//��data����һ�������Ŀռ��ڶ�����
	//capacity��ʼ��Ϊ��ǰ���������
	InitContact(&con);
	do
	{
		meun();
		printf("������:>");
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
			//����ͨѶ¼
			DestoryContact(&con);
			printf("�˳�\n");
			break;

		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}