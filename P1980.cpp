#include<iostream>
#include<sstream>
using namespace std;

int n;
int x;
string s;

int main()
{
	int num = 0;
	cin >> n >> x;
	char c = '0' + x;
	for (int i = 1; i <= n; i++)
	{
		stringstream ss;
		ss << i;
		s += ss.str();
	}
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == c)
			num++;
	}
	cout << num;
	return 0;
}