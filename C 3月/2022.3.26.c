#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>

////int fib(int n) //递归斐波那契数列  效率较低
////{
////
////	if (n <= 2)
////	{
////		return 1;
////	}
////	else
////	{
////		return fib(n - 1) + fib(n - 2);
////	}
////
////}
//
////int fib(int n)   //斐波那契数列 不考虑溢出
////{
////	int a = 1;
////	int b = 1;
////	int c = 1;
////	while (n>2)
////	{
////		n--;
////		c = a + b;
////		a = b;
////		b = c;
////	}
////	return c;
////}
////
////int main()
////{
////	int i=0;
////	scanf("%d", &i);
////	int n = fib(i);
////	printf("%d", n);
////}


//int main()
//{
//    int hanoi(int, char, char, char);   //汉诺塔方法声明
//    int n, counter;
//    printf("输入层数：");
//    scanf("%d", &n);
//    printf("\n");
//    counter = hanoi(n, 'A', 'B', 'C');
//    return 0;
//}

//int hanoi(int n, char x, char y, char z)
//{
//    int move(char, int, char); //转移方法声明
//    if (n == 1)
//        move(x, 1, z);
//    else
//    {
//        hanoi(n - 1, x, z, y);  //递归调用，第一轮,将A柱中的N-1层通过C柱，转移到B
//        move(x, n, z);   //第二轮，将A柱中的最底层转移到C柱
//        hanoi(n - 1, y, x, z); //递归调用，第三轮,将B柱中原本的N-1层，通过A柱转移到C柱上
//    }
//    return 0;
//}
//
//int move(char getone, int n, char putone)
//{
//    static int k = 1;
//    printf("%2d:%3d # %c---%c\n", k, n, getone, putone);
//    if (k++ % 3 == 0)
//        printf("\n");
//    return 0;
//}

//1*1=1
//2*1=2 2*2=4
//3*1=3 3*2=6 3*3=9
//void print_table(int n)  //打印乘法口诀表
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%3d*%d=%d ", i,j,(i * j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	print_table(i);
//}


int my_strlen(char* str)
{
	int count=0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}


//void re_string(char* str)  //普通逆序
//{
//	int left = 0;
//	int right = my_strlen(str)-1;
//	char temp;
//	while (left != right)
//	{
//		temp = str[left];
//		str[left] = str[right];
//		str[right] = temp;
//		left++;
//		right--;
//	}
//}

void re_string(char* str) //递归逆序
{
	int len = my_strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (my_strlen(str+1)>=2)
	{
		re_string(str + 1);
	}
		*(str + len - 1) = tmp;
}

int main()
{
	char arr[] = "abcdefg";
	re_string(arr);
	printf("%s", arr);
	return 0;
}