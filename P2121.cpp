#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;
int fa[100100];
int ans;
struct edge
{
	int u, v;
	int w;
}a[100100];
bool cmp(edge& s1, edge& s2)
{
	return s1.w > s2.w;
}
int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1, a + 1 + m, cmp);
	for (int i = 1; i <= m; i++)
	{
		if (find(a[i].u) != find(a[i].v))
		{
			fa[find(a[i].u)] = find(a[i].v);
			ans += a[i].w;
			k--;
		}
		if (k == 0)break;
	}
	cout << ans << endl;
	return 0;
}