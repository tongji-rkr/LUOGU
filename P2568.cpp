#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;
const int maxn = 1e7 + 5;
int n;
int prime[maxn],phi[maxn];
bool vis[maxn];
ll sum[maxn];

int gcd(int a, int b)
{
    if (b) while ((a %= b) && (b %= a));
    return a + b;
}

void Prime() {
    memset(vis, false,sizeof vis);
    memset(prime, 0,sizeof prime);
    phi[1] = 1;
    for (int i = 2; i <= n; i++) 
    {
        if (!vis[i]) 
        {
            prime[++prime[0]] = i; 
            phi[i] = i - 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= maxn; j++) 
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[prime[j] * i] = prime[j] * phi[i];
                break;
            }
            else
                phi[prime[j] * i] = phi[prime[j]] * phi[i];
        }
    }
}

int main()
{
    cin >> n;
    Prime();
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + phi[i];
    ll ans = 0;
    for (int i = 1; i <= prime[0] && prime[i] <= n; ++i)
        ans += (sum[n / prime[i]] << 1) - 1;
    printf("%lld\n", ans);
	return 0;
}