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

int n;
int a[35][35];
const int dx[8] = { -1,1,0,0 };
const int dy[8] = { 0,0,-1,1 };

void dfs(int x, int y)
{
	a[x][y] = 2;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<1 || yy<1 || xx>n || yy>n)continue;
		if (a[xx][yy] == 0)
			dfs(xx, yy);
	}
}

int main()
{
	int i = 1, j = 1;
	n = read();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = read();
		}
	}
	for (; i <= n; i++)
	{
		if (a[i][j] == 0)
			dfs(i, j);
	}
	i--;
	for (; j <= n; j++)
	{
		if (a[i][j] == 0)
			dfs(i, j);
	}
	j--;
	for (; i >= 1; i--)
	{
		if (a[i][j] == 0)
			dfs(i, j);
	}
	i++;
	for (; j >= 1; j--)
	{
		if (a[i][j] == 0)
			dfs(i, j);
	}
	for (int i = 1; i <= n; i++,cout<<endl)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << 2 - a[i][j] << " ";
		}
	}
	return 0;
}