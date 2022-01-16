#include<iostream>
#include<algorithm>
using namespace std;

typedef long ll;
const int N = 1000000007;
ll a[55], cnt = 0;
int n;
ll ans = 1;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++,cnt++)
	{
		if (a[i] - cnt <= 0)
		{
			ans = 0;
			break;
		}
		ans = ans * (a[i] - cnt) % N;
	}
	cout << ans << endl;
	return 0;
}