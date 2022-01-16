#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

typedef long long ll;
const ll d[10][5] = { {}, {2,1,3}, {3,-1,1,3}, {2,-1,3}, {3,-3,1,3}, {4,-3,-1,1,3}, {3,-3,-1,3}, {2,-3,1}, {3,-3,-1,1}, {2,-3,-1} };
const ll a[9] = { 100000000,10000000,1000000,100000,10000,1000,100,10,1 };
unordered_map<ll, ll> visb, vise;
ll b, e, dcb, dce;
queue<ll>qb, qe;

int main()
{
	cin >> b;
	e = 123804765;
	ll p = 0;
	ll xb = b, xe = e;
	qb.push(b), qe.push(e);
	visb[b] = 1, vise[e] = 1;
	while (!qb.empty() && !qe.empty())
	{
		b = qb.front(), qb.pop();
		e = qe.front(), qe.pop();
		xb = b, xe = e;
		int pd=0;
		dcb = dce = 1;
		for(int i=9;i>=1;i--)
		{
			pd = xb % 10, xb /= 10;
			if (pd == 0) dcb = i;
			pd = xe % 10, xe /= 10;
			if (pd == 0) dce = i;
		}
		if (visb[b] && vise[b])
		{
			p = b;
			break;
		}
		if (visb[e] && vise[e])
		{
			p = e;
			break;
		}
		for (int i = 1; i <= d[dcb][0]; i++)
		{
			ll k = dcb + d[dcb][i];
			ll t = (b / a[k - 1]) % 10;
			xb = b - t * (a[k - 1] - a[dcb - 1]);
			if (visb[xb] == 0)
			{
				visb[xb] = visb[b] + 1;
				qb.push(xb);
			}
		}
		for (int i = 1; i <= d[dce][0]; i++)
		{
			ll k = dce + d[dce][i];
			ll t = (e / a[k - 1]) % 10;
			xe = e - t * (a[k - 1] - a[dce - 1]);
			if (vise[xe] == 0)
			{
				vise[xe] = vise[e] + 1;
				qe.push(xe);
			}
		}
	}
	cout << visb[p] + vise[p] - 2;
	return 0;
}