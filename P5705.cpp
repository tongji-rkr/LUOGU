#include<iostream>
using namespace std;

int main()
{
	char num[6], temp;
	cin >> num;
	for (int i = 0; i < 2; i++)
	{
		temp = num[4 - i];
		num[4 - i] = num[i];
		num[i] = temp;
	}
	num[5] = '\0';
	cout << num << endl;
	return 0;
}