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

int n, s[11], b[11];
int ans = 1000000000;
bool used[11];

void dfs(int ms, int mb,int m)
{
	if (m&&fabs(mb - ms) < ans)ans = fabs(mb - ms);
	for (int i = 1; i <= n; i++)
	{
		if (used[i])continue;
		used[i] = 1;
		dfs(ms * s[i], mb + b[i], m + 1);
		used[i] = 0;
	}
}
int main()
{
	memset(used, false, sizeof used);
	n = read();
	for (int i = 1; i <= n; i++)
		s[i] = read(), b[i] = read();
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}