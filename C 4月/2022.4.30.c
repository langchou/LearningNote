#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


int main()
{
	//���迪��10�����εĿռ� - 10 * sizeof(int)
	int arr[10];//ջ��
	//��̬�ڴ濪�ٵ�
	//int* p = malloc(10 * sizeof(int));
	int* p = calloc(10 ,sizeof(int));  //���malloc�����Զ���ʼ��
	//ʹ����Щ�ռ��ʱ��
	if (p == NULL)
	{
		printf("error\n");
		return 0;
	}
	//ʹ��
	int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	*(p + i) = i;
	//}
	for (i = 0; i < 10; i++)
	{
		*(p + i) = 5;
	}
	//��Ҫpָ�����Ŀռ䣬��Ҫ20��int�Ŀռ�

	int *ptr = realloc(p, 20 * sizeof(int));//����ʱָ��*ptr�������ݺ�ĵ�ַ����������ʧ�ܷ��ؿ�ָ��
	if (*ptr != NULL) 
	{
		*p = *ptr;
	}

	free(p);
	p = NULL;
	return 0;
}