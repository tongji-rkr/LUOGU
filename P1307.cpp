#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;

long long s;
int main()
{
	stringstream ss;
	string str;
	cin >> s;
	ss << s;
	str = ss.str();
	if (s < 0)
		reverse(str.begin() + 1, str.end());
	else
		reverse(str.begin(), str.end());
	ss.str("");
	ss << str;
	ss >> s;
	cout << s << endl;
	return 0;
}