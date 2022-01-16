#include<iostream>
#include<cmath>
using namespace std;

double dis;
int n;

int main()
{
	double i = 2;
	cin >> dis;
	for (;dis>=i; n++)
	{
		dis -= i;
		i *= 0.98;
	}
	n++;
	cout << n;
	return 0;
}   