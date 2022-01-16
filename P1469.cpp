#include<iostream>
using namespace std;

int n,x;
int ans;

int main()
{
	std::ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		ans ^= x;
	}
	cout << ans;
	return 0;
}