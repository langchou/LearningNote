/*
	位段
*/



#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//性别
//00 男
//01 女
//10 保密
//三种情况，只用2个比特位，位段在一定程度上节省了空间

//位段  int,unsigned int,signed int,char
//struct A
//{ 
//	//4个字节 - 32bit
//	int _a : 2; //_a成员占2个比特位
//	int _b : 5; 
//	int _c : 10;
//	//15bit
//	//4个字节 - 32bit
//	int _d : 30;	
//};
//
//
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	return 0;
//}

//字节内部从右向左使用 低位向高位使用 剩余位置会浪费 仅适配VS

struct S
{
	//0|1100|010
	char a : 3; // a放了10即 1010 取后三位
	char b : 4; // b放了12即 1100
	//000|00011
	char c : 5; // c放了3即00011
	//0000|0100
	char d : 4; // d放了4即0100
};
    //01100010 00000011 00000100 
    //--6---2- --0---3- --0--4-- 为内存数据
int main()
{
	struct  S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	return 0;
}



