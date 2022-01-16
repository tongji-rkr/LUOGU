#include<iostream>
using namespace std;

int t, n;
int main()
{
	int y = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int x = 0;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> y;
			x = x ^ y;
		}
		if (x)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}