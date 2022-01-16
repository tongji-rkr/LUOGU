#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int s, v, t;
	int hour, minute;
	cin >> s >> v;
	t = (s + v - 1) / v + 10;
	if (t > 480)
	{
		hour = 24 - (t - 480 + 59) / 60;
		minute = 60 - (t % 60);
	}
	else
	{
		hour = 8 - (t + 59) / 60;
		minute = 60 - (t % 60);
	}
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << endl;
	return 0;
}