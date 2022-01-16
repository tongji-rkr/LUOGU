#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<iomanip>
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

int n;
pair<int, int> a[1000005];
int ans, k;

bool cmp(pair<int, int>& s1, pair<int, int>& s2)
{
	return s1.second < s2.second;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].first = read();
		a[i].second = read();
	}
	sort(a + 1, a + 1 + n, cmp);
	int s = 0;
	while (1)
	{
		for (k++; k <= n; k++)
		{
			if (a[k].first >= s)break;
		}
		if (k == n + 1)break;
		ans++;
		s = a[k].second;
	}
	cout << ans;
	return 0;
}