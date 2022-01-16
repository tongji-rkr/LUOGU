#include<iostream>
#include<iomanip>
using namespace std;

int sum, mon, cun;

int main()
{
	for (int i = 1; i <= 12; i++)
	{
		cin >> mon;
		sum += 300 - mon;
		if (sum < 0)
		{
			cout << '-' << i;
			return 0;
		}
		cun += sum / 100 * 100;
		sum = sum % 100;
	}
	sum += cun * 1.2;
	cout << sum;
	return 0;
}