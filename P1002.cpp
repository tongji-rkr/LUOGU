#include<iostream>
#include<cstring>
using namespace std;

const int Max = 110;
const int XY[9][2] = { {0,0},{-2,-1},{-1,-2},{2,1},{1,2},{-1,2},{-2,1},{1,-2},{2,-1} };
int main()
{
	unsigned long long Board[Max][Max], Mark[Max][Max];
	unsigned long long x0, y0, xm, ym;
	memset(Mark, 0, sizeof(Mark));
	memset(Board, 0, sizeof(Board));
	cin >> x0 >> y0 >> xm >> ym;
	for (int i = 0; i < 9; i++)
	{
		if (xm + XY[i][0] >= 0 && xm + XY[i][0] <= x0 && ym + XY[i][1] >= 0 && ym + XY[i][1] <= y0)
			Mark[xm + XY[i][0]][ym + XY[i][1]] = 1l;
	}
	for (int i = 0; !Mark[i][0]&&i <= x0; i++)
	{
		Board[i][0] = 1;
	}
	for (int i = 0; !Mark[0][i] && i <= y0; i++)
	{
		Board[0][i] = 1;
	}
	for (int i = 1; i <= x0; i++)
	{
		for (int j = 1; j <= y0; j++)
		{
			if (Mark[i][j])
				Board[i][j] = 0;
			else
			{
				Board[i][j] = Board[i - 1][j] + Board[i][j - 1];
			}
		}
	}
	cout << Board[x0][y0]<<endl;
	return 0;	
}