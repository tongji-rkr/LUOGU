#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

struct student
{
	int num, s1, s2, s3, st;
}a[305];
int n;

bool cmp(student& s1, student& s2)
{
	if (s1.st != s2.st)
		return s1.st > s2.st;
	else if (s1.s1 != s2.s1)
		return s1.s1 > s2.s1;
	else
		return s1.num < s2.num;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].num = i;
		a[i].s1 = read(), a[i].s2 = read(), a[i].s3 = read();
		a[i].st = a[i].s1 + a[i].s2 + a[i].s3;
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= 5; i++)
	{
		cout << a[i].num << " " << a[i].st<<endl;
	}
	return 0;
}