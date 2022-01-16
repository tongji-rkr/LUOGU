#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 560;
const ll BASE = 1e18;

struct HighPreNum
{
	int len;
	ll s[MAXN];
	HighPreNum()
	{
		len = 0;
		memset(s, 0, sizeof s);
	}
	void operator -=(const HighPreNum& a);
	HighPreNum operator %(const HighPreNum& a);
	bool operator >(const HighPreNum& a);
};

void HighPreNum::operator -=(const HighPreNum& a)
{
	for (int i = len; i >= 1; i--)
	{
		s[i] -= a.s[i];
		if (s[i] < 0) s[i + 1]--, s[i] += BASE;
	}
	while (s[len] == 0 && len > 0)len--;
	return;
}
HighPreNum HighPreNum::operator %(const HighPreNum& a)
{
	while (*this > a)*this -= a;
	return *this;
}
bool HighPreNum::operator >(const HighPreNum& a)
{
	if (len != a.len)return len > a.len;
	for (int i = len; i >= 1; i--)
		if (s[i] != a.s[i]) return s[i] > a.s[i];
	return true;
}
string str;
void read(HighPreNum& a)
{
	cin >> str;
	reverse(str.begin(), str.end());
	int& len = a.len = 0;
	ll strlen = str.length();
	for (ll i = 0, w=1; i < strlen; i++, w *= 10)
	{
		if (i % 18 == 0)
		{
			w = 1;
			++len;
		}
		a.s[len] += w * (ll)(str[i] - '0');
	}
}
void print(HighPreNum& a)
{
	printf("%lld", a.s[a.len]);
	for (int i = a.len - 1; i >= 1; i--)
	{
		printf("%018lld", a.s[i]);
	}
}
int main()
{
	HighPreNum a, b, c;
	read(a), read(b);
	while (b.len)
	{
		c = a % b;
		a = b;
		b = c;
	}
	print(a);
	return 0;
}