#include<iostream>
#include<stack>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n;
stack<int> q;

int main()
{
	n = read();
	q.push(n);
	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
		q.push(n);
	}
	while (!q.empty())
	{
		cout << q.top() << ' ';
		q.pop();
	}
	return 0;
}