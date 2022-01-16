#include<iostream>
using namespace std;

int k, p;
int n,tim;

struct student
{
	int l, r;
}a[100005] = { 0 };

int main()
{
	int m = 2;
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> k >> p;
		if (p == 0)
		{
			if (a[k].l)
			{
				a[a[k].l].r = m;
				a[m].l = a[k].l;
			}
			a[k].l = m;
			a[m++].r = k;
		}
		else
		{
			if (a[k].r)
			{
				a[a[k].r].l = m;
				a[m].r = a[k].r;
			}
			a[k].r = m;
			a[m++].l = k;
		}
	}
	cin >> tim;
	for (int i = 1; i <= tim; i++)
	{
		int x;
		cin >> x;
		if (a[x].l || a[x].r)
		{
			a[a[x].l].r = a[x].r;
			a[a[x].r].l = a[x].l;
			a[x].l = a[x].r = 0;
		}
	}
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i].l == 0 && a[i].r)
			break;
	}
	for (int j = i;j;)
	{
		cout << j << ' ';
		j = a[j].r;
	}
	return 0;
}