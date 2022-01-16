#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int t, n, h, r;
int fa[1005];
vector<int> up, down;
struct node
{
	long long x, y, z;
}a[1005];
int find(int x)
{
	if (fa[x] == x)
		return x;
	else
		return fa[x] = find(fa[x]);
}

double dis(int i, int j)
{
	return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y) + (a[i].z - a[j].z) * (a[i].z - a[j].z));
}
int main()
{
	t = read();
	for(int i=1;i<=t;i++)
	{
		up.clear();
		down.clear();
		n = read(),h=read(),r=read();
		for (int j = 1; j <= n; j++)
		{
			fa[j] = j;
		}
		for (int k = 1; k <= n; k++)
		{
			a[k].x = read(), a[k].y = read(), a[k].z = read();
			if (a[k].z + r >= h)up.push_back(k);
			if (a[k].z - r <= 0)down.push_back(k);
		}
		for (int li = 1; li <= n; li++)
		{
			for (int lj = li + 1; lj <= n; lj++)
			{
				if (dis(li, lj) <= 2 * r)
					fa[find(li)] = find(lj);
			}
		}
		int s = 0;
		for (int li : up)
		{
			for (int lj : down)
			{
				if (find(li) == find(lj))
				{
					s = 1;
					break;
				}
			}
		}
		if (s == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
