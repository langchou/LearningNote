#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//流：C语言程序运行默认打开3个流
//stdin  - 标准输入流 - 键盘 
//stdout - 标准输出流 - 屏幕 
//stderr - 标准错误流 - 屏幕 


//int main()
//{
//	FILE* pf = fopen("test.dat", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	int ret = fputc("abcdefg", pf);
//
//
//	//关闭文件
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
//	//读文件
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//	fgets(arr, 4, pf);
//	printf("%s\n", arr);
//
//	//关闭文件
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
	//写文件
	fscanf(pf,"%s %d %f",s.arr,&(s.num), &(s.sc));

	printf("%s%d%f\n", s.arr, s.num, s.sc);
	//关文件
	fclose(pf);
	pf == NULL;
	return 0;
}