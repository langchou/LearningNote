/*
	λ��
*/



#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//�Ա�
//00 ��
//01 Ů
//10 ����
//���������ֻ��2������λ��λ����һ���̶��Ͻ�ʡ�˿ռ�

//λ��  int,unsigned int,signed int,char
//struct A
//{ 
//	//4���ֽ� - 32bit
//	int _a : 2; //_a��Առ2������λ
//	int _b : 5; 
//	int _c : 10;
//	//15bit
//	//4���ֽ� - 32bit
//	int _d : 30;	
//};
//
//
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	return 0;
//}

//�ֽ��ڲ���������ʹ�� ��λ���λʹ�� ʣ��λ�û��˷� ������VS

struct S
{
	//0|1100|010
	char a : 3; // a����10�� 1010 ȡ����λ
	char b : 4; // b����12�� 1100
	//000|00011
	char c : 5; // c����3��00011
	//0000|0100
	char d : 4; // d����4��0100
};
    //01100010 00000011 00000100 
    //--6---2- --0---3- --0--4-- Ϊ�ڴ�����
int main()
{
	struct  S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	return 0;
}



