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

long long n, m;
long long tot, x;

int main()
{
	n = read(), m = read();
	tot = n * (n + 1) * m * (m + 1) / 4;
	for (int i = 0; m - i > 0 && n - i > 0; i++)
	{
		x += (n - i) * (m - i);
	}
	cout << x << ' ' << tot - x << endl;
	return 0;
}