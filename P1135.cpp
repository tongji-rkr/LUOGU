#include<iostream>
#include<queue>
using namespace std;

queue<int> q;
int n, a, b;
int k[203];
int judge[203];

bool find(queue<int> q, int& x)
{
	int size = q.size();
	for (int i = 0; i < size; ++i)
	{
		int a = q.front();
		if (a == x)
			return true;
		q.pop();
	}
	return false;
}
int main()
{
	cin >> n >> a >> b;
	int ans = 0;
	for (int i = 1; i <= n; i++)cin >> k[i];
	q.push(a);
	while (!find(q,b))
	{
		int num = q.size();
		ans++;
		for (int i = 1; i <= num; i++)
		{
			int s = q.front();
			judge[s] = 1;
			q.pop();
			if (s - k[s] > 0&&!judge[s - k[s]])
				q.push(s - k[s]);
			if(!judge[s + k[s]])
				q.push(s + k[s]);
		}
		if (q.empty())
		{
			ans = -1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
