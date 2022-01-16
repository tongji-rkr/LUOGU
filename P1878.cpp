#include<iostream>
#include<cstring>
#include<queue>
#include<unordered_map>
#include<cmath>
using namespace std;

int n;
string s;
int a[200005],b[200005][2],ans;
unordered_map<int, int> vis;


struct Node
{
	int left,right;
	int val;
	bool operator < (const Node& s)const
	{
		if (val != s.val)
			return val > s.val;
		else
			return left > s.left;
	}
};
priority_queue<Node> q;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		if (s[i] != s[i - 1])
		{
			q.push({ i,i + 1,abs(a[i + 1] - a[i]) });
		}
	}
	while (!q.empty())
	{
		int l = q.top().left,r=q.top().right,val=q.top().val;
		q.pop();
		if (vis[l] || vis[r])
			continue;
		vis[l] = vis[r] = 1;
		b[++ans][0] = l;
		b[ans][1]=r;
		while (l > 0 && vis[l])l--;
		while (r <= n && vis[r])r++;
		if (l>0 && r<=n && s[l - 1] != s[r - 1])
			q.push({ l,r,abs(a[r] - a[l]) });
	}
	cout << ans << endl;
	for (int i = 1; i <= ans; i++)
	{
		cout << b[i][0] << ' ' << b[i][1] << endl;
	}
	return 0;
}