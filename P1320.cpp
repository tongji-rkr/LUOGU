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

int n, tot, k;
int a[10005], r;
char c[205], p = '0';

int main()
{
    while (1)
    {
        scanf("%s", c);
        k++;
        if(!n)n = strlen(c);
        for(int i=0;i<n;i++)
        {
            tot++;
            if (c[i] != p)r++;
            a[r]++;
            p = c[i];
        }
        if (k == n)break;
    }
    cout << n << ' ' << a[0] << ' ';
    for (int i = 1;a[i]; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}