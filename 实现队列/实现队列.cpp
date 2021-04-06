#include <bits/stdc++.h>
using namespace std;
typedef struct SqQueue
{
	int* base;
	int front, rear;
}SqQueue;
bool InitQueue(SqQueue& Q)
{
	Q.base = new int[100];
	if (!Q.base)return false;
	Q.front = Q.rear = 0;
	return true;

}
int main()
{	

}	 