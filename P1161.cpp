#include<iostream>
#include<map>
using namespace std;

inline int read()
{
    register int x = 0, f = 1; register char c = getchar();
    while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
}

int n, t;
double a;
int lg[2000005];

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        t = read();
        for (int k = 1; k <= t; k++)
        {
            int s = a * k;
            lg[s] = 1 - lg[s];
        }
    }
    int i;
    for (i = 1; !lg[i]; i++);
    cout << i;
    return 0;
}