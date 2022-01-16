#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n;
int a[105];
int f[105], g[105], s[1005];
int ans;

int main()
{
	n = read();
	for (int i = 1; i <= n;i++)
	{
		a[i] = read();
		f[i] = g[i] = 1;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j] && f[i] < f[j] + 1)
			{
				f[i] = f[j] + 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j] && g[i] < g[j] + 1)
			{
				g[i] = g[j] + 1;
			}
		}
	} 
	int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		s[i] = f[i] + g[i] - 1;//��ÿ��������ߴӵ͵��ߵ������ұߴӸߵ��͵������ 
		if (s[i] > maxx)
		{
			maxx = s[i];
		}
	}
	cout << n - maxx;//������е����� 
	return 0;
}