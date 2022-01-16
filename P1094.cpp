#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

priority_queue <int, vector<int>, greater<int> > q;
int w;
int n, ans;
int a[30005];

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	w = read(), n = read();
	for (int i = 1; i <= n; i++)a[i] = read();
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (q.empty())
			q.push(a[i]);
		else
		{
			int t = q.top();
			if (t + a[i] <= w)
			{
				q.pop();
				ans++;
			}
			else
			{
				q.push(a[i]);
			}
		}
	}
	cout << ans + q.size();
	return 0;
}