#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e8 + 10;
bool vis[N];
int num[N];
int n, q, r;

int main()
{
	std::ios::sync_with_stdio(0);
	cin >> n >> q;
	memset(vis, false, sizeof(vis));
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i])num[++r] = i;
		for (int j = 1; j <= r && i * num[j] <= n; j++)
		{
			vis[i * num[j]] = false;
			if (i % num[j] == 0)
				break;
		}
	}
	int s;
	for (int i = 1; i <= q; i++)
	{
		cin >> s;
		cout << num[s] << endl;
	}
	return 0;
}