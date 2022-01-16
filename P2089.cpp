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

int n, m;
int a[10];
int ans[10000][10];

void dfs(int sum, int k)
{
	if (k==10&&sum == n)
	{
		m++;
		for (int i = 0; i < 10; i++)ans[m][i] = a[i];
	}
	else if (sum > n);
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			a[k] = i;
			dfs(sum + i, k + 1);
		}
	}
}
int main()
{
	n = read();
	if (n < 10 || n>30)
	{
		cout << 0;
		return 0;
	}
	dfs(0, 0);
	cout << m << endl;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < 10; j++)cout << ans[i][j] << ' ';
		cout << endl;
	}
	return 0;
}