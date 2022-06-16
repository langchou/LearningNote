#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
using namespace std;
#define CEHUA 1
#define MEISHU 2
#define YANFA 3




/*
    公司招聘了10个员工（ABCDEFGHIJ），10名员工进入公司后，
    需要指派员工在哪个部门工作。
    信息有：姓名 工资组成；部门分为：策划、美术、研发
    随机给10名员工分配部门和工资
    通过multimap进行信息的插入key（部门编号）value（员工）
    分部门显示员工信息
*/

class Worker
{
public:
    string name;
    int salary;
};

void creatWorker(vector<Worker>&v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.name = "员工";
        worker.name += nameSeed[i];
        worker.salary = rand() % 10001 + 10000;
        v.push_back(worker);
    }
}

//指派部门
void setGroup(vector<Worker>& v, multimap<int,Worker>& m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        int dId = rand() % 3 + 1;
        m.insert(make_pair(dId, *it));
   }
}

void showWorker(multimap<int, Worker>m)
{
    cout << "策划部门" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.name << " 薪资：" << pos->second.salary << endl;
    }

    cout << "美术部门" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.name << " 薪资：" << pos->second.salary << endl;
    }


    cout << "策划部门" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.name << " 薪资：" << pos->second.salary << endl;
    }
}

int main()
{
    //创建员工
    srand((unsigned int)time(NULL));
    vector<Worker>vWorker;
    creatWorker(vWorker);

    //测试
    //for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    //{
    //    cout << it->name << it->salary << endl;
    //}
    
    //指派岗位
    multimap<int, Worker>mWorker;
    setGroup(vWorker,mWorker);

    //展示员工部门，姓名，薪资
    showWorker(mWorker);


    system("pause");
    return EXIT_SUCCESS;
}