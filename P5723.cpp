#include<iostream>
#include<cmath>
using namespace std;

int val;
int n;

bool judge(int x)
{
	if (x!=2&&x % 2 == 0)
		return false;
	for (int i = 3; i <= sqrt(x); i += 2)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int i = 2;
	cin >> val;
	while (1)
	{
		if (val < i)
			break;
		if (judge(i))
		{
			val -= i;
			cout << i << endl;
			n++;
		}
		i++;
	}
	cout << n << endl;
	return 0;
}