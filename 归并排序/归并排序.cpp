// #include<iostream>
// #include<assert.h>
// using namespace std;
// void insertion_sort(int arr[], int n);
// void show_array(int n, int arr[]) 
// {
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// }
// int* generateRandomArray(int n, int rangeL, int rangeR)
// {
// 	assert(rangeL <= rangeR);
// 	int* arr = new int[n];
// 	srand(time(NULL));
// 	for (int i = 0; i < n; i++)
// 	{
// 		arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
// 	}
// 	return arr;
// 
// }
// void Merge(int arr[], int left, int mid, int right, int brr[])
// {
// 	int i = left, j = mid;
// 	int key = left;
// 	while (i < mid && j < right)
// 	{
// 		if (arr[i] >= arr[j])
// 		{
// 			brr[key++] = arr[j++];
// 		}
// 		else
// 		{
// 			brr[key++] = arr[i++];
// 		}
// 	}
// 	while (i <mid)
// 	{
// 		brr[key++] = arr[i++];
// 	}
// 	while (j <right)
// 	{
// 		brr[key++] = arr[j++];
// 	}
// 	for (i = left; i < right; i++)
// 	{
// 		arr[i] = brr[i];
// 	}
// }
// void Mergesort(int arr[], int left, int right, int brr[])
// {
// 	if (left + 1 >= right)return;
// 	int mid = left + (right - left) / 2;
// 	Mergesort(arr, left, mid, brr);
// 	Mergesort(arr, mid, right, brr);
// 	Merge(arr, left, mid, right , brr);
// }
// int main()
// {
// 	while (true)
// 	{
// 		int n; cout << "您想排序的个数:"; cin >> n;
// 		int* arr = new int[n];
// 		int* brr = new int[n];
// 		int begin, end; cout << "您想排序数的范围从那到那:";
// 		cin >> begin >> end;
// 		arr = generateRandomArray(n, begin, end);
// 		//show_array(n, arr);
// 		
// 		int left, right; cout << "您想排序的范围从那到那:" ;
// 		cin >> left >> right;
// 		clock_t starttime = clock();
// 		Mergesort(arr, left, right, brr);
// 		show_array(n, arr);
// 		clock_t endtime = clock();
// 		cout << "排序时间为" << double(endtime - starttime) / CLOCKS_PER_SEC << " s" << endl;
// 		delete []arr;
// 		delete []brr;
// 	}
// }
// 20000 0 10 0 10000
