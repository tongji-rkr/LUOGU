#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int a, b, n, m;

int main()
{
	int x, y;
	n = read();
	for (int i = 1; i <= (1 << (n - 1)); i++)
	{
		m = read();
		if (a < m)a = m, x = i;
	}
	for (int i = (1 << (n - 1))+1; i <= (1 << n); i++)
	{
		m = read();
		if (b < m)b = m, y = i;
	}
	if (a > b)cout << y;
	else cout << x;
	return 0;
}