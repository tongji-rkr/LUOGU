#include<iostream>
using namespace std;

int a[10000001];
int b[10000001];
int n;

int main()
{
	cin >> n;
	a[1] = b[1] = 1;
	a[2] = b[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		a[i] = (a[i - 1] + a[i - 2] + 2 * b[i - 2]) % 10000;
		b[i] = (a[i - 1] + b[i - 1])%10000;
	}
	cout << a[n] << endl;
	return 0;
}