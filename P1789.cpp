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

const int sx[12] = { -2,-1,-1,-1,0,0,0,0,1,1,1,2 };
const int sy[12] = { 0,-1,0,1,-2,-1,1,2,-1,0,1,0 };
int n;
int a[105][105];
int i, j, m, k, x, y;

int main()
{
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
    {
        x = read(), y = read();
        a[x][y] = 1;
        for (int j = 0; j < 12; j++)
        {
            int xx = x + sx[j], yy = y + sy[j];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= n)a[xx][yy] = 1;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        x = read(), y = read();
        for (int j = -2; j <= 2; j++)
        {
            for (int k = -2; k <= 2; k++)
            {
                int xx = x + j, yy = y + k;
                if(xx>=1&&xx<=n&&yy>=1&&yy<=n)a[xx][yy] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)ans++;
        }
    }
    cout << ans;
    return 0;
}