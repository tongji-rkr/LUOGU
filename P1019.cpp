#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,t[21];
string str[21];
int len;

int can(string s1, string s2)
{
    for (int i = 0;i<min(s1.length(),s2.length()); i++)
    {
        int cln = i;
        for (int j = 0; j < i; j++)
        { 
            if (s1[s1.length() - i + j] != s2[j])
                cln = 0;
        }
        if (cln) 
            return i;
    }
    return 0;
}
void solve(string strnow,int lennow)
{
    len = max(lennow, len);
    for (int i = 0; i < n; i++)
    {
        if (t[i] >= 2)
            continue;
        int c = can(strnow, str[i]);
        if (c > 0)
        {
            t[i]++;
            solve(str[i], lennow + str[i].length() - c);
            t[i]--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> str[i];
    }
    solve(' ' + str[n], 1);
    cout << len << endl;
    return 0;
}