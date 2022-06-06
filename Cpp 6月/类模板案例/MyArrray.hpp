#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
//		cout << "MyArray有参构造" << endl;
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[this->capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
//		cout << "MyArray拷贝构造" << endl;
		this->capacity = arr.capacity;
		this->size = arr.size;

		//深拷贝 创建新空间 避免重复调用
		this->pAddress = new T[arr.capacity];
		//将arr中原有的数据拷贝过来
		for (int i = 0; i < arr.capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//链式编程
	MyArray& operator=(const MyArray& arr)
	{
//		cout << "operator构造" << endl;

		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL; 
			this->capacity = 0; 
			this->size = 0;
		}
	
		//深拷贝
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.capacity];

		for (int i = 0; i < this->size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T& val)
	{
		if (this->capacity == this->size)
		{
			return;
		}
		this->pAddress[this->size] = val;
		this->size++; //更新数组
	}

	//尾删法
	void Pop_Back()
	{
		if (this->size == 0)
		{
			return;
		}
		this->size--;
	}

	//通过下标方式访问数组中的元素 
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int get_capacity()
	{
		return this->capacity;
	}

	//返回数组大小
	int get_size()
	{
		return this->size;
	}

	~MyArray()
	{
	//	cout << "MyArray析构" << endl;

		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}


private:
	T* pAddress;//指针指向	开辟的数组
	int size;//大小
	int capacity;//容量
};