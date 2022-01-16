#include<iostream>
using namespace std;

int main()
{
	int n, num[3], price[3], total[3],min;
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		cin >> num[i] >> price[i];
		total[i] = (n + num[i] - 1) / num[i] * price[i];
	}
	min = total[0];
	for (int i = 1; i < 3; i++)
	{
		if (total[i] < min)
			min = total[i];
	}
	cout << min << endl;
	return 0;
}