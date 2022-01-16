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

const int dx[8] = { -1,1,0,0,-1,-1,1,1 };
const int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
int n, m;
char a[105][105];
int ans;

void dfs(int x,int y)
{
	a[x][y] = '.';
	for (int i = 0; i < 8; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1 || yy<1 || xx>n || yy>m)continue;
		if (a[xx][yy] == 'W')
			dfs(xx, yy);
	}
}
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 'W')
			{
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}