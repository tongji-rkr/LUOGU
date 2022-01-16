#include <cstdio>
#include <cstring>

const int N = 1e6 + 5;
int tot, p[N];
bool flg[N], vis[N];

void init() {
    for (int i = 2; i < N; ++i) {
        if (!flg[i]) p[++tot] = i;
        for (int j = 1; j <= tot && i * p[j] < N; ++j) {
            flg[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}
void chkmin(long long& x, long long a, long long b, long long& p1, long long& p2) {
    if (x > b - a) x = b - a, p1 = a, p2 = b;
}
void chkmax(long long& x, long long a, long long b, long long& p1, long long& p2) {
    if (x < b - a) x = b - a, p1 = a, p2 = b;
}
int main() {
    init();
    long long l, r;
    while (~scanf("%lld%lld", &l, &r)) {
        memset(vis, 1, sizeof(vis));
        if (l == 1) vis[0] = 0;
        for (int i = 1; i <= tot; ++i) {
            for (long long j = l / p[i]; j * p[i] <= r; ++j) {
                long long x = p[i] * j;
                if (j > 1 && x >= l) vis[x - l] = 0;
            }
        }
        long long p = 0, p1, p2, p3, p4, mn = 1LL << 60, mx = 0;
        for (long long i = l; i <= r; ++i) {
            if (!vis[i - l]) continue;
            if (p) chkmin(mn, p, i, p1, p2), chkmax(mx, p, i, p3, p4);
            p = i;
        }
        if (!mx) puts("There are no adjacent primes.");
        else printf("%lld,%lld are closest, %lld,%lld are most distant.\n", p1, p2, p3, p4);
    }
    return 0;
}