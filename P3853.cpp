#include<iostream>
using namespace std;

int l, n, k;
int a[100005];

bool judge(int x)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		sum += (a[i + 1] - a[i] - 1) / x;
	}
	if (sum > k)
		return false;
	else
		return true;
}
int main()
{
	cin >> l >> n >> k;
	int left = 0, right = l / k + 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans=0;
	while (left <= right)
	{
		int m = right + (left - right) / 2;
		if (judge(m))
		{
			ans = m;
			right = m - 1;
		}
		else
		{
			left = m + 1;
		}
	}
	cout << ans << endl;
	return 0;
}