#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

inline int read()
{
	register int x = 0, f = 1; register char c = getchar();
	while (c < '0' || c>'9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * f;
}

int n, m;
int num[5], s[360];
int F[41][41][41][41];

int main()
{
	int x;
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		s[i] = read();
	for (int i = 1; i <= m; i++)
	{
		x = read();
		num[x]++;
	}
	F[0][0][0][0] = s[1];
	for (int a = 0; a <= num[1]; a++)
		for (int b = 0; b <= num[2]; b++)
			for (int c = 0; c <= num[3]; c++)
				for (int d = 0; d <= num[4]; d++)
				{
					int r = 1 + a + b * 2 + c * 3 + d * 4;
					if (a)F[a][b][c][d] = max(F[a][b][c][d], F[a - 1][b][c][d] + s[r]); 
					if (b)F[a][b][c][d] = max(F[a][b][c][d], F[a][b - 1][c][d] + s[r]);
					if (c)F[a][b][c][d] = max(F[a][b][c][d], F[a][b][c - 1][d] + s[r]);
					if (d)F[a][b][c][d] = max(F[a][b][c][d], F[a][b][c][d - 1] + s[r]);
				}
	cout << F[num[1]][num[2]][num[3]][num[4]];
	return 0;
}