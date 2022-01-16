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

int s1, s2, s3;
map<int, int> m;

int main()
{
    s1 = read(), s2 = read(), s3 = read();
    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            for (int k = 1; k <= s3; k++)
            {
                m[i + j + k]++;
            }
        }
    }
    int ans=0, nmax = 0;
    for (auto& it : m)
    {
        if (it.second > nmax)ans = it.first,nmax=it.second;
    }
    cout << ans;
	return 0;
}