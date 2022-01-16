#include<iostream>
#include<algorithm>
#include<cstdio>
#include<sstream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

stringstream ss;
int l, r;
int ans;
int main()
{
	l = read(), r = read();
	for (int i = l; i <= r; i++)
	{
		ss << i;
	}
	string str = ss.str();
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '2')ans++;
	}
	cout << ans;
	return 0;
}