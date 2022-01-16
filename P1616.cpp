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

int m;
long long T;
long long dp[10000005];

int main()
{
	long long t, v;
	T = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		t = read(), v = read();
		for (int k = t; k <= T; k++)
		{
			dp[k] = max(dp[k], dp[k - t] + v);
		}
	}
	cout << dp[T] << endl;
	return 0;
}