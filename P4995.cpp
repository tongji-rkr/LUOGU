#include<iostream>
#include<algorithm>
using namespace std;

long long h[301];
int n;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	int s = 0;
	int i = 1, j = n;
	for (int k = i; k <= j; k++)
	{
		cin >> h[k];
	}
	sort(h + 1, h + n + 1);
	long long sum = h[j] * h[j];
	while (j > i)
	{
		sum += (h[j] - h[i]) * (h[j] - h[i]);
		if (s % 2 == 0)
			j--;
		else
			i++;
		s++;
	}
	cout << sum << endl;
	return 0;
}