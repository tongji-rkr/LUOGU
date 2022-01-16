#include<iostream>
using namespace std;

int t, k;
int n, m;
int g[2005][2005],dp[2005][2005];
int main()
{
	cin >> t >> k;
	g[0][0] = g[1][0] = g[1][1] = 1;
	for (int i = 2; i <= 2000; i++)
	{
		g[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			g[i][j] = (g[i - 1][j] + g[i - 1][j - 1]) % k;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			if (!g[i][j])dp[i][j]++;
		}
		dp[i][i + 1] = dp[i][i];
	}
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> m;
		if (m > n)m = n;
		cout << dp[n][m] << endl;
	}
	return 0;
}