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

int n, m, tot, k;

int main()
{
    n = read();
    while (tot < n * n)
    {
        m = read();
        for (int i = 1; i <= m; i++,tot++)
        {
            if (tot&&tot % n == 0)cout << endl;
            cout << k;
        }
        k = 1 - k;
    }
    return 0;
}