#include<iostream>
#include<algorithm>
using namespace std;

int n, m, s, t;
int fa[10005];
struct road
{
	int u,v;
	int w;
}a[20005];
bool cmp(road& s1, road& s2)
{
	return s1.w < s2.w;
}
int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
int main()
{
	cin >> n >> m >> s >> t;
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
		}
		if (find(s) == find(t))
		{
			cout << a[i].w << endl;
			break;
		}
	}
	return 0;
}