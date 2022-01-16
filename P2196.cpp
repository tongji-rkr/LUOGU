#include <iostream>
#include <stack>
using namespace std;

inline int read()
{
    register int x = 0, f = 1; register char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}
int ans;
int n, a[23];
int link[23][23];
bool used[23];
int stp, cnt;
int path[23];
int res[23];

bool check(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (link[x][i] && !used[i]) return false;
    }
    return true;
}
void dfs(int i,int stp,int num)
{
    if (check(i))
    {
        if (num > ans)
        {
            ans = num;
            cnt = stp;
            for (int k = 1; k <= stp; k++)
            {
                res[k] = path[k];
            }
        }
    }
    for (int j = i+1; j <= n; j++)
    {
        if (used[j] || link[i][j] == 0 || i == j)continue;
        used[j] = true;
        path[stp + 1] = j;
        dfs(j, stp + 1, num + a[j]);
        used[j] = false;
    }
}
int main()
{
    n = read();
    for(int i=1;i<=n;i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            link[i][j] = read();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        memset(used, false, sizeof used);
        used[i] = true;
        path[1] = i;
        dfs(i, 1, a[i]);
    }
    for (int i = 1; i <= cnt; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    cout << ans;
    return 0;
}