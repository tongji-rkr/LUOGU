#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n, total;
int t[50005],a[50005];
vector<int> b[50005];

int main()
{
	int x, len, y;
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> len;
		t[x] = len;
		while (1)
		{
			cin >> y;
			if (!y)
				break;
			a[x]++;
			b[x].push_back(y);
		}
	}
	while (1)
	{
		vector<int> v;
		int mt = 1000000;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0 && t[i])
			{
				v.push_back(i);
				mt = min(mt, t[i]);
			}
		}
		if (mt == 1000000)
			break;
		total += mt;
		for (int i:v)
		{
			t[i] -= mt;
			if (t[i] == 0)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if(find(b[j].begin(),b[j].end(),i)!=b[j].end())
					{ 
						a[j]--;
					}
				}
			}
		}
	}
	cout << total << endl;
	return 0;
}