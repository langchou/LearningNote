#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>



void test1()
{
    negate<int>n;
    cout << n(30) << endl;
    plus<int>m;
    cout << m(20, 40) << endl;
}

void print01(int val)
{
    cout << val << " ";
}

class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test2()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(60);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(20);

    sort(v.begin(), v.end(),greater<int>());
    //for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    //{
    //    cout << *it << endl;
    //}
    //for_each(v.begin(), v.end(), print01);
    for_each(v.begin(), v.end(), print02());
}

class my_trans
{
public:
    int operator()(int val)
    {
        return val;
    }
};

void test3()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>t_v;
    t_v.resize(v.size());
    transform(v.begin(), v.end(), t_v.begin(), my_trans());
    
    for_each(t_v.begin(), t_v.end(), print02());
    cout << endl;
    for_each(v.begin(), v.end(), print02());
}

class Person
{
public:
    Person(string name,int age)
    {
        this->age = age;
        this->name = name;
    }

    bool operator==(const Person& p)
    {
        if (p.age == age && p.name == name)
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

void test4()
{
    vector<Person>v;
    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);
    Person p4("d", 40);
    Person p5("e", 50);
    Person p6("f", 60);
    Person p7("g", 70);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    v.push_back(p7);

    Person pp("c", 30);
    vector<Person>::iterator it = find(v.begin(), v.end(), pp);
    if (it == v.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << "找到了" << endl;
    }
}

class aPerson
{
public:
    aPerson(string name, int age)
    {
        this->age = age;
        this->name = name;
    }

    string name;
    int age;
};

class Greater20
{
public:
    bool operator()(Person& p)
    {
        return p.age > 20;
    }
};


void test5()
{
    vector<Person>v;
    Person p1("a", 10);
    Person p2("b", 20);
    Person p3("c", 30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
    if (it == v.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << "找到了" << endl;
    }
}

void test6()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
   bool set = binary_search(v.begin(), v.end(), 8);
    if (set)
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
    
}



int main()
{
    //test3();
    //test4();
    //test5();
    test6();

    system("pause");
    return EXIT_SUCCESS;
}