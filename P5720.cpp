#include<iostream>
using namespace std;

int main()
{
	int a, i;
	cin >> a;
	if (a == 1)
		i = 1;
	else
	{
		for (i = 2;; i++)
		{
			a /= 2;
			if (a == 1)
				break;
		}
	}
	cout << i << endl;
	return 0;
}