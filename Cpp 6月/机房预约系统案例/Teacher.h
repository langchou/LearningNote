#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"

/*
  ��ʦ�๦��
  ��ʾ��ʦ�����Ĳ˵�����
  �鿴����ԤԼ
  ���ԤԼ
*/


class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int id, string name, string pwd);
	//չʾ�˵�
	virtual void operMenu();
	//չʾ����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void valiOrder();

	int EmpId;
};