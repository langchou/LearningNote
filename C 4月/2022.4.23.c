#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

// 12345678910
//   12345
void* my_memmove(void * dest,const void* src,size_t num)
{
	assert(dest && src);
	void* ret = dest;
	//从前向后拷贝
	if (dest < src)  
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	//从后向前拷贝
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}
//匿名结构体类型
struct
{
	int i;
	char a;
	double d;
}s;
//匿名结构体类型指针
struct
{
	int i;
	char a;
	double d;
}*ps;

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr1, arr1+2, 20);
	return 0;
}