#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//����C���Գ�������Ĭ�ϴ�3����
//stdin  - ��׼������ - ���� 
//stdout - ��׼����� - ��Ļ 
//stderr - ��׼������ - ��Ļ 


//int main()
//{
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	int ret = fputc("abcdefg", pf);
//
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{	
//	char arr[10] = { 0 };
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ�
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

struct S
{
	char arr[10];
	int num;
	float sc;
};

int main()
{
	struct S s = { "abcdef",10,5.5f };
	FILE *pf = fopen("test1.dat", "r");
	if (NULL == pf)
	{
		perror("fopen");
		return 1;
	}
	//д�ļ�
	fscanf(pf,"%s %d %f",s.arr,&(s.num), &(s.sc));

	printf("%s%d%f\n", s.arr, s.num, s.sc);
	//���ļ�
	fclose(pf);
	pf == NULL;
	return 0;
}