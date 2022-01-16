#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

struct Node
{
	int ord, s;
}b[100005];
int w[100005], n, r, k;
int ans;

bool cmp(Node& a,Node& b)
{
	if (a.s != b.s)
		return a.s > b.s;
	else
		return a.ord < b.ord;
}
int main()
{
	n = read(), r = read(), k = read();
	n *= 2;
	for (int i = 1; i <= n; i++)
	{
		b[i].ord = i;
		b[i].s = read();
	}
	for (int i = 1; i <= n; i++)
	{
		w[i] = read();
	}
	for (int i = 1; i <= r; i++)
	{
		sort(b + 1, b + 1 + n, cmp);
		for(int j = 1; j <= n; j+=2)
		{
			if (w[b[j].ord] > w[b[j+1].ord])
				b[j].s++;
			else if (w[b[j].ord] < w[b[j+1].ord])
				b[j + 1].s++;
			else
			{
				if (b[j].ord < b[j + 1].ord)
					b[j].s++;
				else
					b[j + 1].s++;
			}
		}
	}
	sort(b + 1, b + 1 + n, cmp);
	cout << b[k].ord;
	return 0;
}