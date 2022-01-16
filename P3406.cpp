#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, m;
int t[100005];//每段路过次数

int main()
{
	long long sum = 0;
	long long beg, end;
	int visit = 0;
	long long a, b, c, s = 0;
	n = read(), m = read();
	beg = read();
	for (int i = 2; i <= m; i++)
	{
		end = read();
		t[min(end, beg)]++;
		t[max(end, beg)]--;
		beg = end;
	}
	for (int i = 1; i < n; i++)
	{
		visit += t[i];
		a = read(), b = read(), c = read();
		sum += min(a * visit, b * visit + c);
	}
	cout << sum;
	return 0;
}