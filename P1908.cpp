#include<iostream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, a[500005], c[500005];
long long sum;

void msort(int l, int r)
{
	int k = l;
	if (r == l)return;
	int m = (l + r) / 2, i = l, j = m + 1;
	msort(l, m), msort(m + 1, r);
	while (i <= m && j <= r)
	{
		if (a[i] <= a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++], sum += m + 1 - i;
	}
	while (i <= m)c[k++] = a[i++];
	while (j <= r)c[k++] = a[j++];
	for (int s = l; s <= r; s++)a[s] = c[s];
	return;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)a[i] = read();
	msort(1, n);
	printf("%lld", sum);
	return 0;
}