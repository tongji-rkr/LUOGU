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
struct stick
{
	int l, w;
}a[5005];
int f[5005];
int n, ans;

bool cmp(stick& s1, stick& s2)
{
	if (s1.l > s2.l)return true;
	else if (s1.l == s2.l)
	{
		if (s1.w > s2.w)
			return true;
	}
	return false;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i].l = read(), a[i].w = read();
	sort(a + 1, a + n + 1,cmp);
	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (a[i].w > a[j].w) f[i] = max(f[i], f[j] + 1);
		}
		ans = max(ans, f[i]);		//更新ans的值
	}
	cout << ans + 1;
	return 0;
}