#include<iostream>
using namespace std;

int main()
{
	unsigned long long int n, s = 0;
	cin >> n;
	s = n * (n - 1);
	s /= 2;
	s *= (n - 2);
	s /= 3;
	s *= (n - 3);
	s /= 4;
	cout << s << endl;
	return 0;
}