#include<iostream>
#include<iomanip>
#include<cstring>
#include<queue>
using namespace std;

const int px[8] = {-2,-1,1,2,2,1,-1,-2};
const int py[8] = {-1,-2,2,1,-1,-2,2,1};
int n, m, x, y;
queue<pair<int, int> > q;
int a[405][405];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> x >> y;
	memset(a, -1, sizeof(a));
	a[x][y] = 0;
	q.emplace(x, y);
	while (!q.empty())
	{
		int xx = q.front().first, yy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int x0 = xx + px[i], y0 = yy + py[i];
			if (x0<1 || x0>n || y0<1 || y0>m)
				continue;
			if (a[x0][y0] == -1)
			{
				a[x0][y0] = a[xx][yy] + 1;
				q.emplace(x0, y0);
			}
		}
	}
	cout << setiosflags(ios::left);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
	return 0;
}