#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, flag;
string a[100005];
string ans[100005];
string now[100005];
int vis[100005];
int s1[30], s2[30];
int sum;

void dfs(char c,int step)
{
	if (flag == 1)
		return;
	if (step == n)
	{
		flag = 1;
		for (int i = 1; i <= sum; i++)
		{
			ans[i] = now[i];
		}
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i] == 1)
			continue;
		if (c == a[i][0])
		{
			now[++sum] = a[i];
			vis[i] = 1;
			dfs(a[i][a[i].length() - 1], step + 1);
			sum--;
			vis[i] = 0;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s1[a[i][0]-'a']++;
		s2[a[i][a[i].length() - 1] - 'a']++;
	}
	sort(a + 1, a + 1 + n);
	char s = 'a';
	for (int i = 0; i < 26; i++)
	{
		if (s1[i] - s2[i] == 1)s = i + 'a';
	}
	for (char c = s; c <= 'z'; c++)
	{
		dfs(s, 0);
		if (flag)break;
	}
	if (flag == 0) 
		dfs('w', 0);
	if (!flag) 
		cout << "***";
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i) cout << ".";
			cout << ans[i + 1];
		}
	}
	return 0;
}