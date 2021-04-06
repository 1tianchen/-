#include <cassert>
#include <time.h>
//选择一个基准 分为二个区域 小于<=基准<=大于
//优化 三个 小于 等于 大于 
#include <bits/stdc++.h>
using namespace std;
void show_array(int n, int arr[])
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
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
void quick_sort(int arr[],int left,int right)
{//9ok 15 1 4 0 18 20 17 0 15 4 5 7 11 17 7 16 16 10 1
 //1   9 1 4 0 18 20 17 0 15 4 5 7 11 17 7 16 16 10 15
	if (left >= right) return; //0 19
	int base = arr[left];//9
	int i = left, j = right;//[left,right]0 19
	while (i<j)//1 19
	{    	
		while (arr[j] >= base && j > i)
			j--;//
		if (i < j)arr[i++] = arr[j];
		while (arr[i] < base && i<j)
			i++;
		if (i < j)arr[j--] = arr[i];
	}
	arr[i] = base;
	quick_sort(arr, left, i - 1);
	quick_sort(arr, i + 1, right);
}
int main()
{
	while (true) {
		//n=100000,0->100000||
		int n; cout << "您想排序的个数:"; cin >> n;
		int* p = new int[n];
		int begin, end; cout << "您想排序数的范围从那到那:";
		cin >> begin >> end;
		p = generateRandomArray(n, begin, end);
		//show_array(n, p);
		int left, right; cout << "您想排序的范围从那到那:" ;
		cin >> left >> right;
		clock_t starttime = clock();
		quick_sort(p, left, right - 1);
		//show_array(n,p);
		clock_t endtime = clock();
		cout << "排序时间为" << double(endtime - starttime) / CLOCKS_PER_SEC << " s" << endl;
		delete []p;
	}
}//1000000 0 1000000 0 1000000 ->0.16

/*
#include <cassert>
#include <time.h>
//选择一个基准 分为二个区域 小于<=基准<=大于
//优化 三个 小于 等于 大于
#include <bits/stdc++.h>
using namespace std;
void show_array(int n, int arr[])
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
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
void quick_sort(int arr[],int left,int right)
{//9ok 15 1 4 0 18 20 17 0 15 4 5 7 11 17 7 16 16 10 1
 //1   9 1 4 0 18 20 17 0 15 4 5 7 11 17 7 16 16 10 15
	if (left >= right) return; //0 19
	//if (right - left <= 15)
	//{
	//	insertion_sort(arr, right+1);
	//	return;
	//}
	int base = arr[left];//9
	int i = left, j = right;//[left,right]0 19
	while (i<j)//1 19
	{
		while (arr[j] >= base && j > i)
			j--;//
		if (i < j)arr[i++] = arr[j];
		while (arr[i] < base && i<j)
			i++;
		if (i < j)arr[j--] = arr[i];
	}
	arr[i] = base;
	quick_sort(arr, left, i - 1);
	quick_sort(arr, i + 1, right);
}
int main()
{
	while (true) {
		//n=100000,0->100000||
		int n; cout << "您想排序的个数:"; cin >> n;
		int* p = new int[n];
		int begin, end; cout << "您想排序数的范围从那到那:";
		cin >> begin >> end;
		p = generateRandomArray(n, begin, end);
		//show_array(n, p);
		int left, right; cout << "您想排序的范围从那到那:" ;
		cin >> left >> right;
		clock_t starttime = clock();
		quick_sort(p, left, right - 1);
		//show_array(n,p);
		clock_t endtime = clock();
		cout << "排序时间为" << double(endtime - starttime) / CLOCKS_PER_SEC << " s" << endl;
		delete []p;
	}
}



*/

