#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b)
{
	if (b) while ((a %= b) && (b %= a));
	return a + b;
}
int n;

int main()
{
	int x, y;
	cin >> n;
	int i = 1;
	for (; i <= n; i++)
	{
		cin >> x;
		x = abs(x);
		if (x)break;
	}
	i++;
	for (; i <= n; i++)
	{
		cin >> y;
		y = abs(y);
		if (y)
		{
			x = gcd(x, y);
		}
	}
	cout << x << endl;
	return 0;
}