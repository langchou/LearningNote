#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//д�ļ�

void test01()
{
	//����������
	fstream ofs;

	//ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);

	//д����
	ofs << "����:����" << endl;
	ofs << "�Ա�:��" << endl;
	ofs << "����:18" << endl;

	//�ر��ļ�
	ofs.close();
}


//���ļ�

void test02()
{
	//����������
	fstream ifs;
	//�򿪷�ʽ
	ifs.open("test.txt", ios::in);
	//�ж��Ƿ�򿪳ɹ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//������
	//1.
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}
	//2.
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//3.
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	//4.
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	//�ر��ļ�
	ifs.close();
}
int main()
{
	test02();
	system("pause");
	return 0;
}
