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

int n;
int x0, y0;
int x[10005], y[10005], a[10005], b[10005];
int ans = 1;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		x[i] = read(), y[i] = read(), a[i] = read(), b[i] = read();
	}
	x0 = read(), y0 = read();
	for (int i = 1; i <= n; i++)
	{
		if (x0 >= x[i] && x0 <= x[i] + a[i] && y0 >= y[i] && y0 <= y[i] + b[i])
			ans = i;
	}
	cout << ans;
	return 0;
}