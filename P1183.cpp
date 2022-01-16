#include<iostream>
#include<cmath>
using namespace std;

int x[101], y[101];
int n;

int max(int a[])
{
	int max = a[1];
	for (int i = 2; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
int main()
{
	int s;
	cin >> n;
	cin >> x[0] >> y[0];
	int x0 = x[0], y0 = y[0];
	x[0] = y[0] = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> x[i] >> y[i];
		x[i] -= x0;
		y[i] -= y0;//将首顶点平移到（0，0）
	}
	
	int xmax = max(x), ymax = max(y);
	x[n] = 0;
	y[n] = ymax;
	s = xmax * ymax;
	int h, l;
	for (int i = 1; i < n; i++)
	{
		if (x[i] == xmax)
			continue;
		l = xmax - x[i];
		h = y[i + 1] - y[i];
		s -= l * h;
	}
	cout << s << endl;
	return 0;
}