#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;

inline int read()
{
    register int x = 0, f = 1; register char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int n, i, j, tot;
int a[109][109];

int main()
{
    n = read();
    a[1][1] = 1;
    for (i = 1, j = 1, tot = 1; tot < n * n;)
    {
        while (++j <= n && !a[i][j])a[i][j] = ++tot; --j;
        while (++i <= n && !a[i][j])a[i][j] = ++tot; --i;
        while (--j > 0 && !a[i][j])a[i][j] = ++tot; ++j;
        while (--i > 0 && !a[i][j])a[i][j] = ++tot; ++i;
    }
    for (int i = 1; i <= n; i++, cout << endl)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << setw(3) << a[i][j];
        }
    }
    return 0;
}