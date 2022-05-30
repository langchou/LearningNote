#include "WorkerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{
	WorkerManager wm;

	//测试代码
	//Worker* worker = NULL;
	//worker = new Emplyee(1, "张三", 1);
	//worker->ShowInfo();
	//delete worker;
	//worker = new Manager(2, "李四", 2);
	//worker->ShowInfo();
	//delete worker;
	//worker = new Boss(3, "王五", 3);
	//worker->ShowInfo();
	//delete worker;


	while (1)
	{
		wm.ShowMenu();
		int choice = 0;
		cout << "请输入您的选择:>";
		cin >> choice;

		switch (choice)
		{
		case 1:	//增加
			wm.Add_Emp();
			break;
		case 2:	//显示
			break;
		case 3:	//删除
			break;
		case 4:	//修改
			break;
		case 5:	//查找
			break;
		case 6:	//排序职工
			break;
		case 7:	//清空文档
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