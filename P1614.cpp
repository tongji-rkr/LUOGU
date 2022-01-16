#include<iostream>
#include<sstream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, m, t;
int mi = 100000000;
int a[6005];

int main()
{
	n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n - m + 1; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            t += a[i + j - 1];
        }
        if (t < mi)mi = t;
        t = 0;
    }
    printf("%d", mi);
	return 0;
}