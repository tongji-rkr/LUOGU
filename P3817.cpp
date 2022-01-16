#include<iostream>
using namespace std;

//long long box[10005];
int n;
long long x;

int main()
{
	long long ans;
	long long now;
	long long sum=0;
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> x;
	cin >> now;
	if (now > x)
	{
		sum += now - x;
		now = x;
	}
	for (int i = 2; i <= n; i++)
	{
		cin >> ans;
		if (ans + now > x)
		{
			sum += ans + now - x;
			now = x - now;
		}
		else
			now = ans;
	}
	cout << sum << endl;
	return 0;
}