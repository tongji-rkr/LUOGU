#include<iostream>
#include<iomanip>
using namespace std;

int n;
double sum, x, Max, Min=10;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		sum += x;
		if (x > Max)Max = x;
		if (x < Min)Min = x;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << (sum - Min - Max) / (n - 2);
	return 0;
}