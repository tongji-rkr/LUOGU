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

int n, M, T;
int dp[205][205];

int main()
{
	int t, m;
	n = read(), M = read(), T = read();
	for (int i = 1; i <= n; i++)
	{
		t = read(), m = read();
		for (int k = T; k >= t; k--)
		{
			for (int q = M; q >= m; q--)
			{
				dp[k][q] = max(dp[k][q], dp[k - t][q - m] + 1);
			}
		}
	}
	cout << dp[T][M] << endl;
	return 0;
}