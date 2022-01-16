#include<iostream>
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

void output(int x,int dkr,int dkl)
{
	int pl = 0;
	if (x == 0)
	{
		cout << "(0)";
		return;
	}
	if (x == 1)
	{
		return;
	}
	if (dkl == 0)dkl = 1;
	else cout << '(';
	int num[15] = { 0 };
	for (int i = (1 << 14), k = 14; x && i; i /= 2, k--)
	{
		if (i > x)continue;
		x -= i;
		num[k] = 1;
		pl++;
	}
	for (int i = 14; i >= 0; i--)
	{
		if (num[i])
		{
			pl--;
			cout << '2';
			output(i, 1, 1);
			if (pl)cout << "+";
			else break;
		}
	}
	if (dkr == 0)dkr = 1;
	else cout << ')';
}
int main()
{
	n = read();
	output(n, 0, 0);
	return 0;
}