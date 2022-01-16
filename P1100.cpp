#include<iostream>
using namespace std;

unsigned long long N = INT_MAX + 1;
unsigned long long x, y;
int a, b;
int main()
{
	cin >> x;
	a = x / N;
	b = x % N;
	y = b * N + a;
	cout << y;
	return 0;
}