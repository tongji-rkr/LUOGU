#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

priority_queue<int, vector<int> > q1;//´ó¸ù¶Ñ
priority_queue <int, vector<int>, greater<int> > q2;
int n, x;

int main()
{
	n = read();
	x=read(),q1.push(x);
	cout << x << endl;
	for (int i = 2; i <= n; i++)
	{
		x = read();
		if (x > q1.top()) q2.push(x);
		else q1.push(x);
		while (fabs(q1.size() - q2.size())> 1)
		{
			if (q1.size() > q2.size()) { q2.push(q1.top()); q1.pop(); }
			else { q1.push(q2.top()); q2.pop(); }
		}
		if (i % 2) cout << (q1.size() > q2.size() ? q1.top() : q2.top()) << endl;
	}
	return 0;
}