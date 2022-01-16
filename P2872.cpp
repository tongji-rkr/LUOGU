#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

typedef long long ll;
struct NODE
{
	 ll x, y;
}b[1005];
struct EDGE
{
	int u, v;
	double c;
	bool operator <(EDGE& s1)
	{
		return c < s1.c;
	}
}a[501000];
int n, m, k, t;
int fa[1005];
double ans;

double dis(int i, int j)
{
	return sqrt((b[i].x - b[j].x) * (b[i].x - b[j].x) + (b[i].y - b[j].y) * (b[i].y - b[j].y));
}
int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
int main()
{
	int ma, mb, fa1 = 0, fa2 = 0;
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		b[i].x = read(), b[i].y = read();
		for (int j = 1; j < i; j++)
		{
			a[++k].u = j;
			a[k].v = i;
			a[k].c = dis(i, j);
		}
	}
	sort(a + 1, a + 1 + k);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		ma = read(), mb = read();
		fa[find(ma)] = find(mb);
	}
	for (int i = 1; i <= k; i++)
	{
		fa1 = find(a[i].u);
		fa2 = find(a[i].v);
		if (fa1 != fa2)
		{
			fa[fa1] = fa2;
			t++;
			ans += a[i].c;
		}
		if (t == n - 1)break;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << ans;
	return 0;
}