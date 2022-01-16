#include<iostream>
#include<cmath>
#define Pi 3.141593
using namespace std;

int main()
{
	int num;
	cin >> num;
	switch (num)
	{
		case 1:cout << "I love Luogu!" << endl; break;
		case 2:cout << 6 << " " << 4 << endl; break;
		case 3:cout << 3 << endl << 12 << endl << 2 << endl; break;
		case 4:cout << 500.0 / 3 << endl; break;
		case 5:cout << 480 / 32 << endl; break;
		case 6:cout << sqrt(36 + 81) << endl; break;
		case 7:cout << 110 << endl << 90 << endl << 0 << endl; break;
		case 8:cout << 10*Pi << endl;
			cout << 25 * Pi << endl;
			cout << 4.0 / 3 * Pi * 125 << endl; break;
		case 9:cout << 22 << endl; break;
		case 10:cout << 9 << endl; break;
		case 11:cout << 100.0 / 3 << endl; break;
		case 12:cout << 'M' - 'A' + 1 <<endl<< char('A' + 17) << endl; break;
		case 13:cout << int(pow(4.0 / 3 * Pi * 1064, 1.0 / 3)) << endl; break;
		case 14:cout << 50 << endl; break;
	}
	return 0;
}