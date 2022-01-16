#include<iostream>
#include<cmath>
using namespace std;

bool judge(const int num)
{
	if (num < 2)
		return false;
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(num); i+=2)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (judge(num))
			cout << num << ' ';
	}
	cout << endl;
	return 0;
}