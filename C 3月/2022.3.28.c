#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//游戏相关函数的实现


//初始化棋盘
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

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]); //打印棋盘空白格
			if(j< col-1)
				printf("|");  //打印空白格旁的竖线
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++) {
				printf("---"); //打印分割符
				if (j < col - 1) 
					printf("|"); //打印分割符行的竖线
			}
			printf("\n");
		}	
	}
}

//玩家下棋
void PlayMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>");
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
				printf("坐标被占用，请重新输入");
			}
		}
		else
		{
			printf("坐标非法,请重新输入");
		}
	}
	
}