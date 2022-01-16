#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

typedef long long ll;
unordered_map<ll, int> d;
ll c,a[200005],n,ans;

int main()
{
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		ans += d[a[i]];
		d[a[i] + c]++;
	}
	cout << ans << endl;
	return 0;
}