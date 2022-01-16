#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

struct job
{
	ll d, p;
}a[100005];

int n;
ll ans;
priority_queue <job> q;
bool cmp(job& s1, job& s2)
{
	return s1.d < s2.d;
}

bool operator <(job& s1, job& s2)
{
	return s1.p > s2.p;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].d = read(), a[i].p = read();
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (a[i].d <= q.size())
			if (a[i].p > q.top().p)q.pop(),q.push(a[i]),ans += a[i].p - q.top().p;
		else
			q.push(a[i]), ans += a[i].p;
	}
	cout << ans;
	return 0;
}