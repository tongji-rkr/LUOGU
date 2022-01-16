#include<iostream>
#include<queue>
using namespace std;

#define NUM 80112002
int n, m;
long long ans;
int a[5005][5005],b[5005],c[5005],d[5005];
queue<int> q;

int main()
{
	int x, y;
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		b[x]++;
		c[y]++;
		a[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 0)
		{
			d[i] = 1;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int t = q.front(); q.pop();
		for (int i = 0; i <= n; i++)
		{
			if (a[i][t] == 0)continue;
			d[i] += d[t];
			d[i] %= NUM;
			c[i]--;
			if (c[i] == 0)
			{
				if (b[i]==0)
				{
					ans += d[i];
					ans %= NUM;
					continue;
				}
				q.push(i);
			}
		}
	}
	cout << ans << endl;
	return 0;
}