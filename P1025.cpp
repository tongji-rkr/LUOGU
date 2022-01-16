#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, k;
int ans;

void dfs(int x,int last,int total)
{
	if (total + last > n)return;
	if (x == k - 1)
	{
		ans++;
		return;
	}
	for (int i = last; i <= n; i++)
	{
		dfs(x + 1, i, total + i);
	}
}
int main()
{
	n = read(), k = read();
	dfs(0, 1, 0);
	cout << ans;
	return 0;
}