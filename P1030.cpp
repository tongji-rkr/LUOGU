#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

string a, b;

void dfs(string x, string y)
{
	if (!y.size())return;
	int pos = x.find(y[0]);
	cout << y[0];
	dfs(x.substr(pos + 1), y.substr(pos + 1));
	dfs(x.substr(0, pos), y.substr(1, pos));
}
int main()
{
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	dfs(a, b);
	return 0;
}