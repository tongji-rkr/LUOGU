#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int a[105];

int main()
{
	int i, j;
	string s;
	cin >> s;
	for (i = 0; i < s.length(); i++)
	{
		if (s[i] == ')')
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (a[j] == 0 && s[j] == '(')
				{
					a[i] = a[j] = 1;
					break;
				}
				else if (a[j] == 0 && s[j] == '[')
					break;
			}
		}
		else if(s[i]==']')
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (a[j] == 0 && s[j] == '[')
				{
					a[i] = a[j] = 1;
					break;
				}
				else if (a[j] == 0 && s[j] == '(')
					break;
			}
		}
	}
	for (i = 0; i < s.length(); i++)
	{
		if (a[i] == 0)
		{
			if (s[i] == '(' || s[i] == ')')
				cout << "()";
			else
				cout << "[]";
		}
		else
			cout << s[i];
	}
	return 0;
}