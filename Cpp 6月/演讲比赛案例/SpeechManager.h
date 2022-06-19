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
	//构造
	SpeechManager();
	//菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//析构
	~SpeechManager();
	//创建选手
	void creatSpeaker();
	//初始化选手
	void initSpeaker();
	//开始比赛
	void startGame();
	//抽签
	void speechDraw();
	//分组比赛
	void speechContest();
	//显示比赛成绩
	void showScore();
	//保存记录
	void saveRecord();
	//读取往届成绩
	void loadRecord();
	//查看往届记录
	void showRecord();
	//清空往届记录
	void clearRecord();
	//保存12人的容器
	vector<int>v1;
	//保存第一轮 6人
	vector<int>v2;
	//最后一轮决赛
	vector<int>v3;
	//存放编号对应的选手
	map<int, Speaker> m_Speaker;
	//往届记录 key为第几届 value为记录信息
	map<int, vector<string>> m_Record;
	//记录比赛轮数
	int index;
	//文件为空标记
	bool fileIsEmpty;

};




