#include<iostream>
using namespace std;

int n, m;
long long a[100005];


bool judge(long long x)
{
	int tot = 0;
	long long s = x;
	int i = 0;
	while (i < n)
	{
		i++;
		if (a[i] <= s)
		{
			s -= a[i];
		}
		else
		{
			tot++;
			s = x - a[i];
			if (s < 0)
				return false;
		}
	}
	tot++;
	if (tot > m)
		return false;
	else
		return true;;
}
int main()
{
	long long sum = 0;
	long long ans = 0;
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	long long l = 0, r = sum;
	while (l <= r)
	{
		long long m = l + (r - l) / 2;
		if (judge(m))
		{
			ans = m;
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << ans << endl;
	return 0;
}