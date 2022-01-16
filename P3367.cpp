#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, m;
int fa[10005];

int find(int x)
{
	if (fa[x] == x)
		return x;
	else
		return fa[x]=find(fa[x]);
}

int main()
{
	int z, x, y;
	n = read(), m = read();
	for (int i = 1; i <= n; i++)fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		z = read(), x = read(), y = read();
		if (z == 1)fa[find(x)] = find(y);
		if (z == 2)
		{
			if (find(x) == find(y))cout << 'Y' << endl;
			else cout << 'N' << endl;
		}
	}
	return 0;
}