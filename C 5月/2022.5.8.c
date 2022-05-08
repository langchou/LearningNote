#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//流：C语言程序运行默认打开3个流
//stdin  - 标准输入流 - 键盘 
//stdout - 标准输出流 - 屏幕 
//stderr - 标准错误流 - 屏幕 


int main()
{
	FILE* pf = fopen("test.txt","w");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}

	fputc('b', pf);
	fputc('i', pf);
	fputc('t', pf);

	fclose(pf);
	pf = NULL;
	return 0;
}