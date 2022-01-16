#include<iostream>
using namespace std;

long long d;
int n, m;
long long a[50005];


bool judge(long long x)
{
	int tot = 0;
	int i = 0, now = 0;
	while (i < n + 1)
	{
		i++;
		if (a[i] - a[now] < x)
			tot++;
		else
			now = i;
	}
	if (tot > m)
		return false;
	else
		return true;;
}
int main()
{
	long long ans = 0;
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> d >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	a[n + 1] = d;
	long long l = 0, r = d;
	while (l <= r)
	{
		long long m = l + (r - l) / 2;
		if (judge(m))
		{
			ans = m;
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	cout << ans << endl;
	return 0;
}