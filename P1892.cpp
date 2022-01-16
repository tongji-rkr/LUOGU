#include<iostream>
#include<vector>
using namespace std;

int n, m, p, q;
int f[2002];
int ans;
int find(int x)//²éÕÒ
{
	return x == f[x] ? x : f[x] = find(f[x]);
}
int main()
{
	char c;
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> c >> p >> q;
		if (c == 'F')
		{
			f[find(p)] = find(q);
		}
		else
		{
			f[find(p + n)] = find(q);
			f[find(q + n)] = find(p);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i)
			ans++;
	}
	cout << ans;
	return 0;
}