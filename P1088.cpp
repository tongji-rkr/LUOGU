#include<iostream>
#include<algorithm>
using namespace std;

int ord[10005];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)	cin >> ord[i];
	for (int i = 1; i <= m; ++i)	next_permutation(ord + 1, ord + 1 + n);
	for (int i = 1; i < n; ++i)	cout << ord[i] << ' ';
	cout << ord[n];
}