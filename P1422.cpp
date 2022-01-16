#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int k;
	double sum = 0;
	cin >> k;
	if (k <= 150)
		sum = k * 0.4463;
	else if (k > 150 && k <= 400)
			sum = 150 * 0.4463 + (k - 150) * 0.4663;
		else if (k > 400)
				sum = 150 * 0.4463 + 250 * 0.4663 + (k - 400) * 0.5663;
	cout << setiosflags(ios::fixed) << setprecision(1) << sum << endl;
	return 0;
}