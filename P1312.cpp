#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define LEFT -1
#define RIGHT 1

int a[5][7];
int b[5][7];
int step;
int s;
int tot;
int stx[3], sty[3], stdir[3];

void data_input()
{
	for (int i = 0; i < 5; i++)
	{
		int r = 0;
		while (1)
		{
			scanf("%d", &a[i][r]);
			if (a[i][r] == 0)
				break;
			r++;
			tot++;
		}
	}
}\
void vanish(int a[5][7])
{
	int i, j, k;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (b[i][j] == 1)
			{
				tot--;
				for (k = j+1; a[i][k]; k++)
				{
					a[i][k - 1] = a[i][k];
				}
				a[i][k - 1] = 0;
				b[i][j] = 0;
			}
		}
	}

}
int judge(int a[5][7],int x, int y)
{
	int ret=0;
	for (int i = 2; i >= 0; i--)
	{
		if (x - i < 0 || x - i + 2 >= 5)
			continue;
		if (a[x - i][y] == a[x - i + 1][y] && a[x - i + 1][y] == a[x - i + 2][y])
		{
			b[x - i][y] = b[x - i + 1][y] = b[x - i + 2][y] = 1;
			ret = 1;
		}
	}
	for (int m=0;a[x][m+2];m++)
	{
		if (a[x][m + 2] == a[x][m + 1] && a[x][m + 1] == a[x][m])
		{
			b[x][m + 2] = b[x][m + 1] = b[x][m] = 1;
			ret = 1;
		}
	}
	vanish(a);
	return ret;
}
int dia_move(int a[5][7],int x, int y, int dir)
{
	int i = 0,ret=0;
	if (a[x + dir][y])
	{
		swap(a[x][y], a[x + dir][y]);
	}
	else
	{
		for (i = 0; a[x + dir][i]; i++);
		a[x + dir][i] = a[x][y];
		for (i = y + 1; a[x][i]; i++)
		{
			a[x][i - 1] = a[x][i];
		}
		a[x][i - 1] = 0;
	}
	int loop = 1;
	while (loop)
	{
		loop = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; a[i][j]; j++)
			{
				if (judge(a,i, j) == 1)
				{
					loop = 1;
					break;
				}
			}
		}
	}
	if (tot == 0)
		return 1;
	else
		return 0;
}
int pass(int a[5][7])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; a[i][j]; j++)
		{
			s++;
			if (s > step)
			{
				break;
			}
			if (i != 0)
			{
				int a_copy[5][7];
				memcpy(a, a_copy, sizeof(a));
				if (dia_move(a_copy,i, j, LEFT) == 0)
				{
					if (pass(a_copy) == 0)
						break;
					else
					{
						s--;
						stx[s] = i;
						sty[s] = j;
						stdir[s] = LEFT;
						return 1;
					}
				}
				else
				{
					s--;
					stx[s] = i;
					sty[s] = j;
					stdir[s] = LEFT;
					return 1;
				}	
			}
			if (i != 4)
			{
				int a_copy[5][7];
				memcpy(a, a_copy, sizeof(a));
				if (dia_move(a_copy,i, j, RIGHT) == 0)
				{
					if (pass(a_copy) == 0)
						break;
					else
					{
						s--;
						stx[s] = i;
						sty[s] = j;
						stdir[s] = LEFT;
						return 1;
					}
				}
				else
				{
					s--;
					stx[s] = i;
					sty[s] = j;
					stdir[s] = LEFT;
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &step);
	data_input();
	if (pass(a) == 0)
		printf("-1\n");
	else
	{
		for (int i = 0; i < step; i++)
		{
			printf("%d %d %d\n", stx[i], sty[i], stdir[i]);
		}
	}
	return 0;
}