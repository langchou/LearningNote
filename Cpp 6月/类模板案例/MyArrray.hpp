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
//		cout << "MyArray�вι���" << endl;
		this->capacity = capacity;
		this->size = 0;
		this->pAddress = new T[this->capacity];
	}

	//��������
	MyArray(const MyArray& arr)
	{
//		cout << "MyArray��������" << endl;
		this->capacity = arr.capacity;
		this->size = arr.size;

		//��� �����¿ռ� �����ظ�����
		this->pAddress = new T[arr.capacity];
		//��arr��ԭ�е����ݿ�������
		for (int i = 0; i < arr.capacity; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//��ʽ���
	MyArray& operator=(const MyArray& arr)
	{
//		cout << "operator����" << endl;

		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL; 
			this->capacity = 0; 
			this->size = 0;
		}
	
		//���
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.capacity];

		for (int i = 0; i < this->size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//β�巨
	void Push_Back(const T& val)
	{
		if (this->capacity == this->size)
		{
			return;
		}
		this->pAddress[this->size] = val;
		this->size++; //��������
	}

	//βɾ��
	void Pop_Back()
	{
		if (this->size == 0)
		{
			return;
		}
		this->size--;
	}

	//ͨ���±귽ʽ���������е�Ԫ�� 
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//������������
	int get_capacity()
	{
		return this->capacity;
	}

	//���������С
	int get_size()
	{
		return this->size;
	}

	~MyArray()
	{
	//	cout << "MyArray����" << endl;

		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}


private:
	T* pAddress;//ָ��ָ��	���ٵ�����
	int size;//��С
	int capacity;//����
};