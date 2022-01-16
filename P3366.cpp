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

const int N = 100005;
int n, m;
int link[5005][5005];
int used[5005], pmin[5005];
int imin = 1;
int len;

bool judge()
{
	for (int i = 1; i <= n; i++)
	{
		if (used[i] == 0)
			return false;
	}
	return true;
}
int main()
{
	int x, y, z;
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		pmin[i] = N;
		for (int j = 1; j <= n; j++)
		{
			link[i][j] = N;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		x = read(), y = read(), z = read();
		if (z < link[x][y])link[x][y] = link[y][x] = z;
	}
	used[1] = 1;
	while (!judge())
	{
		int k = N, w = imin;
		for (int i = 1; i <= n; i++)
		{
			if (used[i])continue;
			pmin[i] = min(pmin[i], link[w][i]);
			if (pmin[i] < k)k = pmin[i], imin = i;
		}
		if (k == N) { cout << "orz"; return 0; }
		len += pmin[imin];
		used[imin] = 1;
	}
	cout << len;
	return 0;
}