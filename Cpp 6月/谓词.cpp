#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MyAdd
{
public:

    int operator()(int v1,int v2)
    {
        return v1 + v2;
    }
};

class MyPrint
{
public:

    MyPrint()
    {
        this->count = 0;
    }

    void operator()(string test)
    {
        cout << test << endl;
        this->count++;
    }

    int count;
};

void test01()
{
    MyAdd myadd;
    MyPrint myprint;
    myprint("666");
    myprint("666");
    myprint("666");
    myprint("666");
    //cout << myadd(100, 200) << endl;
    cout << myprint.count << endl;
}

void doprint(MyPrint& p, string test)
{
    p(test);
}

void test02()
{
    MyPrint myprint;
    doprint(myprint, "666");
}

//一元谓词
class GreatFive
{
public:

    bool operator()(int val)
    {
        return val > 5;
    }
};

void test03()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //查找容器中是否有大于5的数字
    //GreaterFive()，匿名的函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreatFive());

    for (; it != v.end(); it++)
    {
        cout << *it << endl;
    }

}

//二元谓词
class MyCompare
{
public:
    //bool体现谓词 传入参数为2个 则为二元
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};


void test04()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(60);
    v.push_back(70);
    v.push_back(50);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    sort(v.begin(), v.end(), MyCompare());

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

}


int main()
{
    //test01();
    //test02();
    //test03();
    test04();
    system("pause");
    return EXIT_SUCCESS;
}