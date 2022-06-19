#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<functional>
#include<numeric>
#include<ctime>
#include<deque>
#include<fstream>
using namespace std;


class Speaker
{
public:
	string name;
	double score[2];
};


class SpeechManager
{
public:
	//����
	SpeechManager();
	//�˵�
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//����
	~SpeechManager();
	//����ѡ��
	void creatSpeaker();
	//��ʼ��ѡ��
	void initSpeaker();
	//��ʼ����
	void startGame();
	//��ǩ
	void speechDraw();
	//�������
	void speechContest();
	//��ʾ�����ɼ�
	void showScore();
	//�����¼
	void saveRecord();
	//��ȡ����ɼ�
	void loadRecord();
	//�鿴�����¼
	void showRecord();
	//��������¼
	void clearRecord();
	//����12�˵�����
	vector<int>v1;
	//�����һ�� 6��
	vector<int>v2;
	//���һ�־���
	vector<int>v3;
	//��ű�Ŷ�Ӧ��ѡ��
	map<int, Speaker> m_Speaker;
	//�����¼ keyΪ�ڼ��� valueΪ��¼��Ϣ
	map<int, vector<string>> m_Record;
	//��¼��������
	int index;
	//�ļ�Ϊ�ձ��
	bool fileIsEmpty;

};




