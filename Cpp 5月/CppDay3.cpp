#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

//
//void bubble(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < len - i-1; j++)
//		{
//			if (arr[j] > arr[j+1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = temp;
//			}
//		}
//	}
//}
//
//
//void cprintf(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << endl;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 4,3,9,6,1,2,10,8,7,5 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	bubble(arr, len);
//	cprintf(arr, len);
//
//	system("pause");
//	return 0;
//}

//�ṹ��
//struct student
//{
//	string name;
//	int age;
//	int score;
//};
//
//
//int main()
//{
//	
//	student s = { "����", 18, 66 };
//	student* p = &s;
//	cout << p->name << endl;
//	system("pause");
//	return 0;
//}


//�ṹ��Ƕ��
//struct student
//{
//	string name;
//	int age;
//	int score;
//};
//
//struct teacher
//{
//	int id;
//	string name;
//	int age;
//	struct student stu;
//};
//
//
//int main()
//{
//
//	teacher t;
//	t.id = 123;
//	t.name = "����";
//	t.age = 40;
//	t.stu.name = "����";
//	t.stu.age = 18;
//	t.stu.score = 60;
//}

//
//struct student
//{
//	string name;
//	int age;
//	int score;
//};
//// ��ַ���� const
//void cprintf(const student* s)
//{
//	cout << s->name << s->age << s->score << endl;
//}
//
//int main()
//{
//
//	student s = { "����", 18, 66 };
//	cprintf(&s);
//	system("pause");
//	return 0;
//}

//struct Student
//{
//	string name;
//	int score;
//};
//
//struct Teacher
//{
//	string name;
//	Student sArray[5];
//};
//
//void allocateSpace(Teacher tArray[],int len)
//{
//	string tName = "��ʦ";
//	string sName = "ѧ��";
//	string nameSeed = "ABCDE";
//
//	for (int i = 0; i < len; i++)
//	{
//		tArray[i].name = tName + nameSeed[i];
//
//		for (int j = 0; j < 5; j++)
//		{
//			tArray[i].sArray[j].name = sName + nameSeed[j];
//			tArray[i].sArray[j].score = rand() % 61 + 40;
//		}
//	}
//}
//
//
//void printfInfo(Teacher tArray[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << tArray[i].name << endl;
// 
//		for (int j = 0; j < 5; j++)
// 
//		{
//			
//			cout << "\t������" << tArray[i].sArray[j].name<< " ������" << tArray[i].sArray[j].score << endl;
//		}
//	}
//}
//
//
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//
//	Teacher tArray[3];
//
//	int len = sizeof(tArray) / sizeof(Teacher);
//
//	allocateSpace(tArray,len);
//
//	printfInfo(tArray,len);
//
//	system("pause");
//	return 0;
//}


struct Hero
{
	string name;
	int age;
	string sex;
};


void heroBubble(Hero Harray[], int len)
{
	for (int i = 0; i < len -1; i++)
	{
		for (int j = 0; j < len-1 - i; j++)
		{
			if (Harray[j].age > Harray[j + 1].age)
			{
				Hero temp = Harray[j];
				Harray[j] = Harray[j + 1];
				Harray[j + 1] = temp;
			}
		}
	}
}

void printHeros(Hero Harray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "������ " << Harray[i].name << " �Ա� " << Harray[i].sex << " ���䣺 " << Harray[i].age << endl;
	}
}

//���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�; �����ṹ�����飬�����д��5��Ӣ�ۡ�
//ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ��
int main()
{
	struct Hero Harray[5] = { {"����",23,"��"} ,{"����",22,"��"} ,{"�ŷ�",20,"��"} ,{"����",21,"��"} ,{"����",19,"Ů"} };
	int len = sizeof(Harray) / sizeof(Harray[0]);
	heroBubble(Harray, len);
	printHeros(Harray, len);
	system("pause");
	return 0;
}

