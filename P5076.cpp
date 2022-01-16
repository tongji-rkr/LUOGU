#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

multiset<int>q;
int n, t, x, order;
int main()
{
    q.insert(-0x7fffffff);
    q.insert(0x7fffffff);
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &t, &x);
        if (t == 1)
        {
            auto it = q.lower_bound(x);
            order = 0;
            for (auto i = q.begin(); i != it; i++, order++);
            printf("%d\n", order);
        }
        else if (t == 2)
        {
            order = -1;
            for (int i : q)
                if (++order == x)
                    printf("%d\n", i);
        }
        else if (t == 3)
        {
            auto it = q.lower_bound(x);
            printf("%d\n", *--it);
        }
        else if (t == 4)
        {
            printf("%d\n", *q.upper_bound(x));
        }
        else
        {
            q.insert(x);
        }
    }
    return 0;
}