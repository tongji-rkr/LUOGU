#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

const int NUM = 1e9 + 7;
int n, s = 1e9, e = -1e9;
int ma[100005];
long long ans;

int main()
{
	int m;
	n = read();
	for (int i = 1; i <= n; i++)
	{
		m = read();
		ma[m]++;
		s = min(s, m);
		e = max(e, m);
	}
	for(int i=s+1;i<=e;i++)
	{
		if (ma[i]<=1)continue;
		for (int j = s; j <= i / 2; j++)
		{
			if (ma[j] && ma[i - j])
			{
				if (j != i - j)
					ans = (ans + ((ma[i] * (ma[i] - 1)) >> 1) * ma[j] * ma[i - j]) % NUM;
				else
					ans = (ans + ((ma[i] * (ma[i] - 1)) >> 1) * ((ma[j] * (ma[j]-1)) >> 1) % NUM) % NUM;
			}
		}
	}
	cout << ans % NUM;
	return 0;
}