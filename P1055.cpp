#include<iostream>
using namespace std;

int main()
{
	char isbn[14], m;
	int k = 1, total = 0;
	cin >> isbn;
	for (int i = 0; i < 11; i++)
	{
		if (isbn[i] >= '0' && isbn[i] <= '9')
			total += (isbn[i] - '0') * k++;
	}
	if (total % 11 < 10)
		m = '0' + total % 11;
	else
		m = 'X';
	if (isbn[12] == m)
		cout << "Right" << endl;
	else
	{
		isbn[12] = m;
		cout << isbn << endl;
	}
	return 0;
}