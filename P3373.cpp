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
	long long sum, add, mul;
	int l, r;
}tree[400020];
int n, m, p, a[100005];

void build(int o, int l, int r)
{
	tree[o].l = l;
	tree[o].r = r;
	tree[o].add = 0;
	tree[o].mul = 1;
	if (l == r)
	{
		tree[o].sum = a[l];
		return;
	}
	build(2 * o, l, (l + r) / 2);
	build(2 * o + 1, (l + r) / 2 + 1, r);
	tree[o].sum = (tree[2 * o].sum + tree[2 * o + 1].sum) % p;
}
void spread(int root,int l,int r)
{
	int m = (l + r) / 2;
	tree[root * 2].sum = (tree[root].mul * tree[root * 2].sum + tree[root].add*(m - l + 1)) % p;
	tree[root * 2 + 1].sum = (tree[root].mul * tree[root * 2 + 1].sum + tree[root].add * (r - m)) % p;
	tree[root * 2].mul = (tree[root].mul * tree[root * 2].mul) % p;
	tree[root * 2 + 1].mul = (tree[root].mul * tree[root * 2 + 1].mul) % p;
	tree[root * 2].add = (tree[root * 2].add * tree[root].mul + tree[root].add) % p;
	tree[root * 2 + 1].add = (tree[root * 2 + 1].add * tree[root].mul + tree[root].add) % p;
	tree[root].mul = 1;
	tree[root].add = 0;
	return;
}
long long query(int o, int l, int r)
{
	if (tree[o].l >= l && tree[o].r <= r)
	{
		return tree[o].sum % p;
	}
	spread(o, tree[o].l, tree[o].r);
	int mid = (tree[o].l + tree[o].r) / 2;
	long long result = 0;
	if (l <= mid) result = (result + query(2 * o, l, r)) % p;
	if (r > mid) result = (result + query(2 * o+1, l, r)) % p;
	return result;
}
void add(int o, int x, int y, long long z)
{
	if (x <= tree[o].l && y >= tree[o].r)
	{
		tree[o].sum = (tree[o].sum + z * (tree[o].r - tree[o].l + 1)) % p;
		tree[o].add = (tree[o].add + z) % p;//打上懒标记
		return;
	}
	spread(o, tree[o].l, tree[o].r);
	int mid = (tree[o].l + tree[o].r) / 2;
	if (x <= mid) add(o * 2, x, y, z);
	if (y > mid) add(o * 2 + 1, x, y, z);
	tree[o].sum = (tree[2 * o].sum + tree[2 * o + 1].sum) % p;
}
void mul(int o, int x, int y, long long z)
{
	if (x <= tree[o].l && y >= tree[o].r)
	{
		tree[o].sum = (tree[o].sum * z) % p;
		tree[o].mul = (tree[o].mul * z) % p;
		tree[o].add = (tree[o].add * z) % p;
		return;
	}
	spread(o, tree[o].l, tree[o].r);
	int mid = (tree[o].l + tree[o].r) / 2;
	if (x <= mid) mul(o * 2, x, y, z);
	if (y > mid) mul(o * 2 + 1, x, y, z);
	tree[o].sum = (tree[2 * o].sum + tree[2 * o + 1].sum) % p;
}
int main()
{
	int q, x, y;
	long long k;
	n = read(), m = read(), p = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read() % p;
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		q = read(), x = read(), y = read();
		if (q == 1) k = read(), mul(1, x, y, k);
		else if (q == 2) k = read(), add(1, x, y, k);
		else cout << query(1, x, y) << endl;
	}
	return 0;
}