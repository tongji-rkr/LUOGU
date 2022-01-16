#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int n;
double dis=40000;
double x[20];
double dp[65000][20];
double y[20];
int t[20];

double d(int a, int b) 
{
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));//距离公式
}
void solve(int k,int now, double lennow,int b)
{
	if (lennow > dis)
		return;
	if (k==n)
	{
		dis = min(lennow, dis);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (t[i])
			continue;
		int p = b + (1 << (i - 1));//状压存状态
		if (dp[p][i] != 0 && dp[p][i] <= lennow + d(i,now))
			continue;//判断条件+优化
		t[i]=1;
		dp[p][i] = lennow + d(i, now);
		solve(k + 1, i, dp[p][i], p);
		t[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
	}
	solve(0, 0, 0, 0);
	cout << setiosflags(ios::fixed) << setprecision(2) << dis << endl;
	return 0;
}