#include<iostream>
#include<sstream>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n1, n2, a[10];

int main()
{
	n1 = read(), n2 = read();
	for (int i = n1; i <= n2; i++)
	{
		stringstream ss("");
		ss << i;
		string s = ss.str();
		for (int j = 0; j < s.length(); j++)
		{
			a[s[j] - '0']++;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}