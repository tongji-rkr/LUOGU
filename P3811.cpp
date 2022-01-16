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

int n, p;
int inv[3000005];

int main()
{
    n = read(); p = read(); inv[1] = 1; puts("1");
    for (int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
        printf("%d\n", inv[i]);
    }
    return 0;
}