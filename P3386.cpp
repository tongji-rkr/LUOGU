#include<iostream>
using namespace std;

int g[505][505];
int mch[505], vis[505];
int n, m, e, ans;

bool dfs(int k, int tag)
{
	if (vis[k] == tag)return false;
	vis[k] = tag;
	for (int i = 1; i <= m; i++)
	{
		if (g[k][i] && (!mch[i] || dfs(mch[i], tag)))
		{
			mch[i] = k;
			return true;
		}
	}
	return false;
}

int main()
{
	int u, v;
	cin >> n >> m >> e;
	for (int i = 1; i <= e; i++)
	{
		cin >> u >> v;
		g[u][v] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (dfs(i, i))++ans;
	}
	cout << ans << endl; 
	return 0;
}