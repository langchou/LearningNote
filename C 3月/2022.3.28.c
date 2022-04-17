#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//��Ϸ��غ�����ʵ��


//��ʼ������
void InitBoard(char board[ROW][COL], int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = '\0';
		}
	}
}

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]); //��ӡ���̿հ׸�
			if(j< col-1)
				printf("|");  //��ӡ�հ׸��Ե�����
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++) {
				printf("---"); //��ӡ�ָ��
				if (j < col - 1) 
					printf("|"); //��ӡ�ָ���е�����
			}
			printf("\n");
		}	
	}
}

//�������
void PlayMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>");
	scanf("%d%d", &x, &y);
	while (1)
	{
		if (x >= 1 && x <= row || y >= 1 && y <= col)
		{
			if (board[x-1][y-1] == '\0')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������");
			}
		}
		else
		{
			printf("����Ƿ�,����������");
		}
	}
	
}