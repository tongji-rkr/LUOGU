#include<iostream>
#include<deque>
using namespace std;

int m, n;
int seq[401];
struct Information
{
	int ser;//序号
	int time;//时间
}Work[21][21];
int mac[21][100001];
int step[21];
int protime[21];

int main()
{
	int total_time = 0;
	cin >> m >> n;
	for (int i = 1; i <= m * n; i++) 
	{
		cin >> seq[i];
	}
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++) 
		{
			cin >> Work[i][j].ser;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> Work[i][j].time;
		}
	}
	for (int i = 1; i <= m * n; i++) 
	{
		int num = seq[i];
		step[num]++;
		int ser = Work[num][step[num]].ser, time = Work[num][step[num]].time;
		int s = 0;
		for (int j = protime[num] + 1; ; j++) 
		{
			if (mac[ser][j] == 0) 
			{
				s++;//需要时间++
			}
			else 
			{
				s = 0;//重置需要时间
			}
			if (s == time) 
			{
				for (int k = j - time + 1; k <= j; k++) 
				{
					mac[ser][k] = 1;//在时间线上占据
				}
				if (j > total_time) 
					total_time = j;
				protime[num] = j;
				break;
			}
		}
	}
	cout << total_time << endl;
	return 0;
}
