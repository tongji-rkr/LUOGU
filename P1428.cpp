#include<iostream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}
int n;
int a[101];
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		a[i] = read();
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i])
				num++;
		}
		cout << num << ' ';
	}
	return 0;
}