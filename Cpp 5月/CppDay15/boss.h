#pragma once 
#include <iostream>
using namespace std;

#include "worker.h"

class Boss : public Worker
{
public:
	Boss(int id, string name, int dId);
	//չʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};