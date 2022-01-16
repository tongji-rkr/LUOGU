#include<iostream>
using namespace std;

int main()
{
	int d[10], h;
	int tot=0;
	for (int i = 0; i < 10; i++)
	{
		cin >> d[i];
	}
	cin >> h;
	for (int i = 0; i < 10; i++)
	{
		if (h + 30 >= d[i])
			tot++;
	}
	cout << tot << endl;
	return 0;
}