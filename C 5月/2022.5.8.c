#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//����C���Գ�������Ĭ�ϴ�3����
//stdin  - ��׼������ - ���� 
//stdout - ��׼����� - ��Ļ 
//stderr - ��׼������ - ��Ļ 


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