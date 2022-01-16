#include<iostream>
using namespace std;

#define NUMSIZE 10
#define PRINTSIZE 5
const string number_print[NUMSIZE][PRINTSIZE] = {
	{"XXX","X.X","X.X","X.X","XXX"},
	{"..X","..X","..X","..X","..X"},
	{"XXX","..X","XXX","X..","XXX"},
	{"XXX","..X","XXX","..X","XXX"},
	{"X.X","X.X","XXX","..X","..X"},
	{"XXX","X..","XXX","..X","XXX"},
	{"XXX","X..","XXX","X.X","XXX"},
	{"XXX","..X","..X","..X","..X"},
	{"XXX","X.X","XXX","X.X","XXX"},
	{"XXX","X.X","XXX","..X","XXX"}
};

int main()
{
	string s;
	int len;
	cin >> len;
	cin >> s;
	for (int i = 0; i < 5; i++)
	{
		for (int j=0;j<len;j++)
		{
			cout <<number_print[s[j]-'0'][i];
			if (j != len-1)
				cout << '.';
		}
		cout << endl;
	}
	return 0;
}