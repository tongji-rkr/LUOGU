#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n, k;
	double Anum = 0, Bnum = 0, Asum = 0, Bsum = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		if (i % k == 0)
		{
			Anum++;
			Asum += i;
		}
		else
		{
			Bnum++;
			Bsum += i;
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(1) << Asum / Anum << " " << Bsum / Bnum << endl;
	return 0;
}