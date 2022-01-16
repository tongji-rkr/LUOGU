#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long

const int N = 200005;
ll m, d, t;
ll stack[N], top, cnt;

void add(ll k) 
{
    cnt++;
    stack[cnt] = k;
    top = cnt - 1;
    while (k > stack[top] && top > 0)
        stack[top--] = k;
    return;
}
void ask(ll x) 
{
    t = stack[x];
    cout << t << endl;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> m >> d;
    char ch;
    for(int i=1;i<=m;i++)
    {
        cin >> ch;
        if (ch == 'A')
        {
            ll x;
            cin >> x;
            add((t + x) % d);
        }
        else
        {
            ll x;
            cin >> x;
            ask(cnt - x + 1);
        }
    }
    return 0;
}