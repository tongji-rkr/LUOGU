#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n, i = 0, j = 0, s = 1;
	cin >> n;
	for (int i = n; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
		{
			cout << setfill('0') << setw(2) << s++;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}