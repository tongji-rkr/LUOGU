#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string read()
{
	string s = "", s1;
	int n;
	char c;
	while(cin>>c)
	{
		if (c == '[')
		{
			cin >> n;
			s1 = read();
			while (n--) s += s1;//�ظ�D��X
		}
		else
		{
			if (c == ']') return s;
			else s += c;
		}
	}
}
int main()
{
	cout<<read();
	return 0;
}