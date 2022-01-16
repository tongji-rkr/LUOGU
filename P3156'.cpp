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
int a[2000005], x;

int main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++)a[i] = read();
	for (int i = 1; i <= k; i++)x=read(),cout << a[x] << endl;
	return 0;
}