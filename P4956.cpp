#include<iostream>
#include<iomanip>
using namespace std;

int n;

int main()
{
	cin >> n;
	n /= 52*7;
	if (n <= 103)
		cout << n - 3 << endl << 1 << endl;
	else
	{

		cout << 98 + (n + 1) % 3 << endl << (n - 98) / 3 << endl;
	}
		
	return 0;
}