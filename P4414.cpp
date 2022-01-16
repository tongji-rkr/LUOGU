#include<iostream>
using namespace std;

int min(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}
int max(int a, int b, int c)
{
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}

int main()
{
	int a, b, c;
	int MAX, MIN, MID;
	char ord[4];
	cin >> a >> b >> c;
	MAX = max(a, b, c);
	MIN = min(a, b, c);
	MID = a + b + c - MAX - MIN;
	int k[3] = { MIN,MID,MAX };
	cin >> ord;
	for (int i = 0; i < 3; i++)
	{
		cout << k[ord[i] - 'A'] << " ";
	}
	return 0;
}