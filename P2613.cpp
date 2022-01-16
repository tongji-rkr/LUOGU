#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N = 19260817;
const int MAXN = 1200;
const int BASE = 1e9;

inline ll mi(ll a, ll b)
{
	ll ans = 1;
	a %= N;
	while (b)
	{
		if (b & 1) ans = ans * a % N;
		b >>= 1;
		a = a * a % N;
	}
	return ans;
}

inline int getint()
{
	int res = 0, ch = getchar();
	while (!isdigit(ch) and ch != EOF)
		ch = getchar();
	while (isdigit(ch))
	{
		res = (res << 3) + (res << 1) + (ch - '0');
		res %= N;//直接对MOD取余
		ch = getchar();
	}
	return res;
}
int main()
{
	ll a = getint(), b = getint();
	ll ans = a * mi(b, N - 2) % N;
	cout<<ans<<endl;
	return 0;
}