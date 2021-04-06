// #include<bits/stdc++.h>
// using namespace std;
// int f[10010];
// //f[i]表示i的集合名
// int find(int k) {
//     //路径压缩
//     if (f[k] == k)return k;
//     return f[k] = find(f[k]);
// }
// int main()
// {
//     int p1, p2, p3,n,m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         f[i] = i;//初始化i的老大为自己
//     for (int i = 1; i <= m; i++) 
//     {
//         cin >> p1 >> p2 >> p3;
//         if (p1 == 1)
//             f[find(p2)] = find(p3);
//         //p3打赢了p2
//         else
//             if (find(p2) == find(p3))
//                 //是否是一伙的
//                 printf("Y\n");
//             else
//                 printf("N\n");
//     }
//     return 0;
// }

/*#include<iostream>
using namespace std;
int f[10001];
int find(int k)
{
	if (f[k] ==k)return k;
	return f[k] = find(f[k]);
}
int main()
{
	int n, m, x1, x2;
	char arr;
	cin >> n >> m;
	for (int i = 1; i <=n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> arr >> x1 >> x2;
		if (arr == 'M')
		{
			f[find(x1)] = find(x2);
		}
		else
		{
			if (find(x1) == find(x2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2500;
int p[N];
int n, m;
int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++) p[i] = i;
	char op;
	int a, b;
	while (m--) 
	{
		cin >> op >> a >> b;
		if (op == 'E') 
		{
			p[find(a + n)] = find(b);
			p[find(b + n)] = find(a);
		}
		else {
			p[find(a)] = find(b);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (p[i] == i) ans++;
	cout << ans << endl;
	return 0;
}