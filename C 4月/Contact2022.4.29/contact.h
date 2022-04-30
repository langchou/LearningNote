#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_TELE 12
#define MAX_ADDR 30

#define MAX 1000
#define DEFAULT_SZ 3
#define INC_SZ 2

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


//静态版本
//typedef struct Contact
//{
//	PeoInfo data[MAX];//存放添加的人的信息
//	int sz;//记录有效信息个数
//}Contact;

//动态版本
typedef struct Contact
{
	PeoInfo *data;//存放添加的人的信息
	int sz;//记录有效信息个数
	int capacity;//记录当前通讯录的最大容量
}Contact;



//通讯录初始化
void InitContact(Contact *pc);

//增加联系人
void AddContact(Contact* pc);

//打印通讯录
void PrintContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找联系人
void SearchContact(Contact* pc);

//修改联系人
void ModifyContact(Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);