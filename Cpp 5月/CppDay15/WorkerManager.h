#pragma once //��ֹͷ�ļ��ظ�����
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//չʾ�˵�
	void ShowMenu();
	//�˳�����
	void ExitSystem();
	//���ְ��
	void Add_Emp();
	//�ļ�����
	void save();
	//ְ����������
	Worker** m_EmpArray;
	//��������
	~WorkerManager();



	//��¼�ļ��е���������
	int m_EmpNum;
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

};