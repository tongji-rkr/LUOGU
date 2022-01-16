#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, lens = 1, lenm = 1, lena = 1;
int sum[4010] = { 0, 1 }, maxn[4010] = { 0, 1 }, ans[4010];

struct tmp
{
	int l, r;
	bool operator < (const tmp& x) const
	{
		return l * r < x.l* x.r;
	}
}coin[1001];

void mul(int x)
{
	int tmp = 0;
	for (int i = 1; i <= lens; i++)sum[i] *= x;
	for (int i = 1; i <= lens; i++)
	{
		tmp += sum[i];
		sum[i] = tmp % 10;
		tmp /= 10;
	}
	while (tmp != 0)
	{
		lens++;
		sum[lens] = tmp % 10;
		tmp /= 10;
	}
}

void div(int x)
{
	memset(ans, 0, sizeof(ans));
	lena = lens;
	int tmp = 0;
	for (int i = lena; i >= 1; i--)
	{
		tmp *= 10;
		tmp += sum[i];
		if (tmp >= x)
		{
			ans[i] = tmp / x;
			tmp %= x;
		}
	}
	while (ans[lena] == 0)
	{
		if (lena == 1)
			break;
		lena--;
	}
}

void max()
{
	if (lena > lenm)
	{
		for (int i = 1; i <= lena; i++)
			maxn[i] = ans[i];
		lenm = lena;
	}
	else if (lena == lenm)
	{
		for (int i = lena; i >= 1; i--)
		{
			if (maxn[i] < ans[i])
			{
				for (int j = 1; j <= lena; j++)
					maxn[j] = ans[j];
				lenm = lena;
				break;
			}
		}
	}
}

int main()
{
	n = read();
	coin[0].l=read(),coin[0].r=read();
	for (int i = 1; i <= n; i++)coin[i].l = read(), coin[i].r = read();
	sort(coin + 1, coin + n + 1);
	for (int i = 1; i <= n; i++)
	{
		mul(coin[i - 1].l);
		div(coin[i].r);
		max();
	}
	for (int i = lenm; i >= 1; i--)
		printf("%d",maxn[i]);
	return 0;
}