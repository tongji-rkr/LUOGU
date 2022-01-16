#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
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

int n, ans;
int f[6005][2], r[6005],v[6005];
vector<int> son[6005];

void dfs(int x)
{
	f[x][0] = 0, f[x][1] = r[x];
	for (int i = 0; i < son[x].size(); i++)
	{
		int y = son[x][i];
		dfs(y);
		f[x][0] += max(f[y][0], f[y][1]);
		f[x][1] += f[y][0];
	}
}
int main()
{
	int a, b;
	n = read();
	for (int i = 1; i <= n; i++)r[i] = read();
	for (int i = 1; i <= n; i++)a = read(), b = read(), son[b].push_back(a), v[b] = 1;
	int root=0;
	for (int i = 1; i <= n; i++)
		if (!v[i]) { root = i; break; }
	dfs(root);
	cout << max(f[root][0], f[root][1]) << endl;

	return 0;
}