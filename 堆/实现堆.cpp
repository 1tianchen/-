#include <iostream>
#include <assert.h>
#include <time.h>
using namespace std;
class Maxheap
{
private :
	int count;
	int capacity;
	void shifUp(int k)
	{
		while (k>1&&data[k/2]<data[k])
		{
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	void shiftdown(int k)
	{
		while (2*k<=count)
		{
			int j = 2 * k;
			if (j + 1 <= count && data[j + 1] > data[j])
				j += 1;

			if (data[k] >= data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	}
public:
	int* data;
	Maxheap(int capacity)
	{
		data = new int[capacity + 1];
		this->capacity = capacity;
	}
	~Maxheap()
	{
		delete[] data;
	}
	int size()
	{
		return count;
	}
	bool IsEmpty()
	{
		return count == 0;
	}
	void insert(int item)
	{
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		shifUp(count);
	}
	int extractMax()
	{
		assert(count > 0);
		int ret = data[1];
		swap(data[1], data[count]);
		count--;
		shiftdown(1);
	}
};
int main()
{
	Maxheap maxheap(100);
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		maxheap.insert(rand() % 100);
	}
	for (int i = 1; i < 10; i++)
	{
		cout<<maxheap.data[i]<<" ";
	}
}