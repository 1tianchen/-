#include <iostream>//选择排序
#include <cassert>
#include <time.h>
using namespace std;
void selection_sort(int arr[], int n);
int* generateRandomArray(int n, int rangeL, int rangeR)
{
	assert(rangeL <= rangeR);
	int* arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	}
	return arr;
}
void selection_sort(int arr[],int n)//从小到大
{
	for (int i = 0; i <n-1; i++)//n^2
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main()
{
	//n=100000,0->100000||30.761
	int a = clock();
	int n,t; cout << "您想排序的个数:"; cin >> n;
	cout << "您想从哪里开始排列:"; cin >> t;
	int* p=new int[n];
	int begin, end; cout << "您想排序的范围从那到那:";
	cin >> begin >> end;
	p=generateRandomArray(n, begin, end);
	/*for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}*/
	selection_sort(p+t,n-t);
	cout << endl;
	/*for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}*/
	cout<<endl;
	int b = clock();
	cout<<"排序时间为"<<  b - a;
}