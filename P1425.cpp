#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d;
	if (d >= b)
	{
		e = c - a;
		f = d - b;
	}
	else
	{
		e = c - a - 1;
		f = d + 60 - b;
	}
	cout << e << " " << f << endl;
	return 0;
}