#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> s1, s2;
	int n,len=1,i;
	cin >> n;
	for (int i = 1; i <= n;i++)
	{
		len *= 2;
	}
	s1.resize(len);
	s2.resize(len);
	for (i = 0; i < len-1; i++)
	{
		s1[i] = 0;
		cout << 0 << ' ';
	}
	s1[i] = 1;
	cout << 1 << endl;
	for (int j = 1; j < len;j++)
	{
		for (i = 0; i < len - 1; i++)
		{
			s2[i] = (s1[i] + s1[i + 1]) % 2;
			cout << s2[i] << ' ';
		}
		s2[i] = 1;
		cout << 1 << endl;
		s1 = s2;
	}
	return 0;
}