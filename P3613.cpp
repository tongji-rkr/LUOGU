#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, k;
map<int, map<int, int>> ma;

int main()
{
	int p, x, y, z;
	n = read(), k = read();
	for (int i = 1; i <= k; i++)
	{
		p = read(), x = read(), y = read();
		if (p == 1)
			z = read(), ma[x][y] = z;
		else
			cout << ma[x][y] << endl;
	}
	return 0;
}