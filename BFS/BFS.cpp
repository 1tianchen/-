#include <iostream>
using namespace std;
void Merge(int arr[],int left,int mid ,int right,int brr[])
{
	int i = left, j = mid;
	int key = left;
	while (i < mid && j < right)
	{
		if (arr[i] >= arr[j])
		{
			brr[key++] = arr[j++];
		}
		else
		{
			brr[key++] = arr[i++];
		}
	}
	while (i < mid)
	{
		brr[key++] = arr[i++];
	}
	while (j < right)
	{
		brr[key++] = arr[j++];
	}
	for (i = left; i < right; i++)
	{
		arr[i] = brr[i];
	}
}
void Mergesort(int arr[], int left, int right,int brr[])
{
	if (left + 1 >= right)return;
	int mid = left + (right - left) / 2;
	Mergesort(arr, left, mid,brr);
	Mergesort(arr, mid, right,brr);
	Merge(arr, left, mid, right, brr);

}
int main()
{
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	int n; cin >> n;
	int* arr = new int[n];
	int* brr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	Mergesort(arr,0,n,brr);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
