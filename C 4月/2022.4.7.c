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
//	//��Ա����
//	struct B sb;
//	char name[20]; //����
//	int age; //����
//	char id[20];  //ѧ��
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
//	struct Stu s = { {'w',20,3.14},"����",20,"9521" };
//	struct Stu* ps = &s;
//	print1(s);   //��ֵ����
//	print2(&s);  //��ַ����
//	printf("%c\n", s.sb.c);
//	printf("%c\n", ps->sb.c);
//	return 0;
//}



//int main()
//{
//	int i = 0;       
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };    //i��arr�Ǿֲ�����,����ջ����ջ�ڴ�ʹ��ϰ���ǣ���ʹ�øߵ�ַ�ռ䣬��ʹ�õ͵�ַ�ռ�
//	for (i = 0; i <= 15; i++)					//���������±����������ַ�ɵ͵��߱仯
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
	while (*dest++ = *src++)     // '\0'��ascii��ֵΪ0,������copy������ֹͣ
	{
		;
	}

}


//ģ��ʵ��strcpy - �ַ�������
int main()
{
	char arr1[20] = "xxxxxxxxxxxxxx";
	char arr2[] = "hello";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
}