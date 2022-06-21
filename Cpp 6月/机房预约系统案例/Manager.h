#pragma once
#include<iostream>
#include "Identity.h"
#include"Student.h"
#include"Teacher.h"
#include "globalFile.h"
#include "computerRoom.h"
#include "Student.h"
#include "Teacher.h"
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
/*
- ��ʾ����Ա�����Ĳ˵�����

- ����˺�

- �鿴�˺�

- �鿴������Ϣ

- ���ԤԼ��¼
*/

class Manager :public Identity
{
	public:
	Manager();
	Manager(string name, string pwd);
	//չʾ�˵�
	virtual void operMenu();
	//����˺�  
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();
	//��ʼ������
	void initVector();
	//���ѧ��ʱ����ظ� idΪ��� typeΪ����(ѧ��/��ʦ)
	bool checkRepeat(int id,int type);


	vector<Student>vStudent;
	vector<Teacher>vTeacher;
};