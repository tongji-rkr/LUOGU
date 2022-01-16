#include<iostream>
using namespace std;

int f[500010];
string s;
string str[500010];
int n;

int read()
{
    register int x = 0, f = 1;
    register char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main()
{
    n = read();
    cin >> s;
	for (int i = 2; i <= n; i++)
	{
        f[2] = read();
	}
    for(int i=1;i<=)
	return 0;
}