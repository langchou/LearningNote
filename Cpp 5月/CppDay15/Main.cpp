#include "WorkerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{
	WorkerManager wm;

	//���Դ���
	//Worker* worker = NULL;
	//worker = new Emplyee(1, "����", 1);
	//worker->ShowInfo();
	//delete worker;
	//worker = new Manager(2, "����", 2);
	//worker->ShowInfo();
	//delete worker;
	//worker = new Boss(3, "����", 3);
	//worker->ShowInfo();
	//delete worker;


	while (1)
	{
		wm.ShowMenu();
		int choice = 0;
		cout << "����������ѡ��:>";
		cin >> choice;

		switch (choice)
		{
		case 1:	//����
			wm.Add_Emp();
			break;
		case 2:	//��ʾ
			wm.Show_Emp();
			break;
		case 3:	//ɾ��
			wm.Del_Emp();
			break;
		case 4:	//�޸�
			wm.Mod_Emp();
			break;
		case 5:	//����
			wm.Find_Emp();
			break;
		case 6:	//����ְ��
			wm.Sort_Emp();
			break;
		case 7:	//����ĵ�
			wm.Clean_File();
			break;
		case 0:
			wm.ExitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}