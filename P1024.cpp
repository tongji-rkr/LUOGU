#include<iostream>
#include<cmath>
using namespace std;

double a, b, c, d;
double ans;

double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}
void search(double lft,double rgt)
{
	if (fabs(lft - rgt) < 1e-4)
	{
		printf("%.2lf ", lft);
		return;
	}
	double l = f(lft);
	double r = f(rgt);
	double mid = lft + (rgt - lft) / 2;
	double m = f(mid);
	if (m == 0)
	{
		printf("%.2lf ", m);
	}
	else
	{
		if ((m < 0 && l>0) || (m > 0 && l < 0))
			search(lft, mid);
		else
			search(mid, rgt);
	}
	return;
}
int main()
{
	cin >> a >> b >> c >> d;
	for (double i = -100; i < 100; i+=1)
	{
		if (f(i) == 0)
			printf("%.2lf ", i);
		else if ((f(i) > 0 && f(i + 1) < 0) || (f(i + 1) > 0 && f(i) < 0))
			search(i, i + 1);
	}
	if (f(100) == 0)
		printf("100.00");
	return 0;
}