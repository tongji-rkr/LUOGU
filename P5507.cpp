#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

const int MN = (1 << 24) + 10;
bool visb[MN], vise[MN];
int fromb[MN], frome[MN];
int cb[MN], ce[MN];
int b, e;
queue<int>qb, qe;
int ans[18];
int a[13][5];

inline void add(int& s, int w)
{
	int num = (s >> ((w - 1) << 1)) & 3;
	s -= num * (1 << ((w - 1) << 1));
	num++;
	if (num != 4)s += num * (1 << ((w - 1) << 1));
}
inline int niu(int s, int w)
{
	add(s, a[w][((s >> ((w - 1) << 1)) & 3) + 1]);
	add(s, w);
	return s;
}
inline int fniu(int s, int w)
{
	for (int i = 1; i <= 3; i++)
		add(s, w);
	for (int i = 1; i <= 3; i++)
		add(s, a[w][((s >> ((w - 1) << 1)) & 3) + 1]);
	return s;
}
inline void pushb(int x,int y)
{
	if (visb[x] == true)return;
	qb.push(x);
	visb[x] = true;
	fromb[x] = b;
	cb[x] = y;
}
inline void pushe(int x,int y)
{
	if (vise[x] == true)return;
	qe.push(x);
	vise[x] = true;
	frome[x] = e;
	ce[x] = y;
}
int main()
{
	int t, tmp = 0;
	for (int i = 1; i <= 12; i++)
	{
		t = read();
		b += (t - 1) << (tmp << 1);
		tmp++;
		for (int j = 1; j <= 4; j++)
			a[i][j] = read();
	}
	int p = 0, xb = b, xe = e;
	qb.push(b), qe.push(e);
	visb[b] = true, vise[e] = true;
	while (!qb.empty() && !qe.empty())
	{
		b = qb.front(), qb.pop();
		e = qe.front(), qe.pop();
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
		for (int i = 1; i <= 12; i++)
		{
			pushb(niu(b,i),i);
			pushe(fniu(e, i), i);
		}
	}
	int cnt1 = 0;
	int s = p;
	while (s != xb)
	{
		ans[++cnt1] = cb[s];
		s = fromb[s];
	}
	int cnt2 = cnt1;
	s = p;
	while (s != xe)
	{
		ans[++cnt2] = ce[s];
		s = frome[s];
	}
	cout << cnt2 << endl;
	for (int i = cnt1; i >= 1; i--)
		cout << ans[i] << ' ';
	for (int i = cnt1 + 1; i <= cnt2; i++)
		cout << ans[i] << ' ';
	return 0;
}