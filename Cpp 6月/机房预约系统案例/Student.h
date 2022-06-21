#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include "Identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"

using namespace std;
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
	vector<computerRoom>vCom;
};