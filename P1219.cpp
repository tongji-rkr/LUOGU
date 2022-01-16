#include<iostream>
using namespace std;

int n;
int a[100], b[100], c[100], d[100];
int total;

void queen(int i)
{
	int j;
	if (i > n)
	{
		if (total <= 2)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << a[i] << ' ';
			}
			cout << endl;
		}
		total++;
	}
	else
	{
		for (j = 1; j <= n; j++)
		{
			if (!b[j] && !c[i + j] && !d[i - j + n])
			{
				a[i] = j;
				b[j] = 1;
				c[i + j] = 1;
				d[i - j + n] = 1;
				queen(i + 1);
				b[j] = c[i + j] = d[i - j + n] = 0;
			}
		}
	}
}
int main()
{
	cin >> n;
	queen(1);
	cout << total << endl;
	return 0;
}