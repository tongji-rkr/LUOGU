#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
ll n, k;

bool judge()
{
	if (n >= k * 2)return false;
	int num = sqrt(k);
	for (int i = 2; i <= num; i++)
	{
		if (k % i==0)
			return false;
	}
	return true;
}
int main()
{
	cin >> n >> k;
	n++, k++;
	if (judge())
		cout << 1 << endl;
	else
		cout << 2 << endl;
	return 0;
}