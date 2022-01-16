#include<iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	cout << "Today, I ate " << x << " apple";
	if (x > 1)
		cout << "s";
	cout << "." << endl;
	return 0;
}