#include <iostream>
using namespace std;

inline int read()
{
    register int x = 0, f = 1; register char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int dp[1100];
int win[1100], lose[1100], use[1100];

int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        lose[i] = read(), win[i] = read(), use[i] = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= use[i]; j--)
            dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
        for (int j = use[i] - 1; j >= 0; j--)
            dp[j] += lose[i];
    }
    printf("%lld", (long long)5 * dp[m]);
}