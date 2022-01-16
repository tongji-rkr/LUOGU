#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

vector<pair<int, int>> son[1510];
int n, m;
int ans[1510];

void dfs(int k,int len,int num)
{
	if (k == n)
	{
		ans[num] = max(ans[num], len);
		return;
	}
	for (auto& i : son[k])
	{
		if (i.first > num)
		{
			if (i.first!=n&&!ans[i.first])continue;
			dfs(n, len + i.second + ans[i.first], num);
		}
		else 
			dfs(i.first, len + i.second, num);
	}
	return;
}
int main()
{
	int x, y, w;
	n = read();
	m = read();
	for (int i = 1; i <= m; i++)
	{
		x = read(), y = read(), w = read();
		son[x].emplace_back(y, w);
	}
	for (int i = n-1; i >= 1; i--)dfs(i, 0, i);
	if (ans[1])cout << ans[1];
	else cout << -1;
	return 0;
}