#pragma once 
#include <iostream>

using namespace std;

//������
class Worker
{
public:
	//չʾ������Ϣ
	virtual void ShowInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_Id;//Ա�����
	string m_Name;//Ա������
	int m_DeptId;//ְ�����ڲ������Ʊ��
};