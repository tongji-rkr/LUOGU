#include<iostream>
#include<algorithm>
#include<cstdio>
#include<sstream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n;
int dp[205][205];

int main()
{
	n = read();
	for (int i = 1; i <= n - 1;i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			dp[i][j] = read();
		}
	}
	for (int gap = 2; gap <= n - 1; gap++)
	{
		for (int i = 1; i + gap <= n; i++)
		{
			int j = i + gap;
			for (int k = i + 1; k < j; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}