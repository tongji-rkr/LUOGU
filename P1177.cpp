#include<iostream>
using namespace std;

int a[100001];
int n;

void qsort(int l,int r)
{
	int i=l, j=r;
	int mid = a[(l + r) / 2];
	do 
	{
		while (a[i] < mid)i++;
		while (a[j] > mid)j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > l)qsort(l, j);
	if (i < r)qsort(i, r);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	qsort(0, n-1);
	for (int i = 0; i < n; i++)
	{
		cout<< a[i]<<' ';
	}
	return 0;
}