#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;

struct Node
{
	string val;
	int k;
	Node(string s, int v)
	{
		val = s;
		k = v;
	}
};
string a, b;
int n = 0, ans;
pair<string, string> ord[7];
unordered_map<string, int> ma;
queue<Node> q;
string trans(string s,int i,int j)
{
	string ret = "";
	if (i + ord[j].first.length() > s.length())
		return ret;
	for (int d = 0; d < ord[j].first.length(); d++)
	{
		if (s[i + d] != ord[j].first[d])
			return ret;
	}
	ret = s.substr(0, i);
	ret += ord[j].second;
	ret += s.substr(i + ord[j].first.length());
	return ret;
}
void bfs()
{
	Node m(a, 0);
	q.push(m);

	while (!q.empty())
	{
		Node u = q.front();
		q.pop();

		if (u.k == 10)break;
		if (ma.count(u.val) == 1)continue;
		if (u.val == b)
		{
			ans = u.k;
			break;
		}
		ma[u.val] = 1;
		for (int i = 0; i < u.val.length(); i++)
		{
			for (int j = 0; j < n; j++)
			{
				string tmp=trans(u.val, i, j);
				if (tmp != "")
				{
					Node s(tmp, u.k + 1);
					q.push(s);
				}
			}
		}
	}
	if (ans > 0 && ans < 10)cout << ans;
	else cout << "NO ANSWER!";
}
int main()
{
	cin >> a >> b;
	while (n<3)
	{
		cin >> ord[n].first >> ord[n].second;
		n++;
	}
	bfs();
	return 0;
}