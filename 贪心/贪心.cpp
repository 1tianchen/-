
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
int v[1001];
int w[1001];
int f[1001][1001];
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			f[i][j] = f[i - 1][j];
			if (v[i] <= j)
			{
				f[i][j] = max(f[i - 1][j], f[i-1][j - v[i]] + w[i]);
			}
		}
	cout << f[n][m];
}