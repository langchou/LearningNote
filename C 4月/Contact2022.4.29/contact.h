#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_TELE 12
#define MAX_ADDR 30


#define MAX 1000


typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;



typedef struct Contact
{
	PeoInfo data[MAX];//�����ӵ��˵���Ϣ
	int sz;//��¼��Ч��Ϣ����
}Contact;

//ͨѶ¼��ʼ��
void InitContact(Contact *pc);

//������ϵ��
void AddContact(Contact* pc);

//��ӡͨѶ¼
void PrintContact(Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SearchContact(Contact* pc);

//�޸���ϵ��
void ModifyContact(Contact* pc);

