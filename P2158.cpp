#include<iostream>
#include<cmath>
using namespace std;

int n;
int a[40010];
int main()
{
	int ans = 0;
	cin >> n;
	n--;
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		a[i] = i - 1;
		int num = sqrt(i);
		for (int j = 2; j <= num; j++)
		{
			if (i % j == 0)
			{
				a[i] -= a[j];
				if (i / j != j)a[i] -= a[i / j];
			}
		}
		ans += a[i];
	}
	ans = 2 * ans + 3;
	cout << ans << endl;
	return 0;
}