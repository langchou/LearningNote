#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//struct B
//{
//	char c;
//	short s;
//	double d;
//};
//struct Stu
//{
//	//成员变量
//	struct B sb;
//	char name[20]; //名字
//	int age; //年龄
//	char id[20];  //学号
//};
//
//void print1(struct Stu t)
//{
//	printf("%c %d %lf %s %d %s\n", t.sb.c, t.sb.s, t.sb.d, t.name, t.age, t.id);
//}
//void print2(struct Stu* ps)
//{
//	printf("%c %d %lf %s %d %s\n", ps->sb.c, ps->sb.s, ps->sb.d, ps->name, ps->age, ps->id);
//}
//
//int main()
//{
//	struct Stu s = { {'w',20,3.14},"张三",20,"9521" };
//	struct Stu* ps = &s;
//	print1(s);   //传值调用
//	print2(&s);  //传址调用
//	printf("%c\n", s.sb.c);
//	printf("%c\n", ps->sb.c);
//	return 0;
//}



//int main()
//{
//	int i = 0;       
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };    //i和arr是局部变量,放在栈区。栈内存使用习惯是，先使用高地址空间，再使用低地址空间
//	for (i = 0; i <= 15; i++)					//数组随着下表的增长，地址由低到高变化
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//
//	return 0;
//}

//void my_strcpy(char *dest ,char * src)
//{
//	while (* src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//}
//void my_strcpy(char* dest, char* src)
//{
//	while (* src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//}
void my_strcpy(char* dest, char* src)
{
	while (*dest++ = *src++)     // '\0'的ascii码值为0,既做到copy又做到停止
	{
		;
	}

}


//模拟实现strcpy - 字符串拷贝
int main()
{
	char arr1[20] = "xxxxxxxxxxxxxx";
	char arr2[] = "hello";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
}