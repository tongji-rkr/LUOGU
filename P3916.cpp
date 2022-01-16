#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

vector<int> son[100005];
int n, m;
int a[100005];

void dfs(int k,int d)
{
	if(a[k])return;
	a[k] = d;
	for (auto& i : son[k])
	{
		dfs(i, d);
	}
	return;
}
int main()
{
	int x, y;
	n = read();
	m = read();
	for (int i = 1; i <= m; i++)
	{
		x = read(), y = read();
		son[y].push_back(x);
	}
	for (int i = n; i >= 1; i--)dfs(i, i);
	for (int i = 1; i <= n; i++)cout << a[i] << ' ';
	return 0;
}