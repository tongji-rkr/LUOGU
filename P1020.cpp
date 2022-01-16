#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int a[maxn], d1[maxn], d2[maxn], n = 1;

int main()
{
	while (cin >> a[n])n++; n--;
	int len1 = 1, len2 = 1;
	d1[1] = d2[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (d1[len1] >= a[i])d1[++len1] = a[i];
		else *upper_bound(d1 + 1, d1 + 1 + len1, a[i], greater<int>()) = a[i];
		if (d2[len2] < a[i])d2[++len2] = a[i];
		else *lower_bound(d2 + 1, d2 + 1 + len2, a[i]) = a[i];
	}
	cout << len1 << endl;
	cout << len2 << endl;
	return 0;
}