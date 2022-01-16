#include<iostream>
#include<cmath>
using namespace std;

int a[26];
int nmax=-1e9, nmin=1e9;

bool judge(int x)
{
	if (x < 2)return false;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)return false;
	}
	return true;
}
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		a[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (nmax < a[i])nmax = a[i];
		if (a[i]&&nmin > a[i])nmin = a[i];
	}
	if (judge(nmax - nmin))
	{
		cout << "Lucky Word\n" << nmax - nmin<<endl;
	}
	else
	{
		cout << "No Answer\n0" << endl;
	}
	return 0;
}