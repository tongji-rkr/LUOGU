#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

vector<int> v;
int n;

int main()
{
	n = read();
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = read();
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size() << endl;
	for (int i : v)
	{
		cout << i << ' ';
	}
	return 0;
}