#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	string n;
	cin >> m >> n;
	int len = n.length();
	for (int i = 0;i< len; i++)//5
	{
		if (n[i] == '0')
		{
			continue;
		}
		cout << n[i] <<"*"<< m << "^" << len - i - 1;
		if(n[i]!='0')cout << "+";
	}
	cout << (char)8;
}