#include<iostream>
using namespace std;

int main()
{
	int n;
	int min = 0, a;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (i == 1)
			min = a;
		else
		{
			if (a < min)
				min = a;
		}
	}
	cout << min << endl;
	return 0;
}