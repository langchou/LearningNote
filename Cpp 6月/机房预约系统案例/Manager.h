#pragma once
#include "Identity.h"

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
};