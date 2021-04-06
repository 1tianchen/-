#include <iostream>
#include <cassert>
#include <time.h>
using namespace std;
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
void insertion_sort(int arr[], int n)
//3 5 2 1 4 10   1
//3 5 2 1 4 10   2
//2 3 5 1 4 10   3
//1 2 3 5 4 10   4
{
	for (int i = 0; i < n; i++)
	{
		int e = arr[i];
		int j;
		for (j = i; j > 0 && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
}
int main()
{
	//n=100000,0->100000||57.976
	int a = clock();
	int n, t; cout << "您想排序的个数:"; cin >> n;
	cout << "您想从哪里开始排列:"; cin >> t;
	int* p = new int[n];
	int begin, end; cout << "您想排序的范围从那到那:";
	cin >> begin >> end;
	p = generateRandomArray(n, begin, end);
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	insertion_sort(p + t, n - t);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	int b = clock();
	cout<< "排序时间为:" << b - a;
}





