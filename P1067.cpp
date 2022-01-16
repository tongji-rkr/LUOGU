#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n;
int a;

int main()
{
	n = read();
	for (int i = n; i >= 1; i--)
	{
		a = read();
		if (a == 0)continue;
		if (a > 0 && i != n)cout << '+';
		if (a != 1)
		{
			if (a == -1)
				cout << '-';
			else
				cout << a;
		}
		cout << 'x';
		if(i>1)cout<<'^' << i;
	}
	a = read();
	if (a > 0)cout << '+';
	if (a != 0)cout << a;
	return 0;
}