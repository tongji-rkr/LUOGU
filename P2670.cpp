#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int MAX = 100;
const int XY[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1} };

int Board[MAX + 3][MAX + 3];
char Mark[MAX + 3][MAX + 3];

int main()
{
	int row, col, x1, y1;
	memset(Mark, 0, sizeof(Mark));
	memset(Board, 0, sizeof(Board));
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
	{
		cin >> &Mark[i][1];
	}
	for (int i = 1; i <=row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (Mark[i][j]=='*')
				Board[i][j] = -1;
			else
			{
				for (int k = 0; k < 8; k++)
				{
					x1 = i + XY[k][0];
					y1 = j + XY[k][1];
					if (Mark[x1][y1] == '*')
						Board[i][j] += 1;
				}
			}
		}
	}
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (Board[i][j] >= 0)
				cout << Board[i][j];
			else
				cout << '*';
		}
		cout << endl;
	}
	return 0;
}