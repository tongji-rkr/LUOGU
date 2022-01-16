#include<iostream>
using namespace std;

int main()
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int y, m;
	cin >> y >> m;
	month[1] += ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) == true);
	cout << month[m - 1] << endl;
	return 0;
}