#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int p1, p2, p3;
	string a;
	cin >> p1 >> p2 >> p3 >> a;
	string ret;
	ret += a[0];
	int len = a.length();
	for (int i = 1; i < len - 1; i++)
	{
		if (a[i] == '-')
		{
			char c1 =a[i-1], c2 = a[i+1];
			if (c1 == '-' || c2 == '-' || c1 >= c2 || c2 - c1 > 26)
			{
				ret += '-';
			}
			else
			{
				if (p1 == 3)
				{
					int num = p2 * (c2 - c1 - 1);
					for (int i = 0; i < num; i++)
					{
						ret += '*';
					}
					continue;
				}
				if (p1 == 2 && c1 >= 'a' && c1 <= 'z')
				{
					c1 -= 32;
					c2 -= 32;
				}
				if (p3 == 1)
				{
					for (char k = c1 + 1; k < c2; k++)
					{
						for (int j = 1; j <= p2; j++)
						{
							ret += k;
						}
					}
				}
				else
				{
					for (char k = c2-1; k > c1; k--)
					{
						for (int j = 1; j <= p2; j++)
						{
							ret += k;
						}
					}
				}
			}
		}
		else
		{
			ret += a[i];
		}
	}
	ret += a[len-1];
	cout << ret << endl;
	return 0;
}