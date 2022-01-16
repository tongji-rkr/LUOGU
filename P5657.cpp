#include<iostream>
using namespace std;

typedef long long ll;

int n;
ll k;

void f(int n, ll k)
{
	if (!n)return;
	if (k >= (ll)1 << (n - 1))
	{
		cout << 1;
		k = ((ll)1 << n) - 1 - k;
	}
	else
	{
		cout << 0;
	}
	f(n - 1, k);
}
int main()
{
	int m=1;
	cin >> n >> k;
	f(n, k);
	return 0;
}