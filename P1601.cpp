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
void HighPrecisionPlus(char a[], char b[],char c[])
{
	int i = 0;
	Inverse(a);
	Inverse(b);
	for (i = 0;a[i]||b[i]; i++)
	{
		if (a[i])
			c[i] += a[i] - '0';
		if (b[i])
			c[i] += b[i] - '0';
		c[i + 1] = c[i] / 10;
		c[i] = c[i] % 10;
		c[i] += '0';
	}
	if (c[i])
		c[i] += '0';
	Inverse(c);
	return;
}
int main()
{
	char a[501] = { 0 }, b[501] = { 0 }, c[501] = { 0 };
	cin >> a >> b;
	HighPrecisionPlus(a, b, c);
	cout << c << endl;
	return 0;
}