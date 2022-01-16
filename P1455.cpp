#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, m, w;
int fa[10005];
bool vis[10005];
int c[10005], d[10005], f[10005];

int find(int x)
{
	if (fa[x] == x)
		return x;
	else
		return fa[x] = find(fa[x]);
}

int main()
{
	int x, y;
	memset(vis, false, sizeof(vis));
	n = read(), m = read(), w = read();
	for (int j = 1; j <= n; j++)
	{
		fa[j] = j;
		c[j] = read(), d[j] = read();
	}
	for (int i = 1; i <= m; i++)
	{
		x = read(), y = read();
		fa[find(x)] = find(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] != i)
		{
			if (fa[i] != i)
			{
				d[find(i)] += d[i];
				d[i] = 0;
				c[find(i)] += c[i];
				c[i] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int v = w; v >= c[i]; v--)
		{
			f[v] = max(f[v], f[v - c[i]] + d[i]);
		}
	}
	cout << f[w];
	return 0;
}
