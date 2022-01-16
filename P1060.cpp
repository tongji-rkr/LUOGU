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

int m, n;
int a[30],b[30],f[30005];

int main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		a[i] = read(), b[i] = read();
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = n; j >= a[i]; j--)
		{
			f[j] = max(f[j], f[j - a[i]] + a[i] * b[i]);
		}
	}
	cout << f[n];
	return 0;
}
