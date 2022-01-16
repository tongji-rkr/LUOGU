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

int n;
int a[22][22];
int i, j;

int main()
{
    n = read();
    a[1][1] = 1;
    cout << 1 << endl;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}