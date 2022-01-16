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
	dfs(x.substr(0, pos), y.substr(1, pos));
	dfs(x.substr(pos + 1), y.substr(pos + 1));
	cout << y[0];
}
int main()
{
	cin >> a >> b;
	dfs(a, b);
	return 0;
}