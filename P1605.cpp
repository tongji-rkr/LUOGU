#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
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
int n, m, t;
int map[6][6];
int sx, sy, ex, ey;
int ans;

void dfs(int x, int y)
{
	if (x == ex && y == ey)
	{
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int xx = x + ux[i], yy = y + uy[i];
		if (map[xx][yy]||xx <= 0 || yy <= 0 || xx > n || yy > m)continue;
		map[xx][yy] = 1;
		dfs(xx, yy);
		map[xx][yy] = 0;
	}
}
int main()
{
	int x, y;
	n = read(), m = read(), t = read();
	sx = read(), sy = read(), ex = read(), ey = read();
	for (int i = 1; i <= t; i++)
	{
		x = read(), y = read();
		map[x][y] = 1;
	}
	map[sx][sy] = 1;
	dfs(sx, sy);
	cout << ans;
	return 0;
}