#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#define ll long long
const int maxn = 1e6 + 5;
using namespace std;

inline int read()
{
    register int x = 0, f = 1; register char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}
ll n, k;
ll x[maxn], y[maxn];
int main() 
{
    n = read(), k = read();
    for (ll i = 0; i < k; i++) 
    {
        x[i] = read(), y[i] = read();
    }
    sort(x, x + k);
    sort(y, y + k);
    ll sizex = unique(x, x + k) - x;
    ll sizey = unique(y, y + k) - y;
    printf("%lld", n * n - (n - sizex) * (n - sizey));
    return 0;
}