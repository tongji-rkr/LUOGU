#include<iostream>
#include<cstdio>
using namespace std;

#define NUMSIZE 10
const string number_print[NUMSIZE][5] = {
	{" - ","| |","   ","| |"," - "},
	{"   ","  |","   ","  |","   "},
	{" - ","  |"," - ","|  "," - "},
	{" - ","  |"," - ","  |"," - "},
	{"   ","| |"," - ","  |","   "},//0-4
	{" - ","|  "," - ","  |"," - "},
	{" - ","|  "," - ","| |"," - "},
	{" - ","  |","   ","  |","   "},
	{" - ","| |"," - ","| |"," - "},
	{" - ","| |"," - ","  |"," - "}//5-9
};

int main()
{
	int num;
	int k;
	string s;
	cin >> k >> s;
	int len = s.length();
	for (int j = 0; j < k * 2 + 3; j++)
	{
		for (int i = 0; i < len; i++)
		{
			num = s[i] - '0';
			if (i)
				putchar(' ');
			int sm = j / (k + 1);//ษฬ
			int re = j % (k + 1) ? 1 : 0;//ำเสý
			putchar(number_print[num][2 * sm + re][0]);
			for (int d = 0; d < k; d++)
			{
					putchar(number_print[num][2 * sm + re][1]);
			}
			putchar(number_print[num][2 * sm + re][2]);
		}
		putchar('\n');
	}
	return 0;
}