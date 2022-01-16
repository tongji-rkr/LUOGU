#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

inline int read()
{
    register int x = 0, f = 1; register char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int s[5];
int a[5][21];
int l, r;
int minn;

void dfs(int x,int y)
{
    if (y > s[x])
    {
        minn = min(minn, max(l, r));
        return;
    }
    l += a[x][y];
    dfs(x, y + 1);
    l -= a[x][y];
    r += a[x][y];
    dfs(x, y + 1);
    r -= a[x][y];
}
int main()
{
    int ans = 0;
    for (int i = 1; i <= 4; i++)s[i] = read();
    for (int i = 1; i <= 4; i++)
    {
        for (int k = 1; k <= s[i]; k++)
            a[i][k] = read();
        minn = 10000000;
        l = r = 0;
        dfs(i, 1);
        ans += minn;
    }
    cout << ans;
    return 0;
}