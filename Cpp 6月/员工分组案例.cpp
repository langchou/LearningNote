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
    ��˾��Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾��
    ��Ҫָ��Ա�����ĸ����Ź�����
    ��Ϣ�У����� ������ɣ����ŷ�Ϊ���߻����������з�
    �����10��Ա�����䲿�ź͹���
    ͨ��multimap������Ϣ�Ĳ���key�����ű�ţ�value��Ա����
    �ֲ�����ʾԱ����Ϣ
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
        worker.name = "Ա��";
        worker.name += nameSeed[i];
        worker.salary = rand() % 10001 + 10000;
        v.push_back(worker);
    }
}

//ָ�ɲ���
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
    cout << "�߻�����" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "������" << pos->second.name << " н�ʣ�" << pos->second.salary << endl;
    }

    cout << "��������" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "������" << pos->second.name << " н�ʣ�" << pos->second.salary << endl;
    }


    cout << "�߻�����" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "������" << pos->second.name << " н�ʣ�" << pos->second.salary << endl;
    }
}

int main()
{
    //����Ա��
    srand((unsigned int)time(NULL));
    vector<Worker>vWorker;
    creatWorker(vWorker);

    //����
    //for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    //{
    //    cout << it->name << it->salary << endl;
    //}
    
    //ָ�ɸ�λ
    multimap<int, Worker>mWorker;
    setGroup(vWorker,mWorker);

    //չʾԱ�����ţ�������н��
    showWorker(mWorker);


    system("pause");
    return EXIT_SUCCESS;
}