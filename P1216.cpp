#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<unordered_map>
#include<cstring>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int r;
int dp[1005][1005];
int a;

int main()
{
	r = read();
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			a = read();
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][j - 1]) + a);
		}
	}
	int ans = 0;
	for (int i = 1; i <= r; i++)
	{
		ans = max(ans, dp[r][i]);
	}
	cout << ans;
	return 0;
}