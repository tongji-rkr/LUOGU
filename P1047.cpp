#include<iostream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, q;
int a[10005];

int main()
{
	n = read(), q = read();
	for (int i = 0; i <= n; i++)
		a[i] = 1;
	for (int i = 1; i <=q; i++)
	{
		int x, y;
		x = read(), y = read();
		for (int j = x; j <= y; j++)
			a[j] = 0;
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans += a[i];
	cout << ans;
	return 0;
}