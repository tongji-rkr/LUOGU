#include<iostream>
using namespace std;

long long d;

int main()
{
	long long i = 1;
	long long sum = 0;
	cin >> d;
	while (d > i)
	{
		d -= i;
		sum += i * i;
		i++;
	}
	sum += d * i;
	cout << sum;
	return 0;
}