#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"

/*
  ѧ���๦��
  ��ʾѧ�������Ĳ˵�����
  ����ԤԼ
  �鿴����ԤԼ
  �鿴����ԤԼ
  ȡ��ԤԼ
*/


class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);
	//չʾ�˵�
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//չʾ�Լ�ԤԼ
	void showMyOrder();
	//չʾ����ԤԼ
	void showAllOrder(); 
	//ȡ��ԤԼ
	void cancelOrder();

	int Id;
};