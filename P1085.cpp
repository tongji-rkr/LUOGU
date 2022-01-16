#include<iostream>
using namespace std;

int main()
{
	int x[7], y[7], t[7], max=0, max_num;
	for (int i = 0; i < 7; i++)
	{
		cin >> x[i] >> y[i];
		t[i] = x[i] + y[i];
	}
	for (int j = 0; j < 7; j++)
	{
		if (t[j] > max)
		{
			max = t[j];
			max_num = j + 1;
		}
	}
	cout << max_num << endl;
	return 0;
}