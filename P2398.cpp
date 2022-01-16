#include<iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
ll n;
ll f[MAXN];
ll ans;
int main()
{
	cin >> n;
	for (int i = n; i >= 1; i--)
	{
		f[i] = n / i * (n / i);
		for (int j = 2*i; j <= n; j+=i)
		{
			f[i] -= f[j];
		}
		ans += f[i] * i;
	}
	cout << ans << endl;
	return 0;
}