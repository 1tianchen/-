#include <bits/stdc++.h>
using namespace std;
int Maxsize=100;
typedef struct SqStack
{
	int* base;
	int* top;
}SqStack;
bool Initstack(SqStack& S)
{
	S.base = new int[Maxsize] {0};
	if (!S.base)
		return 0;
	S.top = S.base;
	return true;
}
bool Push(SqStack& S, int e)
{
	if (S.top - S.base == Maxsize)
		return false;
	*(S.top++) = e;
	return true;
}
bool pop(SqStack& S, int& e)
{
	if (S.base == S.top)
		return false;
	e = *(--S.top);
	return true;
}
int GetTop(SqStack S)
{
	cout << "%p=" << S.top-1 ;
	if (S.top != S.base)
		return *(S.top - 1);
	else
		return -1;

	cout << endl;
}
int main()
{	
	int n,x;
	SqStack S;
	Initstack(S);
	cin >> n;
	while (n--)
	{
		cin >> x;
		Push(S, x);
	}
	while (S.top!=S.base)
	{
		cout << GetTop(S) << "\t";
		pop(S, x);

	}
	return 0;
}            