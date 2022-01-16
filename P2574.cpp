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
	int sum, add;
	int l, r;
}tree[800020];
int n, m, a[200005];
char s[200005];

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
void spread(int p,int len)
{
	if (tree[p].add)
	{
		tree[p * 2].sum = len - (len / 2) - tree[p * 2].sum;
		tree[p * 2 + 1].sum = len / 2 - tree[p * 2 + 1].sum;
		tree[p * 2].add ^= 1;
		tree[p * 2 + 1].add ^= 1;
		tree[p].add = 0;
	}
}
int query(int o, int x, int y)
{
	if (tree[o].l >= x && tree[o].r <= y)
	{
		return tree[o].sum;
	}
	spread(o, tree[o].r - tree[o].l + 1);
	int mid = (tree[o].l + tree[o].r) / 2;
	int result = 0;
	if (x <= mid)result += query(2 * o, x, y);
	if (y > mid)result += query(2 * o + 1, x, y);
	return result;
}
void change(int p, int x, int y)
{
	if (x <= tree[p].l && y >= tree[p].r)
	{
		tree[p].sum = (tree[p].r - tree[p].l + 1) - tree[p].sum;
		tree[p].add ^= 1;//打上懒标记
		return;
	}
	spread(p, tree[p].r - tree[p].l + 1);
	int mid = (tree[p].l + tree[p].r) / 2;
	if (x <= mid) change(p * 2, x, y);
	if (y > mid) change(p * 2 + 1, x, y);
	tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
}
int main()
{
	int p, x, y;
	n = read(), m = read();
	for (int i = 1; i <= n; i++)cin >> s[i];
	for (int i = 1; i <= n; i++)a[i] = s[i] - '0';
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		p = read(), x = read(), y = read();
		if (p == 0) change(1, x, y);
		else cout << query(1, x, y) << endl;
	}
	return 0;
}