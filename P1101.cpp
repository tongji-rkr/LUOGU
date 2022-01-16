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
const char aim[6] = "zhong";
const int dx[8] = { -1,1,0,0,-1,-1,1,1 };
const int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
int n, ans;
char map[105][105];
bool a[105][105];

void dfs(int x, int y,int k,int m)
{
	if (m == 5)
	{
		ans = 1;
		return;
	}
	int xx = x + dx[k], yy = y + dy[k];
	if (xx<1 || yy<1 || xx>n || yy>n)return;
	if (map[xx][yy] == aim[m])
		dfs(xx, yy, k, m + 1);
}
int main()
{
	n = read();
	memset(a, false, sizeof a);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 'y')
			{
				for (int k = 0; k < 8; k++)
				{
					ans = 0;
					int xx = i + dx[k], yy = j + dy[k];
					if (xx<1 || yy<1 || xx>n || yy>n)continue;
					if (map[xx][yy] == 'i')
					{
						dfs(xx, yy, k, 0);
						if (ans)
						{
							for (int m = 0; m < 7; m++)
							{
								a[i + m * dx[k]][j + m * dy[k]] = true;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++,cout<<endl)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j])cout << map[i][j];
			else cout << "*";
		}
	}
	return 0;
}