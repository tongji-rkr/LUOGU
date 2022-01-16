#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;

long long x[50] = {1,1};
int n;

int main()
{
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		x[i] = x[i - 1] + x[i - 2];
	}
	cout << x[n - 1] << ".00" << endl;
	return 0;
}