#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB


//void left_move(char * pr,int  num)
//{
//	int i = 0;
//	int len = strlen(pr);
//	for (i = 0; i < num; i++)
//	{
//		char tmp = *pr;
//		for (int j = 0; j < len; j++)
//		{
//			*(pr + j) = *(pr + j + 1);
//		}
//		*(pr + len - 1) = tmp;
//	}
//}

//void reverse(char * left,char *right)
//{
//	while (left<right)
//	{
//		char tmp = 0;
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char arr[10] = "ABCDEFG";
//	int num = 5;
//	int len = strlen(arr);
//	//left_move(arr,num);
//	//printf("%s", arr);
//	//return 0;
//	reverse(arr,arr+num-1);
//	reverse(arr+num,arr+len-1);
//	reverse(arr,arr+len-1);
//	printf("%s", arr);
//	return 0;
//}

//写一个函数，判断一个字符串是否为另一个字符串旋转之后的字符串


int str_p(char *arr1,char*arr2)
{
	assert(arr1);
	assert(arr2);
	if (strlen(arr1) != strlen(arr2))
	{
		return 0;
	}
	strncat(arr1, arr1, strlen(strlen));
	char* ret = strstr(arr1, arr2);
	return ret !=NULL ;
}

int main()
{
	char arr1[20] = "ABCDEF";
	char arr2[] = "DEFABC";
	int * ret =str_p(arr1, arr2);
	if (ret == 0)
	{
		printf("no");
	}
	else
	{
		printf("yes");
	}
}