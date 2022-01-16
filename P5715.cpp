#include<iostream>
#include<algorithm>
using namespace std;

void swap(int& a, int& b)
{
	int temp;
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	swap(a, b);
	swap(b, c);
	swap(a, b);
	cout << a << " " << b << " " << c << endl;
	return 0;
}