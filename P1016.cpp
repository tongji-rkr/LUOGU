#include<iostream>
#include<iomanip>
using namespace std;

double d1, c, d2, p;
int n;
double d[10];
double mp[10];

int main()
{
	double tot = 0, l = 0;
	cin >> d1 >> c >> d2 >> p >> n;
	double x = c * d2;
	double d0 = 0;
	d[0] = 0;
	mp[0] = p;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i] >> mp[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] - d[i - 1] > x)
		{
			cout << "No Solution" << endl;
			return 0;
		}
	}
	int ii = 0;
	double pmin = 10000;
	while (d1 - d0)
	{
		for (int i = ii + 1; d[i] - d0 <= x && i <= n; i++)
		{
			if (mp[i] < pmin) 
			{ 
				pmin = mp[i]; 
				ii = i; 
			}
		}
		if (pmin <= p) 
		{ 
			tot += ((d[ii] - d0) / d2 - l) * p;
			l = (d[ii] - d0) / d2; 
		} 
		else if (d1 - d0 > x)
		{
			tot += (c - l) * p;
			l = c;
		}
		else
		{
			tot += ((d1 - d0) / d2 - l) * p; 
			break; 
		}
		l = l - (d[ii] - d0) / d2;
		d0 = d[ii];
		p = pmin;
		pmin = 1000;
	}
	cout <<setiosflags(ios::fixed)<<setprecision(2)<< tot << endl;
	return 0;
}