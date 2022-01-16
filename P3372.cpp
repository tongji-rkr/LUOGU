#include<iostream>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

struct par
{
	long long sum, add;
	int l, r;
}tree[400020];
int n, m,a[100005];

void build(int o, int l, int r)
{
	tree[o].l = l;
	tree[o].r = r;
	if (l == r)
	{
		tree[o].sum = a[l];
		return;
	}
	build(2 * o, l, (l + r) / 2);
	build(2 * o + 1, (l + r) / 2 + 1, r);
	tree[o].sum = tree[2 * o].sum + tree[2 * o + 1].sum;
}
void spread(int p)
{
	if (tree[p].add)
	{
		tree[p * 2].sum += tree[p].add * (tree[p * 2].r - tree[p * 2].l + 1);
		tree[p * 2 + 1].sum += tree[p].add * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1);
		tree[p * 2].add += tree[p].add;
		tree[p * 2 + 1].add += tree[p].add;
		tree[p].add = 0;
	}
}
long long query(int o, int l, int r)
{
	if (tree[o].l >= l && tree[o].r <= r)
	{
		return tree[o].sum;
	}
	spread(o);
	int mid = (tree[o].l + tree[o].r) / 2;
	long long result = 0;
	if (l <= mid)
		result += query(2 * o, l, r);
	if (r > mid)
		result += query(2 * o + 1, l, r);
	return result;
}
void change(int p, int x, int y, int z)
{
	if (x <= tree[p].l && y >= tree[p].r)
	{
		tree[p].sum += (long long)z * (tree[p].r - tree[p].l + 1);
		tree[p].add += z;//打上懒标记
		return;
	}
	spread(p);
	int mid = (tree[p].l + tree[p].r)/2;
	if (x <= mid) change(p * 2, x, y, z);
	if (y > mid) change(p * 2 + 1, x, y, z);
	tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}
int main()
{
	int p, x, y, k;
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		p = read(), x = read(), y = read();
		if (p == 1) k = read(), change(1, x, y, k);
		else cout << query(1, x, y) << endl;
	}
	return 0;
}