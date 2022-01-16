#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int n, t;
pair<double, int> vm[105];

int main()
{
	double value = 0;
	double total = 0;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> vm[i].second >> value;
		vm[i].first = value / vm[i].second;
	}
	sort(vm + 1, vm + n + 1);
	for (int i = n; i >= 1; i--)
	{
		if (t > vm[i].second)
		{
			total += vm[i].second * vm[i].first;
			t -= vm[i].second;
		}
		else
		{
			total += vm[i].first * t;
			break;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << total << endl;
	return 0;
}