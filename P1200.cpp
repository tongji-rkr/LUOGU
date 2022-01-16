#include<iostream>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int s1=str1[0]-'A'+1, s2=str2[0]-'A'+1;
	int len1 = str1.length(), len2 = str2.length();
	for (int i = 1; i < len1; i++)
	{
		s1 = (s1 * (str1[i] - 'A' + 1)) % 47;
	}
	for (int i = 1; i < len2; i++)
	{
		s2 = (s2 * (str2[i] - 'A' + 1)) % 47;
	}
	if (s1 == s2)
		cout << "GO" << endl;
	else
		cout << "STAY" << endl;
	return 0;
}