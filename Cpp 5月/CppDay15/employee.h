#pragma once 
#include <iostream>
using namespace std;

#include "worker.h"

class Emplyee : public Worker
{
public:
	//���캯��
	Emplyee(int id, string name, int dId);
	//չʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string getDeptName() ;
};