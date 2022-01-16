#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int f[250][250];
int n;
int ans;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		f[i][i] = read();
	}
	for (int len = 1; len < n; len++)
	{
		for (int i = 1; i + len <= n; i++)
		{
			int j = i + len;
			for (int pos = i; pos < j; pos++)
			{
				if (f[i][pos] == f[pos + 1][j] && f[i][pos] && f[pos + 1][j])
					f[i][j] = max(f[i][j], f[i][pos] + 1), ans = max(ans, f[i][j]);
			}
		}
	}
	cout << ans;
	return 0;
}