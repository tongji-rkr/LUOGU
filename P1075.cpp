#include<iostream>
using namespace std;

int n,i;

int main()
{
	cin >> n;
	for (i = n - 1; n % i; i--);
	cout << i;
	return 0;
}