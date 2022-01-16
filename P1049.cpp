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

int v, n;
int a[35];
int f[20005];

int main()
{
	v = read(), n = read();
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = v; j >=a[i]; j--)
		{
			if (f[j] || f[j - a[i]])f[j] = 1;
			else f[j] = 0;
		}
	}
	for (int i = v; i >= 0; i--)
	{
		if (f[i])
		{
			cout << v - i;
			break;
		}
	}
	return 0;
}
