#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;

int main()
{
    double sum = 0, x = 0, ans;
    int p = 1, a[1001] = { 0 }, l = 1;
    char c, ch = 'a';
    while ((c=getchar())!='=')
    {
        if (c == '-')
        {
            p = -1;
            l++;
            continue;
        }
        if (c == '+')
        {
            p = 1;
            l++;
            continue;
        }
        if (c >= '0' && c <= '9')
        {
            if (a[l] == 0)
            {
                a[l] += p * (c - '0');
            }
            else
            {
                a[l] = 10 * a[l] + p * (c - '0');
            }
            continue;
        }
        if (c >= 'a' && c <= 'z')
        {
            ch = c;
            if (a[l] != 0)
                x += a[l];
            else
                x += p;
            a[l] = 0;
            l--;
        }
    }
    l++;
    p = -1;
    while ((c = getchar()) != '\n')
    {
        if (c == '-')
        {
            p = 1;
            l++;
            continue;
        }
        if (c == '+')
        {
            p = -1;
            l++;
            continue;
        }
        if (c >= '0' && c <= '9')
        {
            if (a[l] == 0)
            {
                a[l] += p * (c - '0');
            }
            else
            {
                a[l] = 10 * a[l] + p * (c - '0');
            }
            continue;
        }
        if (c >= 'a' && c <= 'z')
        {
            ch = c;
            if (a[l] != 0)
                x += a[l];
            else
                x += p;
            a[l] = 0;
            l--;
        }
    }
    for (int i = 1; i <= l; i++)
    {
        sum += a[i];
    }
    sum = -sum;
    ans = sum == 0 ? 0 : sum / x;
    cout << ch << "=" << setiosflags(ios::fixed) << setprecision(3) << ans << endl;
    return 0;
}