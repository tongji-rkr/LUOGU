#include<iostream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int a[101];
int i;

int main()
{
	for (i = 1; ; i++)
	{
		a[i] = read();
		if (a[i] == 0)
			break;
	}
	for (int j = i-1; j >=1; j--)
	{
		cout << a[j] << ' ';
	}
	return 0;
}