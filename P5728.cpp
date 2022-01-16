#include<iostream>
#include<cmath>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

struct student
{
	int score1;
	int score2;
	int score3;
	int sum;
}a[1005];
int n;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i].score1 = read();
		a[i].score2 = read();
		a[i].score3 = read();
		a[i].sum = a[i].score1 + a[i].score2 + a[i].score3;
	}
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (fabs(a[i].score1 - a[j].score1) <= 5 &&
				fabs(a[i].score2 - a[j].score2) <= 5 &&
				fabs(a[i].score3 - a[j].score3) <= 5 &&
				fabs(a[i].sum - a[j].sum) <= 10)
				num++;
		}
	}
	cout << num;
	return 0;
}