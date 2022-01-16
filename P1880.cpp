#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int a[305],sum[305];
int dpmax[305][305], dpmin[305][305];
int n, max1, min1=100000000;

int main()
{
	n = read();
	for (int i = 1; i <= n + n; i++)  
	{
		if (i <= n)a[i] = read();
		a[i + n] = a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int gap = 1; gap < n; gap++)
	{
		for (int i = 1; i + gap < 2*n; i++)
		{
			int j = i + gap;
			dpmin[i][j] = 100000000;
			for (int k = i; k < j; k++)
			{
				dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k+1][j] + sum[j] - sum[i - 1]);
				dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k+1][j] + sum[j] - sum[i - 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		max1 = max(max1, dpmax[i][i + n - 1]);
		min1 = min(min1, dpmin[i][i + n - 1]);
	}
	cout << min1 << endl << max1;
	return 0;
}