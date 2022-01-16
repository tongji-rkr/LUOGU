#include<iostream>
#include<cstring>
using namespace std;

long long n;
long long sum;
int main()
{
	cin >> n;
	if (n <= 1)
	{
		cout << n;
		return 0;
	}
	sum = 2 * n - 1;
	for (int i = 2; i <= n; i++)
	{
		sum += n / i - 1;
	}
	cout << sum;
	return 0;
}