#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

int main()
{
	int n;
	char str[50];
	cin >> n >> str;
	int len = strlen(str);
	unordered_map<char, char> CountAB;
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		CountAB[ch] = (ch - 'a' + n) % 26 + 'a';
	}
	for (int i = 0; i < len; i++)
	{
		cout << CountAB[*(str + i)];
	}
	return 0;
}
