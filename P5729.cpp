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

int a[25][25][25];
int w, x, h;
int q;
int x1, y1, z1, x2, y2, z2;


int main()
{
	w = read(), x = read(), h = read();
	q = read();
	for (int i = 1; i <= w; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			for (int k = 1; k <= h; k++)
			{
				a[i][j][k] = 1;
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		x1 = read(), y1 = read(), z1 = read();
		x2 = read(), y2 = read(), z2 = read();
		for (int i = x1; i <= x2; i++)
		{
			for (int j = y1; j <= y2; j++)
			{
				for (int k = z1; k <= z2; k++)
				{
					a[i][j][k] = 0;
				}
			}
		}
	}
	int num = 0;
	for (int i = 1; i <= w; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			for (int k = 1; k <= h; k++)
			{
				num+=a[i][j][k];
			}
		}
	}
	cout << num;
	return 0;

}