#include <iostream>
#include <vector>
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

int n;
vector<int> s[16005];
int a[16005];
bool b[16005];

void dfs(int x)
{
	for (int i : s[x])
	{
		dfs(i);
		if (a[i] > 0)a[x] += a[i];
	}
}
int main()
{
	int x, y;
	int flag = 0,nmax=-1e9;
	memset(b, false, sizeof b);
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		if (a[i] > 0)flag = 1;
		if (a[i] > nmax)nmax = a[i];
	}
	if (!flag)
	{
		cout << nmax;
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		x = read(), y = read();
		s[y].push_back(x);
		b[x] = true;
	}
	int i = 1;
	for (; i <= n && b[i]; i++);
	dfs(i);
	cout << a[i];
	return 0;
}