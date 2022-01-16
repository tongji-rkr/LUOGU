#include<iostream>
using namespace std;

int main()
{
	int a, b;
	double money;
	cin >> a >> b;
	money = a + 0.1 * b;
	cout << int(money / 1.9) << endl;
	return 0;
}