#include <iostream>
using namespace std;

int n, ans = 0x7fffffff;
int val[105];
int g[105][105];

int main()
{
    int l, r;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i!=j)
                g[i][j] = 1000000;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i] >> l >> r;
        if (l)g[i][l] = g[l][i] = 1;
        if (r)g[i][r] = g[r][i] = 1;
    }
    for (int k = 1; k <= n; k++)//用Floyed求任意两结点之间的最短路径
    {
        for (int i = 1; i <= n; i++)
        {
            if (i != k)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i != j && k != j && g[i][k] + g[k][j] < g[i][j])
                        g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int total = 0;
        for (int j = 1; j <= n; j++)
            total += g[i][j] * val[j];
        ans = min(ans, total);
    }
    cout << ans << endl;
    return 0;
}