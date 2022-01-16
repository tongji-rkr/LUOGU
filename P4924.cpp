#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 501;
int str[MAX][MAX];
int tem_str[MAX * MAX];

void Rotate(int str[MAX][MAX], int x, int y, int r, int z, int len)
{
	int x0, y0, n = 0;
	memset(tem_str, 0, sizeof(tem_str));
	if (z == 0)
	{
		for (y0 = y - r; y0 <= y + r; y0++)
		{
			for (x0 = x + r; x0 >= x - r; x0--)
			{
				tem_str[n++] = str[x0 - 1][y0 - 1];
			}
		}
	}
	else
	{
		for (y0 = y + r; y0 >= y - r; y0--)
		{
			for (x0 = x - r; x0 <= x + r; x0++)
			{
				tem_str[n++] = str[x0 - 1][y0 - 1];
			}
		}
	}
	n = 0;
	for (int i = x - r; i <= x + r; i++)
	{
		for (int j = y - r; j <= y + r; j++)
		{
			str[i - 1][j - 1] = tem_str[n++];
		}
	}
	return;
}
int main()
{
	int len, times;
	int x = 0, y = 0, r = 0, z = 0, n = 1;
	cin >> len >> times;
	memset(str, 0, sizeof(str));
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			str[i][j] = n++;
		}
	}
	for (int i = 1; i <= times; i++)
	{
		cin >> x >> y >> r >> z;
		Rotate(str, x, y, r, z, len);
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << str[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}