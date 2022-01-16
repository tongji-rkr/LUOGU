#include<iostream>
#include<cstring>
using namespace std;

void Inverse(char* str)
{
	char temp;
	int m = 0, n = strlen(str) - 1;
	for (; m < n; m++, n--)
	{
		temp = str[m];
		str[m] = str[n];
		str[n] = temp;
	}
	return;
}
void HighPrecisionMul(char a[], char b[], char c[])
{
	int str[4001] = { 0 };
	int len = strlen(a) + strlen(b) - 1, i = 0, m = 0, n = 0;
	if (a[0] == '0' || b[0] == '0')
	{
		c[0] = '0';
		return;
	}
	Inverse(a);
	Inverse(b);
	for (i = 0; i<len; i++)
	{
		for (m = 0,n=i;m<=i; m++,n--)
		{
			if (m >= int(strlen(a)) || m < 0 || n >= int(strlen(b)) || n < 0)
				continue;
			str[i] += (a[m] - '0') * (b[n] - '0');
		}
	}
	for (i = 0; i < len; i++)
	{
		str[i + 1] += str[i] / 10;
		str[i] %= 10;
		str[i] += '0';
	}
	if (str[i])
		str[i] += '0';
	for (int k = 0; str[k]; k++)
	{
		c[k] = str[k];
	}
	Inverse(c);
	return;
}
int main()
{
	char a[2001] = { 0 }, b[2001] = { 0 }, c[4001] = { 0 };
	cin >> a >> b;
	HighPrecisionMul(a, b, c);
	cout << c << endl;
	return 0;
}