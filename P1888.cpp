#include<iostream>
#include<cmath>
using namespace std;

int min(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}
int max(int a, int b, int c)
{
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}
int main()
{
	int a, b, c, Min, Max;
	cin >> a >> b >> c;
	Min = min(a, b, c);
	Max = max(a, b, c);
	for (int i = 2; i < sqrt(Min); i++)
	{
		while (1)
		{
			if (Min % i == 0 && Max % i == 0)
			{
				Min /= i;
				Max /= i;
			}
			else
				break;
		}
	}
	cout << Min << "/" << Max << endl;
	return 0;
}