#include<iostream>
using namespace std;

int x[350000];
int y[350000];
int c[350000];


void cover(long long r, long long a,long long b,long long x, long long y)
{
	if (r == 1)
		return;
	int t = 1 + (x > a + r / 2 - 1 ? 2 : 0) + (y > b + r / 2 - 1 ? 1 : 0);
	if (t == 1)
	{
		cout << r / 2 + a << " " << r / 2 + b << " " << t << endl;
		cover(r / 2, a, b, x, y);
		cover(r / 2, a, r / 2 + b, r / 2 + a - 1, r / 2 + b);
		cover(r / 2, r / 2 + a, b, r / 2 + a, r / 2 + b - 1);
		cover(r / 2, r / 2 + a, r / 2 + b, r / 2 + a, r / 2 + b);
	}
	else if (t == 2)
	{
		cout << r / 2 + a << " " << r / 2 + b - 1 << " " << t << endl;
		cover(r / 2, a, b, r / 2 + a - 1, r / 2 + b - 1);
		cover(r / 2, a, r / 2 + b, x, y);
		cover(r / 2, r / 2 + a, b, r / 2 + a, r / 2 + b - 1);
		cover(r / 2, r / 2 + a, r / 2 + b, r / 2 + a, r / 2 + b);
	}
	else if (t == 3)
	{
		cout << r / 2 + a - 1 << " " << r / 2 + b << " " << t << endl;
		cover(r / 2, a, b, r / 2 + a - 1, r / 2 + b - 1);
		cover(r / 2, a, r / 2 + b, r / 2 + a - 1, r / 2 + b);
		cover(r / 2, r / 2 + a, b, x, y);
		cover(r / 2, r / 2 + a, r / 2 + b, r / 2 + a, r / 2 + b);
	}
	else if (t == 4)
	{
		cout << r / 2 + a - 1 << " " << r / 2 + b - 1 << " " << t << endl;
		cover(r / 2, a, b, r / 2 + a - 1, r / 2 + b - 1);
		cover(r / 2, a, r / 2 + b, r / 2 + a - 1, r / 2 + b);
		cover(r / 2, r / 2 + a, b, r / 2 + a, r / 2 + b - 1);
		cover(r / 2, r / 2 + a, r / 2 + b, x, y);
	}
}
int main()
{
	long long x0, y0;
	long long k, r = 1;
	cin >> k >> x0 >> y0;
	for (long long i = 1; i <= k; i++)
	{
		r *= 2;
	}
	cover(r, 1, 1, x0, y0);
	return 0;
}