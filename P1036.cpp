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

int n,k;
int a[22];
int ans;
bool used[22];

int judge(int x)
{
	if (x <= 1)return 0;
	if (x == 2)return 1;
	if (x > 2 && x % 2 == 0)return 0;
	for (int i = 3; i <= sqrt(x); i += 2)
	{
		if (x % i == 0)return 0;
	}
	return 1;
}
void dfs(int m, int sum,int last)
{
	if (m == k)ans += judge(sum);
	for (int i = 1; i <= n; i++)
	{
		if (last>=i||used[i])continue;
		used[i] = 1;
		dfs(m + 1, sum + a[i], i);
		used[i] = 0;
	}
}

int main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++)a[i] = read();
	memset(used, false, sizeof used);
	dfs(0, 0,0);
	cout << ans;
	return 0;
}