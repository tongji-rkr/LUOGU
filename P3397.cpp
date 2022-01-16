#include<iostream>
#include<cstdio>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int a[1005][1005];
int x0, x2, yk, y2;
int n, m;

int main()
{
	n = read();
	m = read();
	for (int i = 1; i <= m; i++)
	{
		x0 = read(), yk = read(), x2 = read(), y2 = read();
		for (int x = x0; x <= x2; x++)
		{
			for (int y = yk; y <= y2; y++)
			{
				a[x][y]++;
			}
		}
	}
	for (int i = 1; i <= n; i++,cout<<endl)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << ' ';
		}
	} 
	return 0;
}