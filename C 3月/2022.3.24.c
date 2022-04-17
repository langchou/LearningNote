#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//结构体和指针初使用
// 
// 
//void swap1(int x, int y) {
//	int z = x;
//	x = y;
//	y = z;
//}

int get_max(int x, int y) {
	int max;
	if (x >= y) {
		max = x;
	}
	else {
		max = y;
	}
	return max;
}
void swap2(int* pa, int* pb) {
	int z = *pa;
	*pa = *pb;
	*pb = z;
}

int main()
{
	int a = 10;
	int b = 20;
	int max = get_max(a, b);
	printf("较大数字为:%d", max);
	printf("第一次%d,%d", a, b);
	swap(&a, &b);
	printf("第二次%d,%d", a, b);

}