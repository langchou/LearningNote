#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Person
{
public:

    Person(string name,int age)
    {
        this->age = age;
        this->name = name;
    }

    bool operator==(const Person &p)
    {
        if (p.age == this->age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string name;
    int age;
};

class Greater20
{
public:
    bool operator()(const Person& p)
    {
        if (p.age > 20) return true;
        else return false;
    }
};

void test()
{
    vector<Person>v;
    Person p1("¡ı±∏", 35);
    Person p2("πÿ”", 35);
    Person p3("’≈∑…", 35);
    Person p4("’‘‘∆", 30);
    Person p5("ª∆÷“", 38);
    Person p6("≤‹≤Ÿ", 40);
    Person p("÷Ó∏¡¡", 35);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    
    int ret = count_if(v.begin(), v.end(), Greater20());
    cout << ret << endl;
}

void myPrint(int val)
{
    cout << val << endl;
}

void test2()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(60);
    v.push_back(40);
    v.push_back(10);
    v.push_back(80);
    v.push_back(40);
    v.push_back(50);
    v.push_back(90);

    sort(v.begin(), v.end(), [](const int v1, const int v2) {return v1 > v2; });
    for_each(v.begin(), v.end(),myPrint);
}

void test3()
{
    vector<int>v1;
    vector<int>v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    for_each(v1.begin(), v1.end(), myPrint);
    cout << endl;
    for_each(v2.begin(), v2.end(), myPrint);
    cout << endl;
    vector<int>v3;
    v3.resize(v1.size() + v2.size());
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), itEnd, myPrint);

}


int main()
{

    //test2();
    test3();
    system("pause");
    return EXIT_SUCCESS;
}