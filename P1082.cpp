#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

int a, b;

int fai(int n) 
{//求欧拉函数
    int ans = 1;
    for (int i = 2; i * i <= n; ++i) 
    {
        if (n % i == 0) {
            n /= i;
            ans *= i - 1;
            while (n % i == 0) 
            {
                n /= i;
                ans *= i;
            }
        }
    }
    if (n > 1)
        ans *= n - 1;
    return ans;
}

int fast_pow(int x, int k) 

{//快速幂
    ll ans = 1, quan = x;
    while (k) {
        if (k & 1)
            ans = ans * quan % b;
        quan = quan * quan % b;
        k >>= 1;
    }
    return (int)ans;
}
int main() 
{
    scanf("%d %d", &a, &b);
    printf("%d", fast_pow(a, fai(b) - 1));//公式
    return 0;
}