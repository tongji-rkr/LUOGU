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

int n, k;
int a[100005];

bool judge(int x)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)sum += a[i] / x;
	if (sum >= k)
		return true;
	else
		return false;
}
int main()
{
	long long t = 0;
	n = read(), k = read();
	for (int i = 1; i <= n; i++)a[i] = read(), t += a[i];
	int l = 0, r = t / k;
	if (r <=1)
	{
		cout << r << endl;
		return 0;
	}
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