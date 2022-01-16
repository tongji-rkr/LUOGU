#include<iostream>
using namespace std;

int a[10010], ans[1000010];
int num[1000010];
int m;
int n;

int check(int x)
{
	if (ans[x])return ans[x];
	int y = x, sum = 0;
	while (y <= m)
	{
		sum += num[y];
		y += x;
	}
	ans[x] = sum;
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		num[a[i]]++;
		if (m < a[i])m = a[i];
	}
	int top = m;
	for (int i = 1; i <= n; i++)
	{
		while (top > 1 && check(top) < i)top--;
		cout << top << endl;
	}
	return 0;
}