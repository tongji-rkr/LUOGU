#include<iostream>
using namespace std;

int n;
int sum;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)sum += i;
	cout << sum;
	return 0;
}