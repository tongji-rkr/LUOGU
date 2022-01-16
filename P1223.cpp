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
pair<int,int> a[1005];
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].first = read();
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	double s = 0;
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cout << a[i].second << ' ';
		s += a[i - 1].first;
		ans += s;
	}
	cout << endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << ans / n;
	return 0;
}