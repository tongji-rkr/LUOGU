#include <iostream>
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
long long m;
int a[1000005];

bool judge(int x)
{
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > x)sum += a[i] - x;
	}
	if (sum >= m)
		return true;
	else
		return false;
}
int main()
{
	int l = 0, r = 0;
	n = read(), m = read();
	for (int i = 1; i <= n; i++)a[i] = read(), r = max(r, a[i]);
	int ans = 0;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (judge(m))
		{
			ans = m;
			l = m + 1;
		}
		else
			r = m - 1;
	}
	cout << ans << endl;
	return 0;
}