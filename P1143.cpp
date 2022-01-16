#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<char, int> mp = { {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},
								{'8',8},{'9',9},{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15} };
const char pm[17] = "0123456789ABCDEF";
int n, m;
string s;
int num;
void f(int x)
{
	if (x == 0)return;
	f(x / m);
	cout << pm[x % m];
}
int main()
{
	cin >> n >> s >> m;
	for (int i = 0; i < s.length(); i++)
	{
		num = num * n + mp[s[i]];
	}
	f(num);
	return 0;
}