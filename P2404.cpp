#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, a[10001] = { 1 };

void print(int t)
{
	for (int i = 1; i <= t - 1; i++)
	{
		cout << a[i] << '+';
	}
	cout << a[t] << endl;
}
void dfs(int s, int t)
{
	for (int i = a[t - 1]; i <= s; i++)
	{
		if (i < n)
		{
			a[t] = i;
			s -= i;
			if (s == 0)print(t);
			else dfs(s, t + 1);
			s += i;
		}
	}
}
int main()
{
	n = read();
	dfs(n, 1);
	return 0;
}