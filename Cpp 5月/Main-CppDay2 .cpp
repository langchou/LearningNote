#include "Swap.h"


//int main()
// {
//	//ц╟ещеепР
//	int temp = 0;
//	int arr[9] = { 1,4,7,2,5,8,3,6,9 };
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9 - i; j++)
//		{ 
//			if (arr[j - 1] > arr[j])
//			{
//				temp = arr[j];
//				arr[j] = arr[j - 1];
//				arr[j - 1] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < 9; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
	//int sum = 0;
	//int score[3][3] = { {100,100,100},
	//                    { 90, 50,100},
	//                    { 60, 70, 80} };
	//for (int i = 0; i < 3; i++)
	//{
	//	
	//	for (int j = 0; j < 3; j++)
	//	{
	//		
	//		 sum = sum + score[i][j];
	//	}
	//	cout << sum << endl;
	//	sum = 0;
//	//}
//	int i = 0;
//	int j = 1;
//	Swap(i, j);
//	system("pause");
//	return 0;
//}

//void bubble(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < len - i; j++)
//		{
//			if (arr[j - 1] > arr[j])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j - 1];
//				arr[j - 1] = temp;
//			}
//		}
//	}
//}
//
//void my_cout(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << endl;
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,7,8,9,6,5,2,3,11,4 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	bubble(arr, len);
//
//	my_cout(arr, len);
//	
//	system("pause");
//	return 0;
//}