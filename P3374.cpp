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

int tree[800020], n, m;

int lowbit(int x)
{
	return x & -x;
}

void add(int k, int a)
{
	while (k <= n) 
	{
		tree[k] += a;
		k += lowbit(k);
	}
}
int sum(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += tree[x];
		x -= lowbit(x);
	}
	return res;
}
int main()
{
	int a;
	int x, y, z;
	n = read(), m = read();
	for (int i = 1; i <= n; i++)a = read(), add(i, a);
	for (int i = 1; i <= m; i++)
	{
		x = read(), y = read(), z = read();
		if (x == 1)add(y, z);
		else printf("%d\n", sum(z)-sum(y-1));
	}
	return 0;
}