#include<iostream>
using namespace std;

int main()
{
	int m, t, s, num;
	cin >> m >> t >> s;
	if (t == 0)
		num = 0;
	else
	{
		num = m - (s + t - 1) / t;
		if (num < 0)
			num = 0;
	}
	cout << num << endl;
	return 0;
}