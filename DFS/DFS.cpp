#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define nline "\n"
#define ull unsigned long long
const int maxn = 1e6 + 10;
const int h = 131;
ull f[maxn], p[maxn];
int main()
{
	fast
		string str;
	cin >> str;
	str = ' ' + str;
	p[0] = 1;
	for (int i = 1; i < str.length(); i++)
	{

		f[i] = (i == 1 ? (ull)str[i] - 'a' + 1ull : f[i - 1] * h + (ull)str[i] - 'a' + 1ull);
		p[i] = p[i - 1] * h;
	}
	int t;
	cin >> t;

	while (t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (f[b] - f[a - 1] * p[b - a + 1] == f[d] - f[c - 1] * p[d - c + 1])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}