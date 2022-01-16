#include<iostream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, m;
int a[100005][18];
int Log[100005];

int findmax(int x, int y)
{
	int d = y - x + 1;
	if (d == 1)return a[x][0];
	if (x + (1 << Log[d]) > y)
		return a[x][Log[d]];
	else
		return max(a[x][Log[d]], findmax(x + (1<<Log[d]), y));
}
int main()
{
	n = read(), m = read();
	a[1][0] = read();
	for (int i = 2; i <= n; i++)
	{
		a[i][0] = read();
		Log[i] = Log[i / 2] + 1;
	}
	for (int l = 1; (1 << l) <= n; l++)
	{
		for (int i = 1; i <= n - (1 << l) + 1; i++)
		{
			a[i][l] = max(a[i][l - 1], a[i + (1 << (l - 1))][l - 1]);
		}
	}
	int l, r;
	for (int i = 1; i <= m; i++)
	{
		l = read(), r = read();
		printf("%d\n", findmax(l, r));
	}
	return 0;
}