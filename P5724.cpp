#include<iostream>
using namespace std;

int n, nmax, nmin=1000;

int main()
{
	int x;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x > nmax)
			nmax = x;
		if (x < nmin)
			nmin = x;
	}
	cout << nmax - nmin << endl;
	return 0;
}