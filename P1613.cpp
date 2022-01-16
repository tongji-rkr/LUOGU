#include <iostream>
#include <vector>
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

int n, m;
int F[55][55][65], dis[55][55];

int main()
{
	memset(dis, 0x3f, sizeof dis);
	int x, y, flag = 0;
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		x = read(), y = read();
		if (x == y)flag = 1;
		F[x][y][0] = 1;
		dis[x][y] = 1;
	}
	if (flag)
	{
		cout << 1;
		return 0;
	}
	for (int p = 1; p <= 64; p++)
	{
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (F[i][k][p - 1] && F[k][j][p - 1])
						F[i][j][p] = dis[i][j] = 1;
				}
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	cout << dis[1][n];
	return 0;
}