#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };
inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

bool istree[105][105];
int n, m, t, x, y, x2, y2, ans;
char c;

void dfs(int x,int y,int step)
{
	if (x == x2 && y == y2 && step == 0)ans++;
	if (!step || fabs(x - x2) + fabs(y - y2) > step)return;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1 || yy<1 || xx>n || yy>m || istree[xx][yy])continue;
		dfs(xx, yy, step - 1);
	}
}
int main()
{
	n = read(), m = read(), t = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c;
			if (c == '.')
				istree[i][j] = false;
			else 
				istree[i][j] = true;
		}
	}
	x = read(), y = read(), x2 = read(), y2 = read();
	dfs(x, y, t);
	cout << ans;
	return 0;
}