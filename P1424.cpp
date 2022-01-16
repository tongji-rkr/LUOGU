#include<iostream>
using namespace std;

int main()
{
	int x, n, sum = 0;
	cin >> x >> n;
	for (int i = 0; i < n; i++)
	{
		if ((x + i) % 7 && (x + i) % 7 != 6)
			sum += 250;
	}
	cout << sum << endl;
	return 0;
}