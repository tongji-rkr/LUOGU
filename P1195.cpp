#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

struct EDGE
{
	int x, y, v;
	bool operator <(EDGE& s1)
	{
		return v < s1.v;
	}
}a[10005];
int n, m, k, s;
int fa[2005];
int ans;

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
int main()
{
	n = read(), m = read(), s = read();
	if (s == n)
	{
		cout << 0;
		return 0;
	}
	if (s > n)
	{
		cout << "No Answer";
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		a[i].x = read(), a[i].y = read(), a[i].v = read();
	}
	sort(a + 1, a + 1 + m);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		if (find(a[i].x) != find(a[i].y))
		{
			fa[find(a[i].x)] = find(a[i].y);
			k++;
			ans += a[i].v;
		}
		if (k == n - s)
		{
			break;
		}
	}
	cout << ans;
	return 0;
}