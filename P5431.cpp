#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;

const int N = 5e6 + 5;
ll n, p, k;
ll sum;
ll a[N],b[N];

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline ll mi(ll a, ll b,ll p)
{
	ll ans = 1;
	a %= p;
	while (b)
	{
		if (b & 1) ans = ans * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}

int main()
{
	n = read(), p = read(), k = read();
	b[n + 1] = 1;
	for (int i = 1; i <= n; i++)
	{
		a[i]=read();
	}
	ll pre=1,w=k;
	for (int i = n; i >= 1; i--)
	{
		b[i] = (b[i + 1] * a[i]) % p;
	}
	for (int i = 1; i <= n; i++)
	{
		sum = (sum + ((w * pre) % p) * b[i + 1] % p) % p;
		w = w * k % p;
		pre = pre * a[i] % p;
	}
	sum = (sum * mi(b[1], p - 2, p)) % p;
	cout << sum << endl;
	return 0;
}