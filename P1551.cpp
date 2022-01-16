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

int n, m, p;
int fa[10005];
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
	n = read(), m = read(), p = read();
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		x = read(), y = read();
		fa[find(x)] = find(y);
	}
	for (int i = 1; i <= p; i++)
	{
		x = read(), y = read();
		if (find(x) == find(y))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}