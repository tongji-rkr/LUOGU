#include<iostream>
#include<cmath>
using namespace std;

int n;
int a0, a1, b0, b1;

int gcd(int a, int b)
{
	if (b) while ((a %= b) && (b %= a));
	return a + b;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		cin >> a0 >> a1 >> b0 >> b1;
		int k = b1 / b0;
		while (1)
		{
			int s = gcd(b0, k);
			if (s == 1)break;
			b0 /= s;
			k *= s;
		}
		if (a1 % (gcd(k, a0)))
		{
			cout << 0 << endl;
			continue;
		}
		a1 /= gcd(k, a0);
		int t = sqrt(b0);
		for (int i = 1; i <= t; i++)
		{
			if (b0 % i == 0)
			{
				if (gcd(i, a0) == a1)
					ans++;
				if (i != b0 / i && gcd(b0 / i, a0) == a1)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}