#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, a, b[2];
int ans = -2147483647;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a = read();
		if (i < 2)b[i & 1] = a;
		else b[i & 1] = max(b[!(i & 1)] + a, a);
		ans = max(ans, b[i & 1]);
	}
	cout << ans;
	return 0;
}