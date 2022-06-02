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
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ��
	void Show_Emp();
	//�޸�ְ����Ϣ
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����ְ��
	void Sort_Emp();
	//ְ���Ƿ����
	int IsExist(int id);
	//ɾ��ְ��
	void Del_Emp();
	//�ļ�����
	void save();
	//����ļ�
	void Clean_File();
	//ְ����������
	Worker** m_EmpArray;
	//��������
	~WorkerManager();

	//ͳ������
	int get_EmpNum();
	//��¼�ļ��е���������
	int m_EmpNum;
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

};