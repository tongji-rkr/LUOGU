#include<iostream>
using namespace std;

int n, ans, len = 1;

int main()
{
	int x, y;
	cin >> n;
	cin >> y;
	for (int i = 2; i <= n; i++)
	{
		cin >> x;
		if (x != y + 1)
		{
			ans = max(ans, len);
			len = 1;
		}
		else
			len++;
		y = x;
	}
	cout << ans;
	return 0;
}