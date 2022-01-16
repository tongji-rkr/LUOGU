#include<iostream>
using namespace std;

string step[200] = {"oooo****--","ooo--***o*","ooo*o**--*",
					"o--*o**oo*","o*o*o*--o*","--o*o*o*o*"};//n=4Ê±²½Öè
int n;
string s0 = "oooo****";
string s1 = "ooo--***";

int main()
{
	cin >> n;
	for (int i = 5; i <= n; i++)
	{
		for (int j = 2 * (i - 2) - 1; j >= 0; j--)
		{
			step[j + 2] = step[j] + "o*";
		}
		step[0] = step[1] = "o";
		step[0] += s0 + '*';
		step[1] += s1 + '*';
		s0 = step[0];
		s1 = step[1];
		step[0] += "--";
		step[1] += "o*";
	}
	for (int i = 0; i < 2 * (n - 1); i++)
	{
		cout << step[i] << endl;
	}
	return 0;
}