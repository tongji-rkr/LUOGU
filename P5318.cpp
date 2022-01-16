#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

vector<int> son[100005];
int n, m;
int dord[100005], d;
int bord[100005], b;
queue<int> q;
bool dvis[100005], bvis[100005];

void dfs(int k)
{
	dord[d++] = k;
	dvis[k] = true;
	for (auto& i : son[k])
	{
		if(!dvis[i])dfs(i);
	}
	return;
}
void bfs()
{
	q.push(1);
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		if (!bvis[a])
		{
			bord[b++] = a;
			bvis[a] = true;
		}
		for (auto& i : son[a])
			if (!bvis[i])q.push(i);
	}
}
int main()
{
	int x, y;
	n = read();
	m = read();
	memset(dvis, false, sizeof(dvis));
	memset(bvis, false, sizeof(bvis));
	for (int i = 1; i <= m; i++)
	{
		x = read(), y = read();
		son[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(son[i].begin(), son[i].end());
	}
	dfs(1);
	for (int i = 0; i < d; i++)
		cout << dord[i] << ' ';
	cout << endl;
	bfs();
	for (int i = 0; i < b; i++)
		cout << bord[i] << ' ';
	return 0;
}