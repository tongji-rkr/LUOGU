#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int a[32];

void f(int x)
{
	int cnt = 0;
	while (x)
	{
		a[cnt] = (a[cnt] + x % 2) % 2;
		cnt++;
		x = x / 2;
	}
}
int main()
{
	int x;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		f(x);
	}
	int ans = 0, k = 1;
	for (int i = 0; i < 32; i++,k*=2)
	{
		ans += k * a[i];
	}
	cout << ans << endl;
	return 0;
}