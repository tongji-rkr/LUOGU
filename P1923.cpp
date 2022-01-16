#include<iostream>
#include<algorithm>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int a[5000005];
int n, q;

void qsort(int a[], int l, int r)
{
	int m = l + (r - l) / 2;
	int i = l, j = r;
	do {
		while (a[i] < a[m])i++;
		while (a[j] > a[m])j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < r)qsort(a, i, r);
	if (j > l)qsort(a, l, j);
}
int main()
{
	n = read(), q = read();
	for (int i = 0; i < n; i++)
	{
		a[i] = read();
	}
	sort(a, a + n);
	cout << a[q];
	return 0;
}