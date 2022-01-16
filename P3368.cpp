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

int tree[500010], a[500010], n, m;

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
	int x, y, z, k;
	n = read(), m = read();
	for (int i = 1; i <= n; i++)a[i] = read();
	for (int i = 1; i <= m; i++)
	{
		x = read();
		if (x == 1)
		{
			y = read(), z = read(), k = read();
			add(y, k);
			add(z + 1, -k);
		}
		else
		{	
			y = read(); 
			printf("%d\n", a[y] + sum(x));
		}
	}
	return 0;
}