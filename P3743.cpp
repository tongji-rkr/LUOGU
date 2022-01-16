#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n;
double p, l, r=1e10, sum;
double a[200000], b[200000];

bool check(double x)
{
	double tot = p * x;
	sum = 0;
	for (int i = 1; i < +n; i++)
	{
		if (a[i] * x > b[i])
		{
			sum += a[i] * x - b[i];
		}
	}
	return sum <= tot;
}

int main()
{
	
	cin >> n >> p;
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i], sum += a[i];
	if (sum <= p) {
		cout << -1.000000 << endl;
		return 0;
	}
	while (r-l>1e-6)
	{
		double m = (l + r) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	cout << l;
	return 0;
}