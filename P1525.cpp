#include<iostream>
#include<algorithm>
using namespace std;

inline int read()
{
    int p = 0, f = 1; char c = getchar();
    while (c < '0' || c>'9') { if (c == '-')f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { p = p * 10 + c - '0'; c = getchar(); }
    return f * p;
}
int n, m;
struct EDGE
{
	int nex, to, w;
}a[200010];
int fa[20005], e[20005];

bool cmp(EDGE e1, EDGE e2)
{
    return e1.w > e2.w;
}
int find(int x)//²éÕÒ
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        a[i].nex = read(),
        a[i].to = read(),
        a[i].w = read();
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int t1 = find(a[i].nex), t2 = find(a[i].to);
        if (t1 == t2)
        {
            cout << a[i].w;
            return 0;
        }
        else
        {
            if (!e[a[i].nex])
                e[a[i].nex] = a[i].to;
            else
                fa[find(e[a[i].nex])] = find(a[i].to);
            if (!e[a[i].to])
            {
                e[a[i].to] = a[i].nex;
            }
            else
                fa[find(e[a[i].to])] = find(a[i].nex);
        }
    }
    cout << 0;
    return 0;
}
