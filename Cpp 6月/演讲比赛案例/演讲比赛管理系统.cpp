#define _CRT_SECURE_NO_WARNINGS
using namespace std; 
#include "SpeechManager.h"

/*
* ѧУ����һ���ݽ�����������**12����**�μӡ�**����������**����һ��Ϊ��̭�����ڶ���Ϊ������
* ������ʽ��**���������ÿ��6����**��ѡ��ÿ��Ҫ������飬���б���
* ÿ��ѡ�ֶ��ж�Ӧ��**���**���� 10001 ~ 10012
* ��һ�ַ�Ϊ����С�飬ÿ��6���ˡ� ���尴��ѡ�ֱ�Ž���**��ǩ**��˳���ݽ���
* ��С���ݽ������̭����������������ѡ�֣�**ǰ��������**��������һ�ֵı�����
* �ڶ���Ϊ������**ǰ����ʤ��**
* ÿ�ֱ���������Ҫ**��ʾ����ѡ�ֵ���Ϣ**
*/
int main()
{
	//���������
	srand((unsigned int)time(NULL));

	//����������
	SpeechManager sm;
	int choice = 0; //���ڴ洢�û�����
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first
			<< " ������ " << it->second.name
			<< " �ɼ��� " << it->second.score[0] << endl;
	}*/


	while (true)
	{
		sm.showMenu();
		cout << "����������ѡ�� " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: // ��ʼ����
			sm.startGame();
			break;
		case 2: //�鿴���������¼
			sm.showRecord();
			break;
		case 3:  //��ձ�����¼
			sm.clearRecord();
			break;
		case 0:  //�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls"); // ����
			break;
		}
	}


	system("pause");
	return 0;
}