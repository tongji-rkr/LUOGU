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

const int ux[4] = { -1,1,0,0 };
const int uy[4] = { 0,0,-1,1 };
int m, ans = 2147483647;
int dtr[305][305], muq[305][305];
struct Stn
{
	int day;
	int x;
	int y;
}a[50005];

bool cmp(Stn& s1, Stn& s2)
{
	return s1.day < s2.day;
}

void dfs(int d, int x, int y)
{
	if (dtr[x][y]<=d||d>=ans||d>=muq[x][y])
		return;
	muq[x][y] = d;
	if (dtr[x][y]>=2100000000)
	{
		ans = min(ans, d);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (x + ux[i] < 0 || y + uy[i] < 0)continue;
		dfs(d + 1, x + ux[i], y + uy[i]);
	}
}
int main()
{
	int x = 0, y = 0;
	m = read();
	memset(dtr, 0x7f, sizeof dtr);
	memset(muq, 0x7f, sizeof muq);
	for (int j = 1; j <= m; j++)
	{
		a[j].x = read(), a[j].y = read(), a[j].day = read();
		dtr[a[j].x][a[j].y] = min(dtr[a[j].x][a[j].y], a[j].day);
		for (int i = 0; i < 4; i++)
		{
			int xx = a[j].x + ux[i], yy = a[j].y + uy[i];
			if (xx >= 0 && yy >= 0)dtr[xx][yy] = min(dtr[xx][yy], a[j].day);
		}
	}
	dfs(0, 0, 0);
	if (ans == 2147483647)
		cout << -1;
	else 
		cout << ans;
	return 0;
}