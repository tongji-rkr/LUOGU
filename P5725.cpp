#include<iostream>
#include<iomanip>
using namespace std;

int n, r = 1;

int main()
{
	cin >> n;
	cout << setfill('0');
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << setw(2) << r++;
		}
		cout << endl;
	}
	r = 1;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j <= n - i)
				cout << "  ";
			else
				cout << setw(2) << r++;
		}
		cout << endl;
	}
	return 0;
}