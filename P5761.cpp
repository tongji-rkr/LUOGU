#include<iostream>
using namespace std;

int a[20005],s[20005];
int m, n;
int nmin;
int ans=-1e9;

int main()
{
	int x;
	cin >> m >> n;
	n -= 1;
	for (int j = 1; j <= n; j++)
	{
		a[j] = -1e9;
	}
	for (int i = 1; i <= m; i++) 
	{	
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			a[j] = max(a[j], x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, s[i] - nmin);
		if (nmin > s[i])nmin = s[i];
	}
	cout << ans << endl;
	return 0;
}