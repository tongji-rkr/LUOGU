#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, t, k, x, ans;
int na[100005];
struct node
{
	int s, t;
};
queue<node> q;
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		t = read(), k = read();
		while (!q.empty())
		{
			node h = q.front();
			if (h.t + 86400 <= t)
			{
				q.pop();
				na[h.s]--;
				if (na[h.s] == 0)ans--;
			}
			else
				break;
		}
		for (int j = 1; j <= k; j++)
		{
			x = read();
			node h;
			h.t = t;
			h.s = x;
			q.push(h);
			na[x]++;
			if (na[x] == 1)ans++;
		}
		cout << ans << endl;
	}
	return 0;
}