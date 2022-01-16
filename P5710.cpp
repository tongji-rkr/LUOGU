#include<iostream>
using namespace std;

int main()
{
	int num;
	int s[4] = { 0 };
	cin >> num;
	bool a = (num % 2 == 0), b = (num > 4 && num <= 12);
	if (a == true && b == true)
		s[0] = 1;
	if (a == true || b == true)
		s[1] = 1;
	if ((a == true && b == false) || (a == false && b == true))
		s[2] = 1;
	if (a == false && b == false)
		s[3] = 1;
	for (int i = 0; i < 4; i++)
	{
		cout << s[i] << " ";
	}
	return 0;
}