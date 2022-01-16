#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
	char l, r;
	node()
	{
		l = r = '*';
	}
}a[30];
int n;
int s[26];

void preord(char c)
{
	cout << c;
	if (a[c - 'a'].l != '*')
		preord(a[c - 'a'].l);
	if (a[c - 'a'].r != '*')
		preord(a[c - 'a'].r);
}
int main()
{
	char start = 'a', t;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		cin >> a[t - 'a'].l >> a[t - 'a'].r;
		if (a[t - 'a'].l != '*')s[a[t - 'a'].l - 'a']++;
		if (a[t - 'a'].r != '*')s[a[t - 'a'].r - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (!s[i])
		{
			start = 'a' + i;
			break;
		}
	}
	preord(start);
	return 0;
}