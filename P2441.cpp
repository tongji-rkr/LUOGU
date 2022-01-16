#include<iostream>
using namespace std;

const int MAXN = 200010;
int n, k;
int boss[MAXN], a[MAXN];

int gcd(int a, int b)
{
	if (b) while ((a %= b) && (b %= a));
	return a + b;
}
void ask(int x,int y)
{
	if (!x)
	{
		cout << -1 << endl;
	}
	else
	{
		if (gcd(a[x], a[y]) > 1)
			cout << x << endl;
		else
		{
			ask(boss[x], y);
		}
	}
}

int main()
{
	int x, y, w;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> x >> y;
		boss[y] = x;
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> x;
		if (x == 1)
		{
			cin >> y;
			ask(boss[y],y);
		}
		else
		{
			cin >> y >> w;
			a[y] = w;
		}
	}
	return 0;
}