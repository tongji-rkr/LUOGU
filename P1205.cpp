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

char b[12][12], c[12][12], d[12][12];
int n;
bool judge(char b[12][12],char c[12][12])
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (b[i][j] != c[i][j])
                return false;
    return true;
}

void func1()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            d[j][n - i + 1] = b[i][j];
    }
    return;
}
void rever()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            d[i][n - j + 1] = b[i][j];
    }
}
int main()
{
    int ans = 7;
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    if (judge(b, c))
    {
        if (ans > 6)ans = 6;
    }
    for (int i = 1; i <= 3; i++)
    {
        func1();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                b[i][j] = d[i][j];
        if (judge(b, c))
        {
            if (ans > i)ans = i;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            b[j][n - i + 1] = d[i][j];
    rever();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            b[i][j] = d[i][j];
    if (judge(b, c))
    {
        if (ans > 4)ans = 4;
    }
    for (int i = 1; i <= 3; i++)
    {
        func1();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                b[i][j] = d[i][j];
        if (judge(b, c))
        {
            if (ans > 5)ans = 5;
        }
    }
    cout << ans << endl;
    return 0;
}