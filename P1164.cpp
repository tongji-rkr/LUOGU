#include<iostream>
using namespace std;

int dish[101];
int money[101][10001];

int main()
{
	int n, m, x;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> dish[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dish[i] == j)
				money[i][j] = money[i - 1][j] + 1;
			else if (dish[i] > j)
				money[i][j] = money[i - 1][j];
			else if (dish[i] < j)
				money[i][j] = money[i - 1][j] + money[i - 1][j - dish[i]];
		}
	}
	cout << money[n][m] << endl;
	return 0;
}