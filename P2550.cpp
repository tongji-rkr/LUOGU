#include<iostream>
#include<cmath>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n;
int ans[7];
int a[7];
int b[7];

int main()
{
	n = read();
	for (int i = 0; i < 7; i++)
	{
		ans[i] = read();
	}
	for (int i = 1; i <= n; i++)
	{
		int num = 0, k = 0;
		for (int j = 0; j < 7; j++)
		{
			a[j] = read();
			for (k = 0; k < 7; k++)
			{
				if (ans[k] == a[j])
					break;
			}
			if (k < 7)num++;
		}
		b[7 - num]++;
	}
	for (int i = 0; i < 7; i++)
	{
		cout << b[i] << ' ';
	}
	return 0;
}